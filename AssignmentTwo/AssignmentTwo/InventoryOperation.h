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
		static void ExportInventory(ProduceItem* head); 
		static void ReverseList(ProduceItem** head); 
		static void ReverseOperation(ProduceItem* current, ProduceItem* previous, ProduceItem** head);
};

