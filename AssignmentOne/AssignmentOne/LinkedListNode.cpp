/*
  Megan Chipman
  COP 3502 - Computer Science I
  Assignment 1 (Re-Programmed)
  October 10, 2018
*/

#include "stdafx.h"
#include "LinkedListNode.h"

//Linked List Node Constructor: 
LinkedListNode::LinkedListNode(std::string name, int id)
{
	this->name = name;
	this->id = id; 
	this->next = NULL; 
}


LinkedListNode::~LinkedListNode()
{
}
