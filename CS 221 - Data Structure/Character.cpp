/****************************************
*
*	File: Character.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment 1: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "Character.h"
#include "CharacterList.h"
#include "Item.h"
#include <iostream>
#include <string>

Character::Character() 
{
	for (int i = 0; i < 64; i++) {
		m_sName[i] = '\0';
	}

	for (int i = 0; i < 10; i++) {
		m_Items[i].m_dValue = 0.0;
		m_Items[i].m_dWeight = 0.0;
		m_Items[i].m_Itype = 0;
		for (int d = 0; d < 64; d++) {
			m_Items[i].m_sItemName[d] = '\0';
		}
	}

	m_iClass = 0;
	m_iAlignment = 0;
	m_iHitPoints = 0;
	m_iCharTraits[0] = 0;
	m_iCharTraits[1] = 0;
	m_iCharTraits[2] = 0;
	m_iCharTraits[3] = 0;
	m_iCharTraits[4] = 0;
	m_iCharTraits[5] = 0;
	m_pNext = nullptr;
}

Character::Character(char* name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr) 
{
	try
	{
		for (int i = 0; i < 64; i++) {
			m_sName[i] = name[i];
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error! For each statement error." << std::endl;
	}

	m_iClass = cl;
	m_iAlignment = al;
	m_iHitPoints = hp;
	m_iCharTraits[0] = str;
	m_iCharTraits[1] = dex;
	m_iCharTraits[2] = con;
	m_iCharTraits[3] = itl;
	m_iCharTraits[4] = wis;
	m_iCharTraits[5] = chr;
	m_pNext = nullptr;
}

Character::~Character()
{
}

char *Character::getName() 
{
	return m_sName;
}

void Character::setName(char* name) 
{
	try
	{
		for (int i = 0; i < 64; i++) {
			m_sName[i] = name[i];
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error! For loop set error." << std::endl;
		return;
	}
}

int Character::getClass() {
	return m_iClass;
}

void Character::setClass(int cl) {
	m_iClass = cl;
}

int Character::getAlignment() {
	return m_iAlignment;
}

void Character::setAlignment(int al) {
	m_iAlignment = al;
}

int Character::getHitPoints() {
	return m_iHitPoints;
}

void Character::setHitPoints(int hp) {
	m_iHitPoints = hp;
}

int Character::getStrength() {
	return m_iCharTraits[0];
}

void Character::setStrength(int str) {
	m_iCharTraits[0] = str;
}

int Character::getDexterity() {
	return m_iCharTraits[1];
}

void Character::setDexterity(int dex) {
	m_iCharTraits[1] = dex;
}

int Character::getConstitution() {
	return m_iCharTraits[2];
}

void Character::setConstitution(int cn) {
	m_iCharTraits[2] = cn;
}

int Character::getIntelligence() {
	return m_iCharTraits[3];
}

void Character::setIntelligence(int itl) {
	m_iCharTraits[3] = itl;
}

int Character::getWisdom() {
	return m_iCharTraits[4];
}

void Character::setWisdom(int wis) {
	m_iCharTraits[4] = wis;
}

int Character::getCharisma() {
	return m_iCharTraits[5];
}

void Character::setCharisma(int chr) {
	m_iCharTraits[5] = chr;
}

//-----------------------------------------------
// Add an item to the list of items
//-----------------------------------------------
bool Character::addItem(Item* item)
{
	// See if there is an empty place to hold this item
	for (int i = 0; i < 10; i++)
	{
		if (m_Items[i].m_sItemName[0] == '\0')	//Modified
		{
			// Found an empty slot so copy this item here
			m_Items[i] = *item;
			return true;
		}
	}
	// If we get here then the Items array is full and we
	//  can't add this item so return false to flag failure.
	return false;
}

//-----------------------------------------------
// Get a pointer to an item in the list
//-----------------------------------------------
Item* Character::getItem(char* itemName)
{
	for (int i = 0; i < 10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
			return &m_Items[i];
	}
	return NULL; // Didn't find
}

//-----------------------------------------------
// Delete an item from the list of items.  Return
// pointer to item if the item was found or NULL
// if it was not found in the list.
//-----------------------------------------------
Item* Character::dropItem(char* itemName)
{
	// Search all items
	for (int i = 0; i < 10; i++)
	{
		// If this it the correct item name
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
		{
			Item* newItem = new Item();
			*newItem = m_Items[i];
			// Set the name of the item to the "Empty" string
			strcpy_s(m_Items[i].m_sItemName, "\0");
			return newItem;
		}
	}
	return NULL;
}

void Character::printAll() {
	std::string ItemName;
	int userInput = 0;
	bool playerInventoryNameHasRan = false;

	if (m_sName == nullptr)
		return;
	//Character
	std::cout << "\tCharacter: " << std::endl;
	std::cout << "Name:\t";

	try
	{
		for (int i = 0; i < 64; i++) {
			if (m_sName[i] == '\0')
				break;
			std::cout << m_sName[i];
		}
	}
	catch (const std::exception&)
	{
		std::cout << "PrintAll -> For statement error!" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Class:\t\t" << m_iClass << std::endl;
	std::cout << "Alignment:\t" << m_iAlignment << std::endl;
	std::cout << "Hitpoints:\t" << m_iHitPoints << std::endl;

	std::cout << std::endl << "\tCharacter Traits: " << std::endl;
	std::cout << "Strength:\t" << m_iCharTraits[0] << std::endl;
	std::cout << "Dexterity:\t" << m_iCharTraits[1] << std::endl;
	std::cout << "Constituion:\t" << m_iCharTraits[2] << std::endl;
	std::cout << "Intelligence:\t" << m_iCharTraits[3] << std::endl;
	std::cout << "Wisdom:\t\t" << m_iCharTraits[4] << std::endl;
	std::cout << "Charisma:\t" << m_iCharTraits[5] << std::endl;

	//Inventory
	for (int i = 0; i < sizeof(m_Items) / sizeof(m_Items[0]); i++) {
		//Don't not print if item is null.
		if (m_Items[i].m_sItemName[0] == '\0')
			continue;

		if (!playerInventoryNameHasRan) {
			std::cout << std::endl << "Player Inventory:" << std::endl;
			playerInventoryNameHasRan = true;
		}

		std::cout << "\t Item Number: " << i+1 << std::endl;
		std::cout << "Item Name: \t";
		for (int n = 0; n < 64; n++) {
			if (m_Items[i].m_sItemName[0] == '\0')
				std::cout << "Item: " << i;

			if (m_Items[i].m_sItemName[n] == '\0')
				break;

			std::cout << m_Items[i].m_sItemName[n];
		}
		std::cout << std::endl;
		std::cout << "Item Type: \t" << m_Items[i].m_Itype << std::endl;
		std::cout << "Item Weight: \t" << m_Items[i].m_dWeight << std::endl;
		std::cout << "Item Value: \t" << m_Items[i].m_dValue << std::endl;
		std::cout << std::endl;
	}
}