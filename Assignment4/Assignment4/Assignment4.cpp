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
	int userChoice = 0, value = 0, minValue = 0, maxValue = 0, sum = 0, 
		numNodes = 0, median = 0;
	float average = 0.0f; 
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

			//Print Breadth First Traversal: 
			case 5: 
				std::cout << "Breadth First Traversal:" << std::endl; 
				BSTOperations::BreadthFirst(root); 
				std::cout << std::endl; 
				std::cout << std::endl; 
				break; 

			//Find Value: 
			case 6: 
				std::cout << "Enter a value to search for: "; 
				std::cin >> value; 
				std::cout << "Searching for value " << value << "..." << std::endl; 
				BSTOperations::FindValue(root, value); 
				break; 

			//Find Minimum Value: 
			case 7: 
				std::cout << "Finding Minimum Value..." << std::endl; 
				minValue = BSTOperations::FindMin(root);
				std::cout << "The Minimum Value is " << minValue << "." << std::endl;
				std::cout << std::endl; 
				break; 

			//Find Maximum Value: 
			case 8: 
				std::cout << "Finding Maximum Value..." << std::endl;
				maxValue = BSTOperations::FindMax(root);
				std::cout << "The Maximum Value is " << maxValue << "." << std::endl;
				std::cout << std::endl;
				break;
			
			//Find Node Average: 
			case 9: 
				std::cout << "Calculating Node Average..." << std::endl; 
				average = BSTOperations::FindAverage(root); 
				std::cout << "The Average of the Nodes is " << average << "." << std::endl; 
				std::cout << std::endl;
				break;
			
			//Find Node Median: 
			case 10: 
				std::cout << "Calculating Median..." << std::endl; 
				median = BSTOperations::FindMedian(root); 
				std::cout << "The Median of the Nodes is " << median << "." << std::endl; 
				std::cout << std::endl; 
				break; 

			//Find Node Sum: 
			case 11: 
				std::cout << "Calculating Node Sum..." << std::endl; 
				sum = BSTOperations::FindSum(root); 
				std::cout << "The Sum of the Nodes is " << sum << "." << std::endl; 
				std::cout << std::endl; 
				break; 

			//Find Number of Nodes: 
			case 12: 
				std::cout << "Calculating Number of Nodes..." << std::endl; 
				numNodes = BSTOperations::FindNumNodes(root); 
				std::cout << "There are " << numNodes << " in the tree." << std::endl; 
				std::cout << std::endl; 
				break; 

			//Delete a Node: 
			case 13: 
				std::cout << "Enter a value to delete: ";
				std::cin >> value;
				std::cout << "Deleting value " << value << "..." << std::endl;
				root = BSTOperations::Delete(root, value); 
				std::cout << "Node Deleted." << std::endl; 
				break; 

			//Exit: 
			case 14: 
				break; 

			default:
				std::cout << "Invalid Selection" << std::endl; 

		}
	}
	
    return 0;
}

