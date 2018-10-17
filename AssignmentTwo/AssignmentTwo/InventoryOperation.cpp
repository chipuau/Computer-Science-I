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

/*
 Pre-Conditions: None.
 Post-Conditions: Displays a list of available operations to the user.
*/
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

ProduceItem * InventoryOperation::StockInventory(ProduceItem * head)
{
	//Declare and Intialize Variables: 
	std::string produce = "", type = "", soldBy = "", priceString = "", quantityInStockString = "";
	float price = 0.00; 
	int quantityInStock = 0; 

	//Open File: 
	std::ifstream file; 
	file.open("AssignmentTwoInput.txt"); 

	//Read Contents of File: 
	while (!getline(file, produce, ',').eof())
	{
		getline(file, type, ','); 
		getline(file, soldBy, ','); 
		getline(file, priceString, ','); 
		getline(file, quantityInStockString);

		price = std::stof(priceString);
		quantityInStock = std::stoi(quantityInStockString); 

		//Create a Node Using the Gathered Information: 
		head = CreateProduceItem(head, produce, type, soldBy, price, quantityInStock); 
	}

	return head;
}

/*
 Pre-Conditions: Takes in the head of a linked list of produce items, the name of the produce, the produce type, 
                 the sold by date, the price of the produce, and the number of produce in stock.
 Post-Conditions: Creates a new node using the input parameters, adds it to the back of the linked list, and returns
                  the head of the linked list.
*/
ProduceItem * InventoryOperation::CreateProduceItem(ProduceItem * head, std::string produce, std::string type, std::string soldBy, float price, int quantityInStock)
{
	//If the list is empty, make the new node the head of the linked list:
	if (head == NULL)
	{
		head = new ProduceItem(produce, type, soldBy, price, quantityInStock); 
	}

	//Otherwise, create a new node and place it at the back of the linked list: 
	else
	{
		ProduceItem* temp = head; 

		//Find the back of the list: 
		while (temp->next != NULL)
		{
			temp = temp->next; 
		}

		//Create and add the new node: 
		temp->next = new ProduceItem(produce, type, soldBy, price, quantityInStock); 
	}

	return head;
}
