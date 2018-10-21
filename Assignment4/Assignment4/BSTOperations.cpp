/*
Megan Chipman
Computer Science I
Assignment 4 - Binary Search Trees
October 21, 2018
*/

#include "stdafx.h"
#include "BSTOperations.h"


BSTOperations::BSTOperations()
{
}


BSTOperations::~BSTOperations()
{
}

/*
 Pre-Conditions: None
 Post-Conditions: Displays a menu of operations to the user.
*/
void BSTOperations::DisplayMenu()
{
	std::cout << "Binary Search Tree Operations:" << std::endl; 
	std::cout << "==============================" << std::endl; 
	std::cout << "1. Generate Binary Search Tree" << std::endl; 
	std::cout << "2. Print Pre-Order Traversal" << std::endl;
	std::cout << "3. Print In-Order Traversal" << std::endl; 
	std::cout << "4. Print Post-Order Traversal" << std::endl; 
	std::cout << "5. Print Breadth-First Traversal" << std::endl; 
	std::cout << "6. Find Value" << std::endl; 
	std::cout << "7. Find Minimum Value" << std::endl; 
	std::cout << "8. Find Maximum Valule" << std::endl; 
	std::cout << "9. Calculate Node Average" << std::endl; 
	std::cout << "10. Find Node Median" << std::endl; 
	std::cout << "11. Calculate Node Sum" << std::endl; 
	std::cout << "12. Count Number of Nodes" << std::endl; 
	std::cout << "13. Delete Node" << std::endl; 
	std::cout << "14. Exit Program" << std::endl; 
	std::cout << std::endl;

}
