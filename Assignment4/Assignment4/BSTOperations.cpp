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

/*
 Pre-Conditions: Takes in the root of a binary search tree. 
 Post-Conditions: Generates a binary search tree using an input file and
                  returns the root of the new tree. 
*/
BSTNode* BSTOperations::GenerateBST(BSTNode * root)
{
	//Declare and Initialize Variables:
	int data = 0; 
	std::string dataString = "";

	//Open the file containing node data: 
	std::ifstream file; 
	file.open("AssignmentFourInput.txt");

	std::cout << "Generating Binary Search Tree..." << std::endl; 

	//Create new nodes using the data: 
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

/*
 Pre-Conditions: Takes in the root of a binary search tree and an integer
 Post-Conditions: Creates a new node with the integer parameter and places it
                  appropriately in the binary search tree. 
*/
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

/*
 Pre-Conditions: Takes in the root of a binary search tree 
 Post-Conditions: Prints the Pre-Order Traversal of the binary search tree
*/
void BSTOperations::PreOrder(BSTNode * root)
{
	//Check if the node is empty. If so, return:
	if (root == NULL)
	{
		return;
	}

	//Print root data, traverse left, then traverse right: 
	std::cout << root->data << " "; 
	PreOrder(root->left); 
	PreOrder(root->right); 
}

/*
Pre-Conditions: Takes in the root of a binary search tree
Post-Conditions: Prints the In-Order Traversal of the binary search tree
*/
void BSTOperations::InOrder(BSTNode * root)
{
	//Check if the root is empty. If so, return. 
	if (root == NULL)
	{
		return;
	}

	//Traverse left, print root data, then traverse right: 
	InOrder(root->left); 
	std::cout << root->data << " "; 
	InOrder(root->right); 

}

/*
Pre-Conditions: Takes in the root of a binary search tree
Post-Conditions: Prints the Post-Order Traversal of the binary search tree
*/
void BSTOperations::PostOrder(BSTNode * root)
{
	//Check if the root is empty. If so, return: 
	if (root == NULL)
	{
		return; 
	}

	//Traverse left, traverse right, then print root data: 
	PostOrder(root->left); 
	PostOrder(root->right); 
	std::cout << root->data << " "; 

}

/*
Pre-Conditions: Takes in the root of a binary search tree
Post-Conditions: Prints the Breadth First Traversal of the binary search tree
*/
void BSTOperations::BreadthFirst(BSTNode * root)
{
	//Check if the root is empty. If so, return: 
	if (root == NULL)
	{
		return; 
	}

	else
	{
		//Create a queue to store nodes by level: 
		std::queue<BSTNode*> queue;
		queue.push(root); 

		//Print the front of the queue, then add its children to the queue: 
		while (!queue.empty())
		{
			std::cout << queue.front()->data << " ";

			if (queue.front()->left != NULL)
			{
				queue.push(queue.front()->left);
			}
			
			if (queue.front()->right != NULL)
			{
				queue.push(queue.front()->right); 
			}
			
			//Pop the current node off of the queue: 
			queue.pop();
		}
	}
	
}

/*
 Pre-Conditions: Takes in the root of a binary search tree and an integer value.
 Post-Conditions: Searches for the integer value and tells user whether or not it was found. 
*/
void BSTOperations::FindValue(BSTNode * root, int value)
{
	//If the root is the node being searched for, indicate it and return: 
	if (root->data == value)
	{
		std::cout << "Node Found" << std::endl;
		std::cout << std::endl;
		return; 
	}

	//Otherwise, if the value is less than the root data, traverse left: 
	else if (root->data > value && root->left != NULL)
	{
		FindValue(root->left, value); 
	}

	//Otherwise, if the value is greater than the root data, traverse right: 
	else if (root->data < value && root->right != NULL)
	{
		FindValue(root->right, value); 
	}

	//If the node is not found, indicate it to the user: 
	else
	{
		std::cout << "Node Not Found" << std::endl; 
		std::cout << std::endl; 
	}
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the min value of the binary search tree.
*/
int BSTOperations::FindMin(BSTNode * root)
{
	if (root->left == NULL)
	{
		return root->data; 
	}

	return FindMin(root->left);
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the max value of the binary search tree.
*/
int BSTOperations::FindMax(BSTNode * root)
{
	if (root->right == NULL)
	{
		return root->data; 
	}

	return FindMax(root->right);
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the sum of the nodes in a binary search tree.
*/
int BSTOperations::FindSum(BSTNode * root)
{
	if (root == NULL)
	{
		return 0; 
	}
	
	return root->data + FindSum(root->left) + FindSum(root->right); 
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the number of nodes in a binary search tree.
*/
int BSTOperations::FindNumNodes(BSTNode * root)
{
	if (root == NULL)
	{
		return 0; 
	}

	return 1 + FindNumNodes(root->left) + FindNumNodes(root->right);
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the average of the nodes in a binary search tree.
*/
float BSTOperations::FindAverage(BSTNode * root)
{
	return FindSum(root) / FindNumNodes(root);
}

/*
Pre-Conditions: Takes in the root of a binary search tree.
Post-Conditions: Returns an integer representing the median of the nodes in a binary search tree.
*/
int BSTOperations::FindMedian(BSTNode * root)
{
	std::vector<int> nodeValues;

	//Calculate the Median Index: 
	int numNodes = FindNumNodes(root); 
	int medianIndex = numNodes / 2;

	//Gather In-Order Traversal of Tree: 
	MakeInOrder(root, nodeValues); 

	//Determine Median and Return It: 
	if (numNodes % 2 == 0)
	{
		return (nodeValues[medianIndex] + nodeValues[medianIndex + 1]) / 2; 
	}

	else
	{
		return (nodeValues[medianIndex + 1]);
	}
}

/*
Pre-Conditions: Takes in the root of a binary search tree and a vector.
Post-Conditions: Adds data to a vector In-Order. 
*/
void BSTOperations::MakeInOrder(BSTNode * root, std::vector<int>& nodeValues)
{
	if (root == NULL)
	{
		return; 
	}

	MakeInOrder(root->left, nodeValues); 
	nodeValues.push_back(root->data); 
	MakeInOrder(root->right, nodeValues); 
}

/*
 Pre-Conditions: Takes in the root of a linked list and a value to delete.
 Post-Conditions: Deletes the specified node from the binary search tree. 
*/
BSTNode* BSTOperations::Delete(BSTNode * root, int value)
{
	//If root is NULL, return it: 
	if (root == NULL)
	{
		return root; 
	}

	//Traverse left to find the value to delete: 
	if (value < root->data)
	{
		root->left = Delete(root->left, value); 
	}

	//Traverse right to find the value to delete: 
	else if (value > root->data)
	{
		root->right = Delete(root->right, value);
	}

	//Otherwise, the node has been found: 
	else
	{
		//If the root only has a right child, replace it with the right
		//and delete the right node: 
		if (root->left == NULL)
		{
			BSTNode* temp = root; 
			root = root->right; 
			delete temp;
			return root; 
		}

		//If the root only has a left child replace it with the left
		//and delete the left node: 
		else if (root->right == NULL)
		{
			BSTNode* temp = root; 
			root = root->left; 
			delete temp; 
			return root;
		}

		//Replace the root with the smallest node, then
		//readjust the tree: 
		BSTNode* temp = MinNode(root);
		root->data = temp->data; 
		root->right = Delete(root->right, temp->data); 

	}

	return root; 
}

BSTNode * BSTOperations::MinNode(BSTNode * root)
{
	if (root->left == NULL)
	{
		return root;
	}

	return MinNode(root->left);
}









