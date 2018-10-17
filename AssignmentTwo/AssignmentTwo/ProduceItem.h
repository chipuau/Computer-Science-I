/*
Megan Chipman
Computer Science I
Assignment Two
October 17, 2018
*/

#pragma once
#include <string>

class ProduceItem
{
	public:
		//Functions: 
		ProduceItem(std::string produce, std::string type, std::string soldBy, float price, int quantityInStock);
		~ProduceItem();

		//Variables: 
		std::string produce;
		std::string type; 
		std::string soldBy; 
		float price; 
		int quantityInStock; 
		ProduceItem* next; 
};

