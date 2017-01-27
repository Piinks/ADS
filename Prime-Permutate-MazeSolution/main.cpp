// Kate Archer
// main.cpp

#include <iostream>			// cout & endl
#include <fstream>			// file input
#include <string>			// string type and methods
#include "Permutations.h"	// class for problem one, permutations
#include "PrimeTest.h"		// class for problem two, primes
#include "Maze.h"			// class for problem three, maze
using namespace std;

int main() {

	ifstream inFile;
	inFile.open("ola3data.txt");

	// PROBLEM ONE: PERMUTATIONS

	int numPerms;
	cout << "Problem One: Permutations" << endl;
	inFile >> numPerms;						// Reads in number of permutations to be done.
	for (int i = 0; i < numPerms; i++) {	// For each, creates an instance of the permutation class
		Permutations currPerm(inFile);		// and print them out after permutating.
		currPerm.printPermutations();
	}

	cout << endl;

	// PROBLEM TWO: PRIME

	int totalNums;
	cout << endl << "Problem Two: Prime Number or Not?" << endl;
	inFile >> totalNums;					// Reads in total numbers to test.
	for(int i = 0; i < totalNums; i++){		// For each, creates an instance of the prime class
		PrimeTest currNum(inFile);			// and print the result.
		currNum.printResult();
	}

	// PROBLEM THREE: MAZE SOLVE
	cout << endl << "Problem Three: Maze Solution" << endl;
	Maze aMaze(inFile);						// An instance of the maze class is created
	aMaze.printMaze();						// and the input file stream is passed so the data can
	aMaze.printSolution();					// be collected. Maze is printed, solved, and then the
											// soultion is printed.

	inFile.close();
	return 0;
}
