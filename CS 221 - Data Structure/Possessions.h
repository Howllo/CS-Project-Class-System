/****************************************
*
*	File: Possessions.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Header file for the posessions creation of binary search tree.
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
	//Root of the Tree.
	Item* m_pRoot;

public:
	Possessions();					//Constructor
	~Possessions();					//Destructor

	/** Adds a single item to the tree. */
	bool addItem(Item* newItem);
	
	/// <summary>
	/// Delete items from the tree based on the name of the item. This will be sent
	/// to the RebuildSubtree if there are childern.
	/// </summary>
	/// <param name="itemName"></param>
	/// <returns></returns>
	Item* dropItem(char* itemName);

	/// <summary>
	/// Takes in a character and return an item. If not found returns a null.
	/// </summary>
	/// <param name="char* itemName"></param>
	/// <returns></returns>
	Item* getItem(char* itemName);

	/// <summary>
	/// Only purpose is to call the printAll tree.
	/// </summary>
	void printTree();

	//This is for testing only.
	Item* GetRoot();

private:
	/// <summary>
	/// Prints all the information from the item.
	/// </summary>
	/// <param name="item"></param>
	void printOne(Item* item);
	
	/// <summary>
	/// Called by the destructor to post-order destroy the tree.
	/// </summary>
	/// <param name="root"></param>
	void destroyTree(Item* rt);

	/// <summary>
	/// PrintAll function takes in a root to be printed recursively in-order prints all
	/// nodes within the tree.
	/// </summary>
	/// <param name="root"></param>
	void printAll(Item* rt);

	/**
	* Rebuild tree function purpose is to take in a subtree or just a node
	* resursively post-order a tree until it get to a nullptr. Then it goes into
	* the node creates a copy of the node sends it to addItem function to be placed.
	* Once that is completed the original node will be deleted. 
	*/ 
	void RebuildSubtree(Item* rt);

	/// <summary>
	/// BalanceTree will rebalance the tree to be made sure that it a true binary 
	/// search tree.
	/// </summary>
	/// <param name="root"></param>
	void BalanceTree(Item* rt);

	/// <summary>
	/// Check to see whether the tree is balance or not.
	/// </summary>
	/// <param name="root"></param>
	/// <returns></returns>
	bool IsTreeBalance(Item* rt);

	/// <summary>
	/// Returns the highest different between the two.
	/// </summary>
	/// <param name="root"></param>
	/// <returns></returns>
	int GetHeight(Item* rt);
};
#endif