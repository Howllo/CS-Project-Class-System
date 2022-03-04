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
	CharacterList characterList;
	string UserInput = "";

	while (true) {
		cout << "Do you want to create a new Character?" << endl;
		std::getline(cin, UserInput);

		if (UserInput == "Yes" || UserInput == "yes" || UserInput == "y" || UserInput == "Y") 
		{
			Character* character = new Character();
			FullTestingProtocol(character);
			characterList.addCharacter(character);
		} 
		else {
			cout << "Cancelling creation of next character.." << endl;
			break;
		}
			
	}
}

int main(void) {
	//FullTestingProtocol();
	//ConstructorTest();
	AddCharacterTestFunction();
	return 0;
}