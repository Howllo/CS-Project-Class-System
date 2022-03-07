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

CharacterList::CharacterList() 
{
	m_pHead = nullptr;
}

CharacterList::~CharacterList() 
{
}

//Working
bool CharacterList::addCharacter(Character* newCharacter) 
{
	Character* tempHolder = new Character();
	Character* tempHolderTwo = new Character();
	bool successfullyAdded = false;
	char* characterNamePtr = newCharacter->getName();
	char* headNamePtr = m_pHead->getName();
	char* characterTempNamePtr = nullptr;

	//Creation of linked list.
	if (m_pHead == nullptr) {
		m_pHead = newCharacter;
		return true;
	}

	tempHolder = m_pHead;
	while (tempHolder != nullptr) {
		//Set Pointer to Name
		characterTempNamePtr = tempHolder->getName();

		if (!successfullyAdded) {
			//Insert at Head
			if (characterNamePtr[0] < headNamePtr[0]) {
				tempHolderTwo = m_pHead;
				m_pHead = newCharacter;
				m_pHead->m_pNext = tempHolderTwo;
				successfullyAdded = true;
				tempHolderTwo = nullptr;
			}

			if (characterNamePtr[0] > headNamePtr[0]) {
				//Insert in Body
				if (tempHolder->m_pNext != nullptr) {
					if (characterNamePtr[0] >= characterTempNamePtr[0] && characterNamePtr[0] < tempHolder->m_pNext->getName()[0]) {
						tempHolderTwo = tempHolder->m_pNext;
						tempHolder->m_pNext = newCharacter;
						tempHolder->m_pNext->m_pNext = tempHolderTwo;
						tempHolderTwo = nullptr;
						successfullyAdded = true;
					}
				}
				//Insert at Tail
				else if (characterNamePtr[0] >= characterTempNamePtr[0] && tempHolder->m_pNext == nullptr) {
					tempHolder->m_pNext = newCharacter;
					successfullyAdded = true;
				}
			}
		}
		tempHolder = tempHolder->m_pNext;
	}
	return successfullyAdded;
}

Character* CharacterList::deleteCharacter(char* characterName) 
{
	Character* tempHolder = new Character();
	Character* tempHolderTwo = new Character();
	char firstCharArray[64];
	tempHolder = m_pHead;

	if (m_pHead == nullptr)
		return m_pHead;
	else if (m_pHead->m_pNext == nullptr) {
		tempHolder = m_pHead;
		m_pHead = nullptr;
		return tempHolder;
	}
	else if (strcmp(m_pHead->getName(), characterName) == 0) {
		tempHolder = m_pHead;
		m_pHead = m_pHead->m_pNext;
		tempHolder->m_pNext = nullptr;
		return tempHolder;
	}
	
	while (tempHolder->m_pNext != nullptr)
	{
		if (strcmp(characterName, tempHolder->getName()) == 0) {
			if (tempHolder->m_pNext != nullptr) {
				tempHolderTwo->m_pNext = tempHolder->m_pNext;
				tempHolder->m_pNext = nullptr;
				tempHolderTwo = nullptr;
				return tempHolder;
			}
			else if (tempHolder->m_pNext == nullptr) {
				tempHolderTwo->m_pNext = nullptr;
				tempHolderTwo = nullptr;
				return tempHolder;
			}
		}
		tempHolderTwo = tempHolder;
		tempHolder = tempHolder->m_pNext;
	}
	return nullptr;
}

bool CharacterList::addItem(char* characterName, Item* newItem) 
{
	Character* tempHolder;
	char* arrayPtr;
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != nullptr) {
		arrayPtr = tempHolder->getName();
		if (strcmp(characterName, arrayPtr))
		{
			return tempHolder->addItem(newItem);
		}
		tempHolder = tempHolder->m_pNext;
	}
	return false;
}

Item* CharacterList::getItem(char* characterName, char* itemName) 
{
	Character* tempHolder = new Character();
	char* arrayPtr;
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != nullptr) {
		arrayPtr = tempHolder->getName();
		if (strcmp(characterName, arrayPtr))
		{
			return tempHolder->getItem(itemName);
		}
		tempHolder = tempHolder->m_pNext;
	}
	delete tempHolder;
	return nullptr;
}

Item* CharacterList::dropItem(char* characterName, char* itemName)
{
	Character* tempHolder;
	char* arrayPtr;
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != nullptr) {
		arrayPtr = tempHolder->getName();
		if (strcmp(characterName, arrayPtr)) {
			return tempHolder->dropItem(itemName);
		}
	}
	return nullptr;
}

void CharacterList::printCharacter()
{
	Character* character;
	if (m_pHead == nullptr)
		return;

	character = m_pHead;
	while (character != nullptr) {
		character->printAll();
		character = character->m_pNext;
	}
}