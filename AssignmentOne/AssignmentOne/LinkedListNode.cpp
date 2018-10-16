#include "stdafx.h"
#include "LinkedListNode.h"


LinkedListNode::LinkedListNode(std::string name, int id)
{
	this->name = name;
	this->id = id; 
	this->next = NULL; 
}


LinkedListNode::~LinkedListNode()
{
}
