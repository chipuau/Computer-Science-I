/*
Megan Chipman
Computer Science I
Assignment Two
October 17, 2018
*/

#pragma once
class InventoryOperation
{
	public:
		//Functions: 
		InventoryOperation();
		~InventoryOperation();
		static void DisplayMenu(); 
		static ProduceItem* StockInventory(ProduceItem* head); 
		static ProduceItem* CreateProduceItem(ProduceItem* head, std::string produce, std::string type, std::string soldBy, float price, int quantityInStock); 
		static void DisplayInventory(ProduceItem* head); 
		static ProduceItem* ReverseList(ProduceItem* head); 
};

