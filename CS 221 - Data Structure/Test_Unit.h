#pragma once

using namespace std;

#include "Character.h"
#include "CharacterList.h"
#include "Item.h"
#include <string>

class Test_Unit {
public:
	Test_Unit();
	~Test_Unit();
	void AutoTestFillLinkedList();
private:
	Item* testRoot;
	int counting;
	string characterName[9];
	string ItemName[10];
	string ItemDesc[10];
	Character* AddCharacterStats(Character* character, char* name, int* CharTraits, int &m_Class, int &m_Alignment, int &m_HitPoints);
	void AttributeTesting(Character* newCharacter, int& TotalGrade, int& currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints);
	void TestCharacterLocation(CharacterList* characterList, int& TotalGrade, int& currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints);
	void TestLocation(CharacterList* list, int elementLocation, int& TotalGrade, int& currentGrade, int correctLocation);
	void ItemTesting(CharacterList* characterList,char* charName, int& TotalGrade, int& currentGrade);
	void DeleteItemTesting(CharacterList* characterList, char* characterName, char* name, int& TotalGrade, int& currentGrade);
	Item* CreateNewItem();
	bool isTreeBalanced(Item* root);
	int height(Item* rt);
};
