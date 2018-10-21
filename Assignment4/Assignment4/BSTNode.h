/*
Megan Chipman
Computer Science I
Assignment 4 - Binary Search Trees
October 21, 2018
*/

#pragma once

class BSTNode
{
	public:
		//Functions: 
		BSTNode(int data);
		~BSTNode();

		//Variables: 
		int data; 
		BSTNode* left; 
		BSTNode* right; 
};

