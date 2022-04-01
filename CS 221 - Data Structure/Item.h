/****************************************
*
*	File: Item.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Defining a structure.
*	Assignment 2: Programming Assignment 2 - Updated for Programming Assignment 3
*	Declaration: This program is entirely my own work.
*
****************************************/
#pragma once

#define BATTLE_ITEM 1
#define TREASURE_ITEM 2

struct Item
{
	char m_sItemName[64];
	char m_sDesc[127];
	int m_Itype;
	double m_dWeight;
	double m_dValue;
	Item* m_pLeft;
	Item* m_pRight;
};