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
#include <queue>

Possessions::Possessions() {
	m_pRoot = nullptr;
}

Possessions::~Possessions() {
	destroyTree(m_pRoot);
}

bool Possessions::addItem(Item* newItem) {
	Item* temp = m_pRoot;
	Item* back = nullptr;

	while (temp != nullptr) {
		back = temp;

		if (temp->m_sItemName != nullptr) {
			if (strcmp(newItem->m_sItemName, temp->m_sItemName) >= 0) {
				temp = temp->m_pLeft;
			}
			else {
				std::cout << "Entered else!" << std::endl;
				temp = temp->m_pRight;
			}
		}
	}
	if (back == nullptr) {
		m_pRoot = newItem;
		return true;
	}
	else if (strcmp(newItem->m_sItemName, back->m_sItemName) >= 0) {
		back->m_pLeft = newItem;

		//Check the balance of the tree.
		bool checkTree = CheckBalance(m_pRoot);
		if (!checkTree) {
			RebalanceTree(m_pRoot);
		}

		return true;
	}
	else {
		back->m_pRight = newItem;

		//Check the balance of the tree.
		bool checkTree = CheckBalance(m_pRoot);
		if (!checkTree) {
			RebalanceTree(m_pRoot);
		}

		return true;
	}

	return false;
}

Item *Possessions::dropItem(char* itemName) {
	Item* temp = m_pRoot;
	Item* back = nullptr;



	return nullptr;
}

Item *Possessions::getItem(char* itemName) {
	if (m_pRoot == nullptr) return nullptr;
	Item* temp = m_pRoot;

	while (temp != nullptr) {
		if (strcmp(itemName, temp->m_sItemName) <= 0) {
			if (strcmp(itemName, temp->m_sItemName) == 0) {
				return temp;
			}
			else {
				temp = temp->m_pLeft;
			}
		}
		else if (strcmp(itemName, temp->m_sItemName) >= 0) {
			if (strcmp(itemName, temp->m_sItemName) == 0) {
				return temp;
			}
			else {
				temp = temp->m_pRight;
			}
		}
	}
	return nullptr;
}

void Possessions::printTree() {
	printAll(m_pRoot);
}

void Possessions::printOne(Item* item){
	std::cout << "\tItem Name: " << item->m_sItemName << std::endl;
	std::cout << "Item Description:\t" << item->m_sDesc << std::endl;
	std::cout << "Item Type:\t\t" << item->m_Itype << std::endl;
	std::cout << "Item Weight\t\t" << item->m_dWeight << std::endl;
	std::cout << "Item Value:\t\t" << item->m_dValue << std::endl;
	std::cout << "\t----------------------" << std::endl << std::endl;
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

void Possessions::RebalanceTree(Item* rt) {
	return;
}

bool Possessions::CheckBalance(Item* rt) {
	if (rt == nullptr) return false;

	int CheckLeft = CheckHeight(rt->m_pLeft);
	int CheckRight = CheckHeight(rt->m_pRight);

	if (std::abs(CheckLeft - CheckRight) <= 1 && CheckBalance(rt->m_pLeft) && CheckBalance(rt->m_pRight)) {
		return true;
	}
	return false;
}

int Possessions::CheckHeight(Item* rt) {
	if (rt == nullptr) return 0;
	return 1 + std::max(CheckHeight(rt->m_pLeft), CheckHeight(rt->m_pRight));
}