/*
Megan Chipman
Computer Science I
Assignment 3 - Permutations
October 20, 2018
*/


#pragma once
#include <string>

class Permutation
{
	public:
		Permutation();
		~Permutation();
		static void doPermutation(std::string word, int start, std::ofstream &outputFile);

	private: 
		static std::string Swap(std::string word, int letter1, int letter2); 
};

