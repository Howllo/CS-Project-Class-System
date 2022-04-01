/****************************************
*
*	File: Possessions.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 3
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "Possessions.h"

Possessions::Possessions() {
	m_pRoot = nullptr;
}

Possessions::~Possessions() {
	destroyTree(m_pRoot);
}

bool Possessions::addItem(Item* newItem) {
	Item* temp = m_pRoot;
	int newNodeKey = 0, tempKey = 0;
	char* holderArray = newItem->m_sItemName;
	std::string test;

	//Create a Key
	for (int i = 0; i < 64; i++) {
		if (isalpha(holderArray[i]) || isdigit(holderArray[i]) || isspace(holderArray[i])
			|| holderArray[i] == '.' || holderArray[i] == '\'') {
			newNodeKey += (int)holderArray[i];
		}
	}

	if (m_pRoot == nullptr) {
		m_pRoot = newItem;
		newItem->m_pLeft = nullptr;
		newItem->m_pRight = nullptr;
		return true;
	}
	
	while (temp != nullptr) {
		holderArray = temp->m_sItemName;

		//Create a Key for Temp
		for (int i = 0; i < 64; i++) {
			if (isalpha(holderArray[i]) || isdigit(holderArray[i]) || isspace(holderArray[i])
				|| holderArray[i] == '.' || holderArray[i] == '\'') {
				tempKey += (int)holderArray[i];
			}
		}

		if (newNodeKey < tempKey) {
			if (temp->m_pLeft == nullptr) {
				temp->m_pLeft = newItem;
				return true;
			}
			temp = temp->m_pLeft;
		}
		else if (newNodeKey > tempKey) {
			if (temp->m_pRight == nullptr) {
				temp->m_pRight = newItem;
				return true;
			}
			temp = temp->m_pRight;
		}
	}

	return false;
}

Item *Possessions::dropItem(char* itemName) {
	Item* temp;

	return nullptr;
}

Item *Possessions::getItem(char* itemName) {
	if (m_pRoot == nullptr)
		return nullptr;

	Item* temp = m_pRoot;
	Item* back = nullptr;
	char* holderArray = itemName;
	int key = 0;
	int tempKey = 0;

	for (int i = 0; i < 64; i++) {
		if (isalpha(holderArray[i]) || isdigit(holderArray[i]) || isspace(holderArray[i])
			|| holderArray[i] == '.' || holderArray[i] == '\'') {
			key += (int)holderArray[i];
		}
	}

	while (temp != nullptr) {
		holderArray = temp->m_sItemName;

		for (int i = 0; i < 64; i++) {
			if (isalpha(holderArray[i]) || isdigit(holderArray[i]) || isspace(holderArray[i])
				|| holderArray[i] == '.' || holderArray[i] == '\'') {
				tempKey += (int)holderArray[i];
			}
		}

		if (key <= tempKey) {
			if (key == tempKey) {
				back->m_pLeft = temp->m_pLeft;
				back->m_pRight = temp->m_pRight;
			}

			back = temp;
			temp = temp->m_pLeft;
		}
		else if (key >= tempKey) {
			if (key == tempKey) {
				back->m_pRight = temp->m_pRight;
				back->m_pLeft = temp->m_pLeft;
			}

			back = temp;
			temp = temp->m_pRight;
		}
	}
	return nullptr;
}

void Possessions::printTree() {
	printAll(m_pRoot);
}

void Possessions::printOne(Item* item){
	std::cout << "\tItem Name:" << item->m_sItemName << std::endl;
	std::cout << "Item Description:\t\t" << item->m_sDesc << std::endl;
	std::cout << "Item Type:\t\t" << item->m_Itype << std::endl;
	std::cout << "Item Weight\t\t" << item->m_dWeight << std::endl;
	std::cout << "Item Value:\t\t" << item->m_dValue << std::endl;
}

void Possessions::destroyTree(Item* rt) {
	if (rt == nullptr) return;

	printAll(rt->m_pLeft);
	printAll(rt->m_pRight);
	free(rt);
}

void Possessions::printAll(Item* rt){
	if (rt == nullptr) return;

	printAll(rt->m_pLeft);
	printOne(rt);
	printAll(rt->m_pRight);
}