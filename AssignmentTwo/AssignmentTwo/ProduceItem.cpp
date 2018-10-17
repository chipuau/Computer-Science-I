/*
Megan Chipman
Computer Science I
Assignment Two
October 17, 2018
*/

#include "stdafx.h"
#include "ProduceItem.h"

//Produce Item Constructor: 
ProduceItem::ProduceItem(std::string produce, std::string type, std::string soldBy, float price, int quantityInStock)
{
	this->produce = produce; 
	this->type = type; 
	this->soldBy = soldBy; 
	this->price = price; 
	this->quantityInStock = quantityInStock; 
	this->next = NULL; 
}


ProduceItem::~ProduceItem()
{
}
