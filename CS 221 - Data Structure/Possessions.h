/****************************************
*
*	File: Possessions.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 3
*	Declaration: This program is entirely my own work.
*
****************************************/

#ifndef POSSESSIONS_H
#define POSSESSIONS_H

#include "Item.h"
#include <iostream>

class Possessions
{
private:
	Item* m_pRoot;
public:
	Possessions();					//Constructor
	~Possessions();					//Destructor
	bool addItem(Item* newItem);	//Add item to binary tree.
	Item* dropItem(char* itemName);	//Delete items
	Item* getItem(char* itemName);	//Return item pointer.
	void printTree();
private:
	void printOne(Item* item);		//Print a single item out of the tree.
	void destroyTree(Item* rt);		//
	void printAll(Item* rt);
};
#endif