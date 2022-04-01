/****************************************
*
*	File: CharacterList.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Defining a class that keeps track of all property of Character creation.
*	Assignment 2: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include <iostream>
#include "Character.h"
#include "Item.h"

class CharacterList
{
public:
	CharacterList();	//Default Constructor
	~CharacterList();	//Destructor

	//Functions
	bool addCharacter(Character* newCharacter);			//Add new node to linked list in sort by first character.
	Character* deleteCharacter(char* characterName);	//Remove a link from the linked list.
	bool addItem(char* characterName, Item* newItem);	//Add a new item to character node. Max allow is 10 currently.
	Item* getItem(char* characterName, char* itemName);	//Get information about item in the character node.
	Item* dropItem(char* characterName, char* itemName);//Remove a item from character node array.
	void printCharacter();
	Character* GetHead();	//This is for test purpose only. Comment this out.
private:
	Character* m_pHead;
};

#endif // !CHAR