/*
 Megan Chipman
 Computer Science I
 Assignment 3 - Permutations
 October 20, 2018
*/

#include "stdafx.h"

int main()
{
	//Open File: 
	std::ifstream file; 
	file.open("AssignmentThreeInput.txt"); 

	std::string word = ""; 

	//Read in Contents of the File: 
	while (!getline(file, word).eof())
	{
		//INSERT PERMUTATION FUNCTION
		std::cout << word << std::endl; 
	}

	file.close();

    return 0;
}

