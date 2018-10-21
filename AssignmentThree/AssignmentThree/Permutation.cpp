/*
Megan Chipman
Computer Science I
Assignment 3 - Permutations
October 20, 2018
*/


#include "stdafx.h"
#include "Permutation.h"


Permutation::Permutation()
{
}


Permutation::~Permutation()
{
}

/*
 Pre-Conditions: Takes in a string, an integer, and an output file pointer as parameters.
 Post-Conditions: Prints permutations of the given string to the specified output file.
*/
void Permutation::doPermutation(std::string word, int start, std::ofstream &outputFile)
{
	if (start == word.length())
	{
		outputFile << word << std::endl; 
	}

	else
	{
		for (int i = start; i < word.length(); i++)
		{
			word = Swap(word, start, i); 
			doPermutation(word, start+1, outputFile); 
			word = Swap(word, i, start); 
		}
	}
}

/*
 Pre-Conditions: Takes in a string and two integers as paramters
 Post-Conditions: Swaps the characters located at each integer in the given string 
                  and returns the new word
*/
std::string Permutation::Swap(std::string word, int letter1, int letter2)
{
	char temp = word[letter1]; 
	word[letter1] = word[letter2];
	word[letter2] = temp; 
	
	return word; 
}
