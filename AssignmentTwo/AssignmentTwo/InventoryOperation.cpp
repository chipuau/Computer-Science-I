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

	std::cout << "Stocking Inventory..." << std::endl; 

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

	file.close(); 

	std::cout << "Stock Complete." << std::endl; 
	std::cout << std::endl; 

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

/*
 Pre-Conditions: Takes in the head of a linked list as a parameter.
 Post-Conditions: Displays the contents of a linked list.
*/
void InventoryOperation::DisplayInventory(ProduceItem * head)
{
	//Check if the list is empty:
	if (head == NULL)
	{
		std::cout << "There are no items in the inventory." << std::endl; 
		std::cout << std::endl; 
	}

	else
	{
		//Declare and Initialize Variables: 
		ProduceItem* temp = head;

		std::cout << "Displaying Inventory..." << std::endl;
		std::cout << std::endl;

		std::cout << std::setw(15) << std::left << "PRODUCE" << std::setw(15) << std::left << "TYPE" <<
			std::setw(15) << std::left << "SOLD BY" << std::setw(15) << std::left << "PRICE" << std::setw(15) <<
			std::left << "QUANTITY IN STOCK" << std::endl;

		std::cout << "=============================================================================" << std::endl;

		//Traverse through the linked list, printing data as you go: 
		while (temp != NULL)
		{
			std::cout << std::setw(15) << std::left << temp->produce << std::setw(15) << std::left << temp->type <<
				std::setw(15) << std::left << temp->soldBy << std::setw(15) << std::left << temp->price << std::setw(15) <<
				std::left << temp->quantityInStock << std::endl;

			temp = temp->next;
		}

		std::cout << std::endl;
		std::cout << "Display Complete." << std::endl;
		std::cout << std::endl;
	}
}

/*
 Pre-Conditions: Takes in the head of a linked list as a parameter.
 Post-Conditions: Recursively reverses the list, and returns the head of the reversed list.
*/
void InventoryOperation::ReverseList(ProduceItem ** head)
{
	//Check to make sure that the list is not empty:
	if (*head == NULL)
	{
		std::cout << "There are no items in the inventory." << std::endl; 
		return;
	}

	//If the list is not empty, begin recursion: 
	else
	{
		std::cout << "Reversing List..." << std::endl; 
		ReverseOperation(*head, NULL, head);
	}

	std::cout << "Reverse Complete." << std::endl; 
	std::cout << std::endl; 

}

/*
 Pre-Conditions: Takes in a pointer to the current item, a pointer to the previous item, and the head of the linked list.
 Post-Conditions: Performs the recursion used to reverse the linked list.
*/
void InventoryOperation::ReverseOperation(ProduceItem * current, ProduceItem * previous, ProduceItem ** head)
{
	//Check if the current node is the last in the original list. If so, set the head of the list to the current node. 
	if (current->next == NULL)
	{
		*head = current; 
		current->next = previous; 
		return; 
	}

	//Otherwise, make the current node point to the previous node, and continue with recursion. 
	ProduceItem* next = current->next; 
	current->next = previous; 

	ReverseOperation(next, current, head); 
}

void InventoryOperation::ExportInventory(ProduceItem * head)
{
	//Declare and Initialize Variables: 
	ProduceItem* temp = head; 
	std::ofstream file("ExportedInventory.txt"); 

	std::cout << "Exporting Inventory..." << std::endl; 

	//Print Header to the Export File: 
	file << std::setw(15) << std::left << "PRODUCE" << std::setw(15) << std::left << "TYPE" <<
		std::setw(15) << std::left << "SOLD BY" << std::setw(15) << std::left << "PRICE" << std::setw(15) <<
		std::left << "QUANTITY IN STOCK" << std::endl;

	file << "=============================================================================" << std::endl;

	//Traverse through the linked list, printing data as you go: 
	while (temp != NULL)
	{
		file << std::setw(15) << std::left << temp->produce << std::setw(15) << std::left << temp->type <<
			std::setw(15) << std::left << temp->soldBy << std::setw(15) << std::left << temp->price << std::setw(15) <<
			std::left << temp->quantityInStock << std::endl;

		temp = temp->next;
	}

	//Close the output stream: 
	file.close();

	std::cout << "Export Complete." << std::endl; 
	std::cout << std::endl; 
}
