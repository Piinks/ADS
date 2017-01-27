// Kate Archer
// Maze.cpp

#include "Maze.h"
#include <fstream>
#include <iostream>
using namespace std;



Maze::Maze(ifstream& inFile) // Constructor
{
	inFile >> totalRow;		// Assigns private data members
	inFile >> totalCol;
	cout << totalRow << " x " << totalCol << " Maze" << endl;
	inFile >> startRow;
	inFile >> startCol;
	cout << "Start Position:\trow " << startRow << " col " << startCol << endl;
	inFile >> endRow;
	inFile >> endCol;
	cout << "Goal Position:\trow " << endRow << " col " << endCol << endl;

	for (int i = 0; i < totalRow; i++) {	// Reads in and stores the maze.
		for (int j = 0; j < totalCol; j++) {
			inFile >> map[i][j];
		}
	}
}

void Maze::printMaze() {					// Prints maze.
	cout << endl << "Here is the maze:";
	for (int i = 0; i < totalRow; i++) {
		cout << endl;
		for (int j = 0; j < totalCol; j++) {
			if ((i == startRow) && (j == startCol))
				cout << " S";				// Marks the start position.
			else if ((i == endRow) && (j == endCol))
				cout << " G";				// Marks the end position.
			else
				cout << ' ' << map[i][j];
		}
	}
	cout << endl;
}

void Maze::printSolution() {
	if (findGoal(startRow, startCol)) {	// Prints the solution to the maze.
		cout << endl << "Here is the maze solution:";
		for (int i = 0; i < totalRow; i++) {
			cout << endl;
			for (int j = 0; j < totalCol; j++) {
				cout << ' ' << map[i][j];
			}
		}
	}
	else
		cout << "A solution was not found for this Maze." << endl;
	cout << endl;
}

bool Maze::findGoal(int x, int y) {				// Solves the maze
	if ((x == endRow) && (y == endCol)) {		// Base case for when the end position has been reached.
		cout << endl << "A solution has been found!" << endl;
		map[x][y] = 'G';
		return true;
	}
	else if ((map[x][y] == '#') || (map[x][y] == 'o') || (map[x][y] == 'S'))
		return false;

	else if ((x == startRow) && (y == startCol))
		map[x][y] = 'S';

	else
		map[x][y] = 'o';		// Marks current position as potential path


	if (findGoal(x - 1, y))		// UP
		return true;

	else if (findGoal(x + 1, y))		// DOWN
		return true;

	else if (findGoal(x, y + 1))		// RIGHT
		return true;

	else if (findGoal(x, y - 1))		// LEFT
		return true;

	map[x][y] = '.';		// If a valid path has not been found, the position is unmarked.
	return false;
}

Maze::~Maze()
{
}
