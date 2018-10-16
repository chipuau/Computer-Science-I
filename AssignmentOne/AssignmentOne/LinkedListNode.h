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

