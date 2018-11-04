/*
Megan Chipman
Computer Science I
Assignment 4 - Binary Search Trees
October 21, 2018
*/

#pragma once
#include "BSTNode.h"
#include <vector>

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
		static void BreadthFirst(BSTNode * root); 
		static void FindValue(BSTNode * root, int value); 
		static int FindMin(BSTNode * root); 
		static int FindMax(BSTNode * root); 
		static int FindSum(BSTNode * root);
		static int FindNumNodes(BSTNode * root); 
		static float FindAverage(BSTNode * root); 
		static int FindMedian(BSTNode * root); 
		static void MakeInOrder(BSTNode* root, std::vector<int>& nodeValues); 
};

