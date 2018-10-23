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

BSTNode* BSTOperations::GenerateBST(BSTNode * root)
{
	//Declare and Initialize Variables:
	int data = 0; 
	std::string dataString = "";

	//Open the file containing node data: 
	std::ifstream file; 
	file.open("AssignmentFourInput.txt");

	std::cout << "Generating Binary Search Tree..." << std::endl; 

	while (!getline(file, dataString, ',').eof())
	{
		data = std::stoi(dataString);
		root = AddNode(root, data); 
	}

	//Close File: 
	file.close();

	std::cout << "Binary Search Tree Generated" << std::endl;
	std::cout << std::endl; 

	return root; 
}

BSTNode* BSTOperations::AddNode(BSTNode * root, int data)
{ 

	//If the BST is empty, set the new node as the root: 
	if (root == NULL)
	{
		root = new BSTNode(data); 
		return root;
	}

	//If the data is less than the root data, traverse left:  
	else if (root->data > data)
	{
		root->left = AddNode(root->left, data);
	}

	//If the data is greater than the root data, traverse right: 
	else
	{
		root->right = AddNode(root->right, data); 
	}

	return root; 

}

void BSTOperations::PreOrder(BSTNode * root)
{
	if (root == NULL)
	{
		return;
	}

	std::cout << root->data << " "; 
	PreOrder(root->left); 
	PreOrder(root->right); 
}

void BSTOperations::InOrder(BSTNode * root)
{
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left); 
	std::cout << root->data << " "; 
	InOrder(root->right); 

}

void BSTOperations::PostOrder(BSTNode * root)
{
	if (root == NULL)
	{
		return; 
	}

	PostOrder(root->left); 
	PostOrder(root->right); 
	std::cout << root->data << " "; 

}
