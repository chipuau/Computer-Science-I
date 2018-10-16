/*
  Megan Chipman
  COP 3502 - Computer Science I
  Assignment 1 (Re-Programmed)
  October 10, 2018
*/

#pragma once
#include <string>

class LinkedListNode
{

	public:
		LinkedListNode(std::string name, int id);
		~LinkedListNode();

		int id; 
		std::string name; 
		LinkedListNode* next; 
};

