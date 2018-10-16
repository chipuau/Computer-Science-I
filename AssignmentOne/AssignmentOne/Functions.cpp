#include "stdafx.h"
#include "Functions.h"


Functions::Functions()
{
}


Functions::~Functions()
{
}

LinkedListNode* Functions::ReadFile(LinkedListNode * head)
{
	//Declare and Initialize Variables: 
	std::string name = "", idString = "";
	
	//Open Appropriate File: 
	std::ifstream file; 
	file.open("AssignmentOneInput.txt"); 
	
	//Extract Data from File:
	while (!getline(file, name, ',').eof())
	{
		getline(file, idString); 
		
		int id = std::stoi(idString); 
		head = Insert(head, name, id); 
	}

	file.close();

	return head;
}

void Functions::Menu()
{
	std::cout << "List Operations" << std::endl; 
	std::cout << "===============" << std::endl; 
	std::cout << "1. Insert" << std::endl; 
	std::cout << "2. Display" << std::endl; 
	std::cout << "3. Delete by ID" << std::endl; 
	std::cout << "4. Delete by Name" << std::endl; 
	std::cout << "5. Exit" << std::endl; 
	std::cout << std::endl; 
}

LinkedListNode* Functions::Insert(LinkedListNode * head, std::string name, int id)
{
	
	//Check if Linked List is Empty: 
	if (head == NULL)
	{
		head = new LinkedListNode(name, id);
	}

	
	//Otherwise, add new node to the end of the linked list: 
	else
	{
		LinkedListNode* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new LinkedListNode(name, id);
	}

	return head;
}

void Functions::DisplayList(LinkedListNode * head)
{
	LinkedListNode* temp = head; 

	std::cout << std::endl; 

	while (temp != NULL)
	{
		std::cout << temp->name << " " << temp->id << std::endl; 
		temp = temp->next; 
	}

	std::cout << std::endl; 
}

LinkedListNode * Functions::Delete(LinkedListNode * head, int id)
{
	LinkedListNode* temp = head; 

	//Check if node is the beginning of the list: 
	if (head->id == id)
	{ 
		head = head->next; 
		free(temp); 

		return head; 
	}

	//Otherwise traverse through the linked list: 
	while (temp != NULL)
	{
		//If node is found:, delete it and return head of list:  
		if (temp->next != NULL && temp->next->id == id)
		{
			LinkedListNode* toDelete = temp->next; 
			temp->next = temp->next->next; 
			free(toDelete); 
			
			std::cout << "Deleted ID " << id << std::endl; 
			std::cout << std::endl; 

			return head; 
		}

		temp = temp->next; 
	}

	//If node is not found, display it and return head: 
	std::cout << "ID " << id << " not found" << std::endl; 
	std::cout << std::endl; 

	return head; 
}

LinkedListNode * Functions::Delete(LinkedListNode * head, std::string name)
{
	LinkedListNode* temp = head; 

	//Check if node is at the beginning of the list: 
	if (head->name == name)
	{
		head = head->next;
		free(temp); 

		std::cout << "Deleted " << name << "." << std::endl;
		std::cout << std::endl;

		return head;
	}

	//Otherwise, traverse through the linked list: 
	while (temp != NULL)
	{
		//If node is found, delete it and return the head of the list: 
		if (temp->next != NULL && temp->next->name == name)
		{
			LinkedListNode* toDelete = temp->next;
			temp->next = temp->next->next;
			free(toDelete);

			std::cout << "Deleted " << name << "." << std::endl;
			std::cout << std::endl;

			return head; 
		}

		temp = temp->next;
	}

	//If node is not found, display result to the user: 
	std::cout << "Name " << name << " not found" << std::endl;
	std::cout << std::endl;

	return head;
}
