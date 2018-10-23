/*
Megan Chipman
Computer Science I
Assignment 4 - Binary Search Trees
October 21, 2018
*/

#pragma once
#include "BSTNode.h"

class BSTOperations
{
	public:
		BSTOperations();
		~BSTOperations();
		static void DisplayMenu(); 
		static BSTNode* GenerateBST(BSTNode* root);
		static BSTNode* AddNode(BSTNode* root, int data); 
		static void PreOrder(BSTNode* root); 
		static void InOrder(BSTNode* root); 
		static void PostOrder(BSTNode * root); 
};

