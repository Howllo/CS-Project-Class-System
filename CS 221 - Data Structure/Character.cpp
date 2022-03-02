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

using std::cout; using std::endl;
using std::string; using std::cin;

Character::Character() {
	m_pNext = NULL;

	for (int i = 0; i < 64; i++) {
		m_sName[i] = '|';
	}

	for (int i = 0; i < 10; i++) {
		m_Items->m_dValue = 0.0;
		m_Items->m_dWeight = 0.0;
		m_Items->m_Itype = 0;
		for (int i = 0; i < 64; i++) {
			m_Items->m_sItemName[i] = '|';
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
		cout << "Error! For each statement error." << endl;
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

char *Character::getName() {
	return m_sName;
}

void Character::setName(char* name) {
	try
	{
		for (int i = 0; i < 64; i++) {
			m_sName[i] = name[i];
		}
	}
	catch (const std::exception&)
	{
		cout << "Error! For loop set error." << endl;
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
		if (strcmp(m_Items[i].m_sItemName, "---") == 0)
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
			strcpy(m_Items[i].m_sItemName, "---");
			return newItem;
		}
	}
	return NULL;
}

void Character::printAll() {
	cout << "\tCharacter: " << endl;
	cout << "Name:\t";

	try
	{
		for (int i = 0; i < 64; i++) {
			if (m_sName[i] == '|')
				break;
			cout << m_sName[i];
		}
	}
	catch (const std::exception&)
	{
		cout << "Printall for statement erro!" << endl;
	}

	cout << endl;
	cout << "Class:\t\t" << m_iClass << endl;
	cout << "Alignment:\t" << m_iAlignment << endl;
	cout << "Hitpoints:\t" << m_iHitPoints << endl;

	cout << endl << "\tCharacter Traits: " << endl;
	cout << "Strength:\t" << m_iCharTraits[0] << endl;
	cout << "Dexterity:\t" << m_iCharTraits[1] << endl;
	cout << "Constituion:\t" << m_iCharTraits[2] << endl;
	cout << "Intelligence:\t" << m_iCharTraits[3] << endl;
	cout << "Wisdom:\t\t" << m_iCharTraits[4] << endl;
	cout << "Charisma:\t" << m_iCharTraits[5] << endl;
}