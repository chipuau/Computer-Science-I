/*
Megan Chipman
Computer Science I
Assignment Two
October 17, 2018
*/

#include "stdafx.h"
#include "InventoryOperation.h"


InventoryOperation::InventoryOperation()
{
}


InventoryOperation::~InventoryOperation()
{
}

void InventoryOperation::DisplayMenu()
{
	std::cout << "List of Operations:" << std::endl;
	std::cout << "===================" << std::endl; 
	std::cout << "1. Stock Produce Department" << std::endl;
	std::cout << "2. Display Produce Inventory" << std::endl; 
	std::cout << "3. Reverse Order of Produce Inventory" << std::endl; 
	std::cout << "4. Export Produce Inventory" << std::endl; 
	std::cout << "5. Exit Program" << std::endl; 
	std::cout << std::endl; 
}
