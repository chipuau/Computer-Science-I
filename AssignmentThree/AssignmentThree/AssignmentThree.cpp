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
	std::ifstream inputFile; 
	inputFile.open("AssignmentThreeInput.txt"); 
	std::ofstream outputFile; 
	outputFile.open("AssignmentThreeOutput.txt"); 
	
	std::string word = ""; 

	//Read in Contents of the File: 
	while (!getline(inputFile, word).eof())
	{
		//INSERT PERMUTATION FUNCTION
		std::cout << word << std::endl; 
		Permutation::doPermutation(word, 0, outputFile); 
	}

	inputFile.close();
	outputFile.close(); 
	
    return 0;
}

