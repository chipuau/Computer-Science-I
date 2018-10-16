/*
  Megan Chipman
  COP 3502 - Computer Science I
  Assignment 1 (Re-Programmed)
  October 10, 2018
*/


#include "stdafx.h"


int main()
{
	//Declare and Initialize Variables: 
	int userChoice = 0, id = 0; 
	std::string fname = "", lname = "", name = "";
	LinkedListNode* head = NULL; 
	
	//Read in LinkedList from Text File: 
	head = Functions::ReadFile(head); 
	std::cout << head->name << std::endl;

	//Display Menu to User and Evaluate Response: 
	while (userChoice != 5)
	{
		Functions::Menu(); 
		std::cin >> userChoice; 

		switch (userChoice)
		{
			//Insert a New Node: 
			case 1: 
				std::cout << "Enter First Name: "; 
				std::cin >> fname;
				std::cout << "Enter Last Name: ";
				std::cin >> lname;
				std::cout << "Enter ID: "; 
				std::cin >> id; 
				std::cout << std::endl; 

				name = fname + " " + lname; 

				head = Functions::Insert(head, name, id); 
				break; 

			case 2: 
				Functions::DisplayList(head);
				break; 

			case 3: 
				std::cout << "Enter ID: ";
				std::cin >> id;

				head = Functions::Delete(head, id);
				break; 

			case 4: 
				//CAN BE ONE SEPARATE FUNCTION: 
				std::cout << "Enter First Name: ";
				std::cin >> fname;
				std::cout << "Enter Last Name: ";
				std::cin >> lname;

				name = fname + " " + lname; 
				head = Functions::Delete(head, name); 
				break; 

			case 5: 
				break; 

			default: 
				std::cout << "Invalid Selection" << std::endl; 
				break; 

		}
	}
	
    return 0;
}

