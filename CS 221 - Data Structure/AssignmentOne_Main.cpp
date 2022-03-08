/***********************************************
*	Main Functiomn for project programming 1.
***********************************************/

#include "Character.h"
#include "CharacterList.h"
#include "Item.h"
#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string; using std::cin;

void AddCharacterTestFunction();
void AutoTestFillLinkedList();
void DeleteCharacterTestFunction(CharacterList* characterList);

//Used to create new Characters.
void FullTestingProtocol(Character* characterObject) {
	char name[64];
	string holderString = "";
	int m_Class = 0, m_Alignment = 0, m_HitPoints = 0;
	int testInt1 = 0, testInt2 = 0, CharTraits[6];

	for (int i = 0; i < 64; i++) {
		name[i] = '|';
	}

	cout << "Please enter a name that is less than 64 Characters." << endl;
	std::getline(cin, holderString);


	cout << endl << "Please enter the number. \nClass:\n1. \tWarrior\n2. \tWizard\n3.\tPriest\n4. \tRogue" << endl;
	cout << "Enter Class: ";
	cin >> m_Class;

	cout << endl << "Enter your alignment using numbers." << endl;
	cout << "1.\tLawful Good\n" <<
		"2.\tLawful Neutral\n" <<
		"3.\tLawful Evil\n" <<
		"4.\tNeutral Good\n" <<
		"5.\tTrue Neutral\n" <<
		"6.\tNeutral Evil\n" <<
		"7.\tChaotic Good\n" <<
		"8.\tChaotic Neutral\n" <<
		"9.\tChaotic Evil\n" << endl;
	cout << "Enter Alignment: ";
	cin >> m_Alignment;

	for (int i = 0; i < holderString.size(); i++) {
		if (i == 64)
			break;
		name[i] = holderString[i];
	}

	m_HitPoints = rand() % 20 + 10;
	cout << "Your hits points is: " << m_HitPoints << endl;

	cout << endl;

	cout << "Character Traits" << endl;
	cout << "Please enter number of traits you want for Strength." << endl;
	cout << "Strength Trait: ";
	cin >> CharTraits[0];

	cout << endl << "Please enter number of traits you want for Dex." << endl;
	cout << "Dex Trait: ";
	cin >> CharTraits[1];

	cout << endl << "Please enter number of traits you want for Constition." << endl;
	cout << "Constition Trait: ";
	cin >> CharTraits[2];

	cout << endl << "Please enter number of traits you want for Int." << endl;
	cout << "Int Trait: ";
	cin >> CharTraits[3];

	cout << endl << "Please enter number of traits you want for Wis." << endl;
	cout << "Wis Trait: ";
	cin >> CharTraits[4];

	cout << endl << "Please enter number of traits you want for Chr." << endl;
	cout << "Chr Trait: ";
	cin >> CharTraits[5];

	characterObject->setName(name);
	characterObject->setClass(m_Class);
	characterObject->setAlignment(m_Alignment);
	characterObject->setHitPoints(m_HitPoints);
	characterObject->setStrength(CharTraits[0]);
	characterObject->setDexterity(CharTraits[1]);
	characterObject->setConstitution(CharTraits[2]);
	characterObject->setIntelligence(CharTraits[3]);
	characterObject->setWisdom(CharTraits[4]);
	characterObject->setCharisma(CharTraits[5]);
	characterObject->printAll();
	return;
}

void NameTest(Character* characterObject) {
	char name[64];
	string holderString = "";

	for (int i = 0; i < 64; i++) {
		name[i] = '|';
	}

	cout << "Please enter a name that is less than 64 Characters." << endl;
	std::getline(cin, holderString);
	cout << endl;
	for (int i = 0; i < holderString.length(); i++) {
		if (holderString[i] == '|')
			break;
		name[i] = holderString[i];
	}
	characterObject->setName(name);
}

void ConstructorTest()
{
	char name[64] = { "Tony Hardiman" };
	int m_Class = 2, m_Alignment = 5, m_HitPoints = 12;
	int CharTraits[6] = {6, 7, 10, 5, 10, 12};
	Character* characterClas = new Character(name, m_Class, m_Alignment, m_HitPoints, CharTraits[0], CharTraits[1], CharTraits[2], CharTraits[3], CharTraits[4], CharTraits[5]);
	
	characterClas->printAll();
	delete characterClas;
	return;
}

//Used to add new Character to linked list.
void AddCharacterTestFunction() 
{
	CharacterList* characterList = new CharacterList();
	string UserInput = "";
	char char_Array[64];

	while (true) {
		cout << "Do you want to create a new Character?" << endl;
		std::getline(cin, UserInput);
		cout << endl;

		if (UserInput == "Yes" || UserInput == "yes" || UserInput == "y" || UserInput == "Y") 
		{
			Character* character = new Character();
			NameTest(character);
			bool getState = characterList->addCharacter(character);
			if (getState) {
				cout << "Is it true or false: " << "true." << endl;
			}
			else if (!getState) {
				cout << "Is it true or false: " << "false." << endl;
			}
		} 
		else {
			cout << "Cancelling creation of next character.." << endl;
			characterList->printCharacter();
			break;
		}
	}

	cout << endl << "Do you want to delete a character?" << endl;
	cin >> UserInput;
	if (UserInput == "Yes" || UserInput == "yes" || UserInput == "y" || UserInput == "Y") {
		cout << "Please enter name exactly you want to delete." << endl;
		cin >> char_Array;
		DeleteCharacterTestFunction(characterList);
	}
}

void DeleteCharacterTestFunction(CharacterList* characterList) {;
	Character* returnedCharacter;
	string characterName= "Yui Takahashi";	// "Carol Hardiman", "Aleks Hararcer", "Isabelle Hardiman", "Zed Norman"
	char charArray[64];

	for (int i = 0; i < 64; i++) {
		charArray[i] = '|';
	}

	for (int i = 0; i < characterName.size(); i++) {
		charArray[i] = characterName[i];
		cout << charArray[i];
	}
	cout << endl;

	returnedCharacter = characterList->deleteCharacter(charArray);
	if (returnedCharacter != nullptr)
		returnedCharacter->printAll();
	else
		cout << "Return Character is a null pointer" << endl;
	characterList->printCharacter();
}

//Auto Fill Test
void AutoTestFillLinkedList() {
	CharacterList* characterList = new CharacterList();
	string UserInput = "";			 //4			  5					2				1					3					6
	string characterName[6] = { "Tony Hardiman", "Yui Takahashi", "Carol Hardiman", "Aleks Hararcer", "Isabelle Hardiman", "Zed Norman" };
	int sizeOfWhat = sizeof(characterName) / sizeof(characterName[0]);

	for (int i = 0; i < sizeOfWhat; i++) {
		Character* characterObject = new Character();
		char name[64];
		string holderString = "";
		int m_Class = 0, m_Alignment = 0, m_HitPoints = 0;
		int CharTraits[6];

		for (int c = 0; c < 64; c++) {
			name[c] = '|';
		}

		holderString = characterName[i];
		for (int c = 0; c < holderString.length(); c++) {
			if (holderString[c] == '|')
				break;
			name[c] = holderString[c];
		}

		m_Class = rand() % 6;
		m_Alignment = rand() % 10;
		m_HitPoints = rand() % 21;
		for (int k = 0; k < 6; k++) {
			CharTraits[k] = rand() % 13;
		}

		characterObject->setName(name);
		characterObject->setClass(m_Class);
		characterObject->setAlignment(m_Alignment);
		characterObject->setHitPoints(m_HitPoints);
		characterObject->setStrength(CharTraits[0]);
		characterObject->setDexterity(CharTraits[1]);
		characterObject->setConstitution(CharTraits[2]);
		characterObject->setIntelligence(CharTraits[3]);
		characterObject->setWisdom(CharTraits[4]);
		characterObject->setCharisma(CharTraits[5]);

		bool getState = characterList->addCharacter(characterObject);
		if (getState) {
			cout << "Is it true or false: " << "true." << endl;
		}
		else if (!getState) {
			cout << "Is it true or false: " << "false." << endl;
		}
	}
	characterList->printCharacter();

	cout << endl << "Do you want to delete a character?" << endl;
	cin >> UserInput;
	if (UserInput == "Yes" || UserInput == "yes" || UserInput == "y" || UserInput == "Y") {
		DeleteCharacterTestFunction(characterList);
	}
}

int main(void) {
	//FullTestingProtocol();
	//ConstructorTest();
	//AddCharacterTestFunction();
	AutoTestFillLinkedList();
	return 0;
}