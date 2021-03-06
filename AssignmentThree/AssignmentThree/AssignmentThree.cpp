/*
 Megan Chipman
 Computer Science I
 Assignment 3 - Permutations
 October 20, 2018
*/

#include "stdafx.h"

int main()
{
	//Open Input and Output Files: 
	std::ifstream inputFile; 
	inputFile.open("AssignmentThreeInput.txt"); 

	std::ofstream outputFile; 
	outputFile.open("AssignmentThreeOutput.txt"); 
	
	std::string word = ""; 

	//Read in Contents of the File: 
	while (!getline(inputFile, word).eof())
	{
		std::cout << "Permuting " << word << "..." << std::endl;
		std::cout << std::endl;

		outputFile << "Permutations for " << word << ":" << std::endl; 
		outputFile << "==========================" << std::endl; 

		//Perform Permutation for each Word:
		Permutation::doPermutation(word, 0, outputFile); 

		outputFile << std::endl; 
	}

	//Close Used Files: 
	inputFile.close();
	outputFile.close(); 
	
    return 0;
}

