// Kate Archer
// Permutations.cpp

#include "Permutations.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Permutations::Permutations(ifstream& inFile) {
	inFile >> word;			// Reads in the word
	length = word.size();	// assigns the length
}

void Permutations::permutate(int lockedPosition) {

	if (lockedPosition == length) {	// Base case for whn the permutation function has
		cout << word << "\t";		// reached the end of the word.
		return;
	}

	else {
		for (int i = lockedPosition; i < length; i++) {	// For ech recursive call, the fist position
			swap(lockedPosition, i);					// is locked into place after each swap, and
			permutate(lockedPosition + 1);				// the recursive call moves to the next position.
			swap(lockedPosition, i);
		}
	}
}

void Permutations::printPermutations() {
	cout << endl<< "Permutations for " << word << endl;	// Prints all the permutations by calling the function.
	permutate(0);									// Starting index is 0.
}
void Permutations::swap(int x, int y) {
	char tempChar;				// Swap function for permutations.
	tempChar = word[x];
	word[x] = word[y];
	word[y] = tempChar;
	return;
}

Permutations::~Permutations(){
}
