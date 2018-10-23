/*
 Megan Chipman
 Computer Science I
 Assignment 4 - Binary Search Trees
 October 21, 2018
*/

#include "stdafx.h"


int main()
{
	//Declare and Initialize Variables:
	int userChoice = 0; 
	BSTNode* root = NULL; 

	while (userChoice != 14)
	{
		BSTOperations::DisplayMenu();
		std::cin >> userChoice; 

		switch (userChoice)
		{
			//Generate BST: 
			case 1: 
				root = BSTOperations::GenerateBST(root);  
				break; 

			//Print Pre-Order Traversal: 
			case 2: 
				std::cout << "Pre-Order Traversal:" << std::endl; 
				BSTOperations::PreOrder(root); 
				std::cout << std::endl; 
				std::cout << std::endl; 
				break;

			//Print In-Order Traversal: 
			case 3: 
				std::cout << "In-Order Traversal:" << std::endl; 
				BSTOperations::InOrder(root); 
				std::cout << std::endl; 
				std::cout << std::endl; 
				break; 

			//Print Post-Order Traversal: 
			case 4: 
				std::cout << "Post-Order Traversal:" << std::endl; 
				BSTOperations::PostOrder(root); 
				std::cout << std::endl; 
				std::cout << std::endl; 
				break; 

			case 5: 
				std::cout << "Breadth First Traversal:" << std::endl; 
				BSTOperations::BreadthFirst(root); 
				std::cout << std::endl; 
				std::cout << std::endl; 
				break; 

			case 14: 
				break; 

			default:
				std::cout << "Invalid Selection" << std::endl; 

		}
	}
	
    return 0;
}

