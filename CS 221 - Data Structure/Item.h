/****************************************
*
*	File: Item.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Defining a structure.
*	Assignment 2: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

struct Item
{
	char m_sItemName[64];
	int m_Itype;
	double m_dWeight;
	double m_dValue;
};
#endif
