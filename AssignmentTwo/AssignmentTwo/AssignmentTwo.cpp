/*
  Megan Chipman
  Computer Science I
  Assignment Two
  October 17, 2018
*/

#include "stdafx.h"


int main()
{
	//Declare and Initialize Variables: 
	int userChoice = 0; 
	ProduceItem* head = NULL; 

	while (userChoice != 5)
	{
		//Display Menu to User: 
		InventoryOperation::DisplayMenu(); 

		//Get User Choice: 
		std::cin >> userChoice; 

		//Evaluate User Choice: 
		switch (userChoice)
		{
			//Stock Produce Department: 
			case 1:
				head = InventoryOperation::StockInventory(head); 
				break; 

			//Display Produce Inventory: 
			case 2: 
				InventoryOperation::DisplayInventory(head); 
				break; 
			
			//Reverse Order of Produce Inventory: 
			case 3: 
				InventoryOperation::ReverseList(&head); 
				break; 
			
			//Export Produce Inventory: 
			case 4: 
				InventoryOperation::ExportInventory(head);
				break; 

			//Exit Program: 
			case 5: 
				break; 
			
			//Invalid Selection Chosen: 
			default: 
				std::cout << "Invalid Selection." << std::endl; 
				std::cout << std::endl; 
				break; 
		}

	}

	return 0;
}

