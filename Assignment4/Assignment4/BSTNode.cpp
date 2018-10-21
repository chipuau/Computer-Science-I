/*
Megan Chipman
Computer Science I
Assignment 4 - Binary Search Trees
October 21, 2018
*/

#include "stdafx.h"
#include "BSTNode.h"

//Constructor for binary search tree node: 
BSTNode::BSTNode(int data)
{
	this->data = data; 
	this->left = NULL; 
	this->right = NULL; 
}


BSTNode::~BSTNode()
{
}
