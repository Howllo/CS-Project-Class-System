/****************************************
*
*	File: Character.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Defining a class that keeps track of all property of Character creation.
*	Assignment 1: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"
#include <string>
#include <iostream>

class Character 
{
private:
	char m_sName[64];								//Name that can only hold up to 64 characters.
	int m_iClass, m_iAlignment, m_iHitPoints;		//The player class, their alignment, and how many hitpoints they have.
	int m_iCharTraits[6];							//Array that holds all the character stats, or known as traits.
	Item m_Items[10];

public:
	//Constructors
	Character();		//Constructor
	Character(char* name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr);	//Second Constructor
	~Character();		//Destructor

	//Public Variables
	Character* m_pNext;		//Get next node.

	//String Functions
	char *getName();	//Get player name.
	void setName(char* name);	//Set player name.

	int getClass();		//Get Player class.
	void setClass(int cl);		//Set player name.

	int getAlignment();	//Get player alignment.
	void setAlignment(int al);	//Set player alignment.

	int getHitPoints();	//Get player hitpoints.
	void setHitPoints(int hp);	//Set player hitpoints.

	//Character Trait Function - Array
	int getStrength();	//Get player strength.
	void setStrength(int str);	//Set player strength.

	int getDexterity();	//Get player dexterity.
	void setDexterity(int dex);		//Set player dexterity.

	int getConstitution();	//Get player constiution.
	void setConstitution(int cn);	//Set player constitution.

	int getIntelligence(); //Get player intelligence.
	void setIntelligence(int itl);	//Set player intelligence.

	int getWisdom();	//Get player wisdom.
	void setWisdom(int wis);	//Set player widsom.

	int getCharisma();	//Get player charisma.
	void setCharisma(int chr);	//Set player charisma.

	//New Functions
	bool addItem(Item* item); //Add Items to Linked list
	Item* getItem(char* itemName);	//Get Item(s) from Linked List
	Item* dropItem(char* itemName);	//Remove Item(s) from Linked List

	//Print Function
	void printAll();	//Print all information.
};
#endif