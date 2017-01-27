// Kate Archer
// Permutations.h

#pragma once

#ifndef PERMUTATIONS
#define PERMUTATIONS

#include <string>
#include <fstream>
using namespace std;

class Permutations
{
public:
	Permutations(ifstream& inFile);		// Constructor
	void permutate(int lockedPosition);	// Recursive permutation function.
	void printPermutations();			// Prints permutations.
	~Permutations();

private:
	string word;				// Stores the word.
	int length;					// int for length of the word.
	void swap(int x, int y);	// swap function for permutation.
};
#endif
