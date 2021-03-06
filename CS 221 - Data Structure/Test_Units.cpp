//Used to create new Characters.

#include "Test_Unit.h"

Test_Unit::Test_Unit(){
	//4				6				5			4			2					1					3				7				2		
	string name[9] = { "Tony Hardiman", "Yui Takahashi", "Yui Godman", "Yun God", "Carol Hardiman", "Aleks Hararcer", "Isabelle Hardiman", "Zed Norman", "Autumn Stormlord" };
	string Item_Name[10] = { "Staff", "Spellbook", "Pouch", "Mighty Pouch", "Sword", "Warhammer", "Grand Hammer of Destiny", "Moe", "Dagger",
					   "Greatsword" };
	string Item_Desc[10] = { "Staff of Characters's is a staff unlike any other.", "Spellbook of Knowledge from great Wizard",
		"Pouch that contains large sum of money", "Mighty pouch that carries even more items than originally did!", "Mighty Sword of Something", "Hammer of Destiny.", "Hammer that warps reality.",
		"Type of a food that is made from flour.", "Small weapon that is easily concealled.", "Allows for heavy attacks." };
	
	for (int i = 0; i < 10; i++) {
		ItemName[i] = Item_Name[i];
		ItemDesc[i] = Item_Desc[i];
	}
	
	for (int i = 0; i < 9; i++) {
		characterName[i] = name[i];
	}
	counting = 0;
	testRoot = nullptr;
}

Test_Unit::~Test_Unit(){}

//Auto Fill Test
void Test_Unit::AutoTestFillLinkedList() {
	CharacterList* characterList = new CharacterList();
	char name[64];
	char itemName[64];
	int m_Class = 0, m_Alignment = 0, m_HitPoints = 0;
	int CharTraits[6];
	int TotalGrade = 0, currentGrade = 0;

	//Character creation test.
	cout << "Character is being created name Tony Hardiman." << endl;

	Character* newCharacter = new Character;
	strcpy_s(name, characterName[0].c_str());
	newCharacter = AddCharacterStats(newCharacter, name, CharTraits, m_Class, m_Alignment, m_HitPoints);
	bool CharacterAdded = characterList->addCharacter(newCharacter);

	if (CharacterAdded) {
		cout << "Successfully added " << newCharacter->getName() << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else if(!CharacterAdded) {
		cout << "Failed to add " << newCharacter->getName() << endl;
		TotalGrade += 1;
	}
	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;

	//Attribute Testing
	AttributeTesting(newCharacter, TotalGrade, currentGrade, CharTraits, m_Class, m_Alignment, m_HitPoints);

	//Adding more Characters and testing.
	TestCharacterLocation(characterList, TotalGrade, currentGrade, CharTraits, m_Class, m_Alignment, m_HitPoints);
	characterList->printCharacters();

	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	//Item Testing
	cout << "Starting to add items to character... " << endl;
	strcpy_s(name, characterName[0].c_str());
	ItemTesting(characterList, name, TotalGrade, currentGrade); 
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);

	//Yui Testing Items
	strcpy_s(name, characterName[1].c_str());
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);
	ItemTesting(characterList, name, TotalGrade, currentGrade);

	testRoot = newCharacter->m_pBattleItems->GetRoot();
	CharacterAdded = isTreeBalanced(testRoot);
	if (CharacterAdded) {
		cout << "The tree is balanced" << endl;
	}
	else if (!CharacterAdded) {
		cout << "The tree is not balanced." << endl;
	}

	cout << endl << "Testing the delete function..." << endl;
	strcpy_s(itemName, "Staff");
	strcpy_s(name, characterName[0].c_str());
	DeleteItemTesting(characterList, name, itemName, TotalGrade, currentGrade);
	testRoot = newCharacter->m_pBattleItems->GetRoot();
	CharacterAdded = isTreeBalanced(testRoot);
}

Character* Test_Unit::AddCharacterStats(Character* character, char* name, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints) {
	m_Class = rand() % 6;
	m_Alignment = rand() % 10;
	m_HitPoints = rand() % 21;
	for (int k = 0; k < 6; k++) {
		CharTraits[k] = rand() % 13;
	}

	character->setName(name);
	character->setClass(m_Class);
	character->setAlignment(m_Alignment);
	character->setHitPoints(m_HitPoints);
	character->setStrength(CharTraits[0]);
	character->setDexterity(CharTraits[1]);
	character->setConstitution(CharTraits[2]);
	character->setIntelligence(CharTraits[3]);
	character->setWisdom(CharTraits[4]);
	character->setCharisma(CharTraits[5]);
	return character;
}

void Test_Unit::AttributeTesting(Character* newCharacter, int &TotalGrade, int &currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints) {
	cout << "Testing Get Function of the to get the items..." << endl;
	if (newCharacter->getClass() == m_Class) {
		cout << "\t\t GetClass function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetClass function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getAlignment() == m_Alignment) {
		cout << "\t\t GetAlignment function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetAlignment function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getHitPoints() == m_HitPoints) {
		cout << "\t\t getHitPoints function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t getHitPoints function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getStrength() == CharTraits[0]) {
		cout << "\t\t getStrength function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t getStrength function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getDexterity() == CharTraits[1]) {
		cout << "\t\t GetDex function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetDex function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getConstitution() == CharTraits[2]) {
		cout << "\t\t GetCon function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetCon function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getIntelligence() == CharTraits[3]) {
		cout << "\t\t GetIntel function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetIntel function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getWisdom() == CharTraits[4]) {
		cout << "\t\t GetWisdom function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetWisdom function did not work." << endl;
		TotalGrade += 1;
	}

	if (newCharacter->getCharisma() == CharTraits[5]) {
		cout << "\t\t GetCharisma function works correctly!" << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else {
		cout << "\t\t GetCharisma function did not work." << endl;
		TotalGrade += 1;
	}

	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;
}

void Test_Unit::TestCharacterLocation(CharacterList* characterList, int &TotalGrade, int &currentGrade, int* CharTraits, int& m_Class, int& m_Alignment, int& m_HitPoints) {
	string characterName[9] = { "Tony Hardiman", "Yui Takahashi", "Yui Godman", "Yun God", "Carol Hardiman", "Aleks Hararcer", "Isabelle Hardiman", "Zed Norman", "Autumn Stormlord" };
	char name[64];
	bool CharacterAdded = false;
	Character* root = characterList->GetHead();

	//TONY HARDIAN - 0 / After AUTUMN - 1 / AFTER ZEED - 1 / AFTER CAROL - 2 / AFTER YUI - 2

	//AUTUMN STORMLORD	- 0 
	cout << "Player Autumn Stormlord Created." << endl;
	Character* newCharacter = new Character;
	strcpy_s(name, characterName[8].c_str());
	newCharacter = AddCharacterStats(newCharacter, name, CharTraits, m_Class, m_Alignment, m_HitPoints);
	CharacterAdded = characterList->addCharacter(newCharacter);
	if (CharacterAdded) {
		TestLocation(characterList, 8, TotalGrade, currentGrade, 0);
	}
	else if (!CharacterAdded) {
		cout << "Failure to add character to linked list!" << endl;
		TotalGrade += 1;
	}
	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;

	//ZED NORMAN	- 2 / AFTER CAROL 3 - AFTER YUI - 4
	cout << "Player Zed Norman Created." << endl;
	newCharacter = new Character;
	strcpy_s(name, characterName[7].c_str());
	newCharacter = AddCharacterStats(newCharacter, name, CharTraits, m_Class, m_Alignment, m_HitPoints);
	CharacterAdded = characterList->addCharacter(newCharacter);
	if (CharacterAdded) {
		TestLocation(characterList, 7, TotalGrade, currentGrade, 2);
	}
	else if (!CharacterAdded) {
		cout << "Failure to add character to linked list!" << endl;
		TotalGrade += 1;
	}
	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;

	//CAROL HARDIMAN - 1
	cout << "Player Carol Hardiman Created." << endl;
	newCharacter = new Character;
	strcpy_s(name, characterName[4].c_str());
	newCharacter = AddCharacterStats(newCharacter, name, CharTraits, m_Class, m_Alignment, m_HitPoints);
	CharacterAdded = characterList->addCharacter(newCharacter);
	if (CharacterAdded) {
		TestLocation(characterList, 4, TotalGrade, currentGrade, 1);
	}
	else if (!CharacterAdded) {
		cout << "Failure to add character to linked list!" << endl;
		TotalGrade += 1;
	}
	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;

	//YUI TAKHASHI	- 3
	cout << "Player Yui Takahashi Created." << endl;
	newCharacter = new Character;
	strcpy_s(name, characterName[1].c_str());
	newCharacter = AddCharacterStats(newCharacter, name, CharTraits, m_Class, m_Alignment, m_HitPoints);
	CharacterAdded = characterList->addCharacter(newCharacter);
	if (CharacterAdded) {
		TestLocation(characterList, 1, TotalGrade, currentGrade, 3);
	}
	else if (!CharacterAdded) {
		cout << "Failure to add character to linked list!" << endl;
		TotalGrade += 1;
	}
	cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;
}

void Test_Unit::TestLocation(CharacterList* list, int characterElementLocation, int &TotalGrade, int &currentGrade, int correctLocation) {
	string characterName[9] = { "Tony Hardiman", "Yui Takahashi", "Yui Godman", "Yun God", "Carol Hardiman", "Aleks Hararcer", "Isabelle Hardiman", "Zed Norman", "Autumn Stormlord" };
	int counter = 0;
	bool executeOnce = false;
	Character* rt = list->GetHead();


	cout << "Head is " << rt->getName() << endl << endl;

	while (rt != nullptr) {
		int testingName = strcmp(rt->getName(), characterName[characterElementLocation].c_str());		

		if (testingName == 0 && counter == correctLocation && !executeOnce) {
			cout << "Player " << characterName[characterElementLocation] << " added to the list in the correct location." << endl;
			TotalGrade++;
			currentGrade += 1;
			executeOnce = true;
		}
		else if(!executeOnce) {
			cout << "Player " << characterName[characterElementLocation] << " added to list but not in correct location." << endl;
			TotalGrade++;
			executeOnce = true;
		}
		rt = rt->m_pNext;
		counter++;
	}
}

void Test_Unit::ItemTesting(CharacterList* characterList, char* charName, int& TotalGrade, int& currentGrade) {
	Item* testItem = new Item;
	testItem = CreateNewItem();
	bool WasAdded = characterList->addItem(charName, testItem);
	cout << charName << "." << endl;

	if (WasAdded) {
		cout << "Successfully added item to character." << endl;
		TotalGrade += 1;
		currentGrade += 1;
	}
	else if(!WasAdded) {
		cout << "Failed to added item to character." << endl;
		TotalGrade += 1;
	}

	cout << endl << "Current points " << currentGrade << " out of " << TotalGrade << endl;
}

Item* Test_Unit::CreateNewItem() {
	Item* item = new Item;

	item->m_Itype = 1;
	item->m_dValue = 20;
	item->m_dWeight = 100;
	strcpy_s(item->m_sItemName, ItemName[counting].c_str());
	strcpy_s(item->m_sDesc, ItemDesc[counting].c_str());
	
	if (counting == 9)
		counting = 0;

	cout << "Adding item " << item->m_sItemName << " to the character ";
	counting++;
	return item;
}

void Test_Unit::DeleteItemTesting(CharacterList* characterList, char* characterName, char* itemName, int& TotalGrade, int& currentGrade) {
	Item* placebo = characterList->getItem(characterName, itemName);
	Item* returnedItem = characterList->dropItem(characterName, itemName);
	Item* testItem = characterList->getItem(characterName, itemName);

	if (returnedItem != nullptr) {
		if (testItem == nullptr && returnedItem->m_pLeft == nullptr && returnedItem->m_pRight == nullptr) {
			TotalGrade++;
			currentGrade++;

			cout << "Item was successfully removed!" << endl << endl;
			cout << "Current Grade is: " << currentGrade << " out of " << TotalGrade << endl << endl;

			return;
		}
		else {
			TotalGrade++;
			cout << "Item was not removed from posessions." << endl;
			return;
		}
	}

	cout << "Item was not found." << endl;
}

bool Test_Unit::isTreeBalanced(Item* root) {
	if (root == nullptr)
		return 0;

	int leftSub;
	int rightSub;

	leftSub = height(root->m_pLeft);
	rightSub = height(root->m_pRight);

	cout << "Left side is " << leftSub << " Right side is: " << rightSub << endl;

	if (abs(leftSub - rightSub) <= 1 && isTreeBalanced(root->m_pLeft) && isTreeBalanced(root->m_pRight)) {
		return 1;
	}

	return 0;
}

int Test_Unit::height(Item* rt) {
	if (rt == nullptr)
		return 0;

	return 1 + max(height(rt->m_pLeft), height(rt->m_pRight));
}