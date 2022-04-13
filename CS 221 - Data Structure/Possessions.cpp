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

	if (m_pRoot == nullptr) {
		m_pRoot = newItem;
		return true;
	}

	while (temp != nullptr) {
		if (strcmp(newItem->m_sItemName, temp->m_sItemName) >= 0) {				//STRCMP > = LEFT < = RIGHT
			if (temp->m_pLeft == nullptr) {
				temp->m_pLeft = newItem;
				bool isBalanced = IsTreeBalance(m_pRoot);

				//Balance the tree.
				if (!isBalanced) {
					BalanceTree(m_pRoot);
				}

				return true;
			}
			temp = temp->m_pLeft;
		}
		else if (strcmp(newItem->m_sItemName, temp->m_sItemName) < 0) {
			if (temp->m_pRight == nullptr) {
				temp->m_pRight = newItem;
				bool isBalanced = IsTreeBalance(m_pRoot);

				//Balance the tree.
				if (!isBalanced) {
					BalanceTree(m_pRoot);
				}
				return true;
			}
			temp = temp->m_pRight;
		}
	}
	return false;
}

Item* Possessions::dropItem(char* itemName) {
	Item* temp = m_pRoot;
	Item* back = nullptr;
	Item* m_pTempLeft = nullptr;
	Item* m_pTempRight = nullptr;
	bool wasLeftused = false;

	while (temp != nullptr) {
		if (temp != nullptr) {
			if (strcmp(temp->m_sItemName, itemName) == 0) {
				break;
			}
		}

		back = temp;
		if (strcmp(temp->m_sItemName, itemName) > 0) {
			temp = temp->m_pLeft;
			wasLeftused = true;
		}
		else if(strcmp(temp->m_sItemName, itemName) < 0) {
			temp = temp->m_pRight;
			wasLeftused = false;
		} 
	}

	if (temp != nullptr) {
		if (back == nullptr) {
			Item* m_pHolder = temp->m_pRight->m_pLeft;
			m_pTempLeft = temp->m_pLeft;
			m_pTempRight = temp->m_pRight;
			temp->m_pRight->m_pLeft = nullptr;

			//Set Root to right subtree.
			m_pRoot = m_pTempRight;
			m_pRoot->m_pLeft = m_pTempLeft;
			RebuildSubtree(m_pHolder);

			temp->m_pLeft = nullptr;
			temp->m_pRight = nullptr;

			return temp;
		}	//One Children to node
		else if (temp->m_pLeft == nullptr) {
			if (wasLeftused) {
				back->m_pLeft = temp->m_pRight;
				return temp;
			}
			else {
				back->m_pRight = temp->m_pRight;
				return temp;
			}
		}
		else if (temp->m_pRight == nullptr) {
			if (wasLeftused) {
				back->m_pLeft = temp->m_pLeft;
				return temp;
			}
			else {
				back->m_pRight = temp->m_pLeft;
				return temp;
			}
		}	//No Children to Node
		else if (temp->m_pLeft == nullptr && temp->m_pRight == nullptr) {
			if (wasLeftused) {
				back->m_pLeft = nullptr;
				return temp;
			}
			else {
				back->m_pRight = nullptr;
				return temp;
			}
		}	//Two Children
		else {
			m_pTempLeft = temp->m_pRight->m_pLeft;
			temp->m_pRight->m_pLeft = nullptr;

			if (wasLeftused) {
				back->m_pLeft = temp->m_pRight;
			}
			else {
				back->m_pRight = temp->m_pRight;
			}

			RebuildSubtree(m_pTempLeft);
			return temp;
		}
	}

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

void Possessions::BalanceTree(Item* rt) {

	if(rt->m_pLeft == nullptr && rt->m_pRight != nullptr){
		
	}
	
}

void Possessions::RebuildSubtree(Item* rt) {
	if (rt == nullptr) return;

	RebuildSubtree(rt->m_pLeft);
	RebuildSubtree(rt->m_pRight);

	//Creating a copy of the node.
	Item* newNode = new Item;
	strcpy_s(newNode->m_sItemName, rt->m_sItemName);
	strcpy_s(newNode->m_sDesc, rt->m_sDesc);
	newNode->m_dWeight = rt->m_dWeight;
	newNode->m_dValue = rt->m_dValue;
	newNode->m_Itype = rt->m_Itype;

	//Send the node to be placed back into the tree.
	addItem(newNode);

	//Delete the original node.
	delete rt;
}

bool Possessions::IsTreeBalance(Item* rt) {
	if (rt == nullptr) return false;

	int CheckLeft = GetHeight(rt->m_pLeft);
	int CheckRight = GetHeight(rt->m_pRight);

	if (std::abs(CheckLeft - CheckRight) <= 0 && IsTreeBalance(rt->m_pLeft) && IsTreeBalance(rt->m_pRight))
		return true;

	return false;
}

int Possessions::GetHeight(Item* rt) {
	if (rt == nullptr) return 0;
	return 1 + std::max(GetHeight(rt->m_pLeft), GetHeight(rt->m_pRight));
}

Item* Possessions::GetRoot() {
	return m_pRoot;
}