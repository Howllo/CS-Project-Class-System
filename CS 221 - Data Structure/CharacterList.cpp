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
#pragma once

CharacterList::CharacterList() 
{
	m_pHead = NULL;
}

CharacterList::~CharacterList() 
{
}

bool CharacterList::addCharacter(Character* newCharacter) 
{
	Character* tempHolder;
	Character* tempHolderTwo;
	char characterName[64];
	char firstCharacterName[64];
	char secondCharacterName[64];

	strncpy_s(characterName,newCharacter->getName(), 64);
	if(m_pHead !=NULL)
		strncpy_s(firstCharacterName, m_pHead->getName(), 64);

	//Check if newly added character name is less than first character of head.
	if (m_pHead == NULL) {
		m_pHead = newCharacter;
		return true;
	}
	else if (characterName[0] < firstCharacterName[0]) {
		newCharacter->m_pNext = m_pHead;
		m_pHead = newCharacter;
		return true;
	}

	tempHolder = m_pHead;

	while (tempHolder->m_pNext != NULL) {
		strncpy_s(firstCharacterName, tempHolder->getName(),64);
		if(tempHolder->m_pNext != NULL)
			strncpy_s(secondCharacterName, tempHolder->m_pNext->getName(), 64);

		//Find a place for new node based on first character. (Each chararcter have a number).
		if (characterName[0] > firstCharacterName[0] && characterName[0] < secondCharacterName[0] 
			|| characterName[0] >= firstCharacterName[0] && secondCharacterName[0] == NULL) 
		{
			//Check to see if next is null or not.
			if (tempHolder->m_pNext != NULL)
			{
				tempHolderTwo = tempHolder->m_pNext;
				tempHolder->m_pNext = newCharacter;
				tempHolder->m_pNext->m_pNext = tempHolderTwo;
				return true;
			}
			else 
			{
				tempHolder->m_pNext = newCharacter;
				return true;
			}
		}	//If they are the same number check the second ones
		else if (characterName[0] == firstCharacterName[0] && characterName[0] < secondCharacterName[0]) 
		{
			if (characterName[1] > firstCharacterName[1] && characterName[1] < secondCharacterName[1])
			{
				tempHolderTwo = tempHolder->m_pNext;
				tempHolder->m_pNext = newCharacter;
				tempHolder->m_pNext->m_pNext = tempHolderTwo;
				return true;
			}
		}
		tempHolder = tempHolder->m_pNext;
	}
	return false;
}

Character* CharacterList::deleteCharacter(char* characterName) 
{
	Character* tempHolder;
	Character* tempHolderTwo = new Character();
	char firstCharArray[64];
	tempHolder = m_pHead;

	while (tempHolder->m_pNext != NULL) 
	{
		if (strcmp(characterName, tempHolder->getName())) {
			tempHolderTwo->m_pNext = tempHolder->m_pNext;
			tempHolder->m_pNext = NULL;
			delete tempHolderTwo;
			return tempHolder;
		}
		tempHolderTwo = tempHolder;
		tempHolder = tempHolder->m_pNext;
	}
	delete tempHolderTwo;
	return NULL;
}

bool CharacterList::addItem(char* characterName, Item* newItem) 
{
	Character* tempHolder;
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != NULL) {
		if (strcmp(characterName, tempHolder->getName()))
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
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != NULL) {
		if (strcmp(characterName, tempHolder->getName())) 
		{
			return tempHolder->getItem(itemName);
		}
		tempHolder = tempHolder->m_pNext;
	}
	delete tempHolder;
	return NULL;
}

Item* CharacterList::dropItem(char* characterName, char* itemName)
{
	Character* tempHolder;
	tempHolder = m_pHead;
	while (tempHolder->m_pNext != NULL) {
		if (strcmp(characterName, tempHolder->getName())) {
			return tempHolder->dropItem(itemName);
		}
	}
	return NULL;
}

void CharacterList::printCharacter()
{
	Character* character;
	character = m_pHead;
	
	while (character->m_pNext != NULL) {
		character->printAll();
		character = character->m_pNext;
	}
}