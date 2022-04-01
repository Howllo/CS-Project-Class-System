#pragma once

using namespace std;

#include "Character.h"
#include "CharacterList.h"
#include "Item.h"
#include <string>

class Test_Unit {
public:
	void AutoTestFillLinkedList();
private:
	Character* AddCharacterStats(Character* character, char* name, int* CharTraits, int &m_Class, int &m_Alignment, int &m_HitPoints);
	void AttributeTesting(Character* newCharacter, int& TotalGrade, int& currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints);
	void TestCharacterLocation(Character* rt, CharacterList* characterList, int& TotalGrade, int& currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints);
	void TestLocation(Character* rt, int elementLocation, int& TotalGrade, int& currentGrade, int correctLocation);
	void ItemTesting(char* charName);
};