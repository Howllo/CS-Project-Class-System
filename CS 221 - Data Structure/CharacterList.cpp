/****************************************
*
*	File: Character.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment 1: Programming Assignment 2
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

//Working
Character* CharacterList::deleteCharacter(char* characterName)
{
	Character* tempHolder = new Character();
	Character* tempHolderTwo = new Character();
	string holderStringOne = "", holderStringTwo = "";

	//All of this is too static for me to create things properly. If you are having problems getting right
	//answer just set a array to 64 and initialize it to all |. My with 64 char array and | at the end works.

	for (int i = 0; i < 64; i++) {
		if (characterName[i] == '|' || characterName[i] == '\0')
			break;
		holderStringOne += characterName[i];
	}

	if (m_pHead == nullptr) {
		cout << "Enter the null pointer head." << endl;
		return m_pHead;
	}
	
	tempHolder = m_pHead;
	while (tempHolder != nullptr)
	{
		//Removes the | to be compared due to garbage values at the end of the array. 
		//For some reason I was getting heart at the end.
		for (int i = 0; i < 64; i++) {
			if (tempHolder->getName()[i] == '|')
				break;
			holderStringTwo += tempHolder->getName()[i];
		}

		if (holderStringOne == holderStringTwo) {
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
		holderStringTwo = "";
	}
	return nullptr;
}

bool CharacterList::addItem(char* characterName, Item* newItem) 
{
	Character* tempHolder = new Character();
	char* arrayPtr;
	tempHolder = m_pHead;
	while (tempHolder != nullptr) {
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
	while (tempHolder != nullptr) {
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
	while (tempHolder != nullptr) {
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