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

void Permutation::doPermutation(std::string word, int start)
{
	if (start == word.length())
	{
		std::cout << word << std::endl; 
	}

	else
	{
		for (int i = start; i < word.length(); i++)
		{
			word = Swap(word, start, i); 
			doPermutation(word, start+1); 
			word = Swap(word, i, start); 
		}
	}
}

std::string Permutation::Swap(std::string word, int letter1, int letter2)
{
	char temp = word[letter1]; 
	word[letter1] = word[letter2];
	word[letter2] = temp; 
	
	return word; 
}
