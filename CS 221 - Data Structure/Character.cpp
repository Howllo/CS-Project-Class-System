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

Character::Character() 
{
	for (int i = 0; i < 64; i++) {
		m_sName[i] = '\0';
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
	m_pBattleItems = new Possessions;
	m_pTreasureItems = new Possessions;
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
	m_pBattleItems = nullptr;
	m_pTreasureItems = nullptr;
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
		std::cout << "Error! SetName for loop has a error." << std::endl;
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


bool Character::addItem(Item* item)
{

	return false;
}

Item* Character::getItem(char* itemName)
{

	return NULL;
}

Item* Character::dropItem(char* itemName)
{

	return NULL;
}

void Character::printAll() {
	if (m_sName == nullptr)
		return;

	//Character
	std::cout << "\tCharacter: " << std::endl;
	std::cout << "Name:\t" << m_sName;
	std::cout << std::endl;
	std::cout << "Class\t" << m_iClass;
	std::cout << "\tAlignment:\t" << m_iAlignment << std::endl;
	std::cout << "Hitpoints:\t" << m_iHitPoints << std::endl;
	std::cout << "---------------------------------";
	std::cout << std::endl << "\tCharacter Traits: " << std::endl;
	std::cout << "STR:\t" << m_iCharTraits[0];
	std::cout << "\tDEX:\t" << m_iCharTraits[1] << std::endl;
	std::cout << "CON:\t" << m_iCharTraits[2];
	std::cout << "\tINT:\t" << m_iCharTraits[3] << std::endl;
	std::cout << "WIS:\t" << m_iCharTraits[4];
	std::cout << "\tCHR:\t" << m_iCharTraits[5] << std::endl;
	std::cout << "---------------------------------" << std::endl;
}