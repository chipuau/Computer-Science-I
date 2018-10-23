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

			case 14: 
				break; 

			default:
				std::cout << "Invalid Selection" << std::endl; 

		}
	}
	
    return 0;
}

