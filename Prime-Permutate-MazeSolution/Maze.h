// Kate Archer
// Maze.h

#pragma once

#ifndef MAZE
#define MAZE

#include <fstream>
using namespace std;

class Maze
{
public:
	Maze(ifstream& inFile);			// Constructor
	void printMaze();				// Prints the original maze
	void printSolution();			// Prints the maze with the solution
	bool findGoal(int x, int y);	// Solves the maze
	~Maze();

private:
	int totalRow;	// Maze dimensions
	int totalCol;
	int startRow;	// Start position
	int startCol;
	int endRow;		// End position
	int endCol;
	char map[100][100];	// two-dimensional array to store the map of the maze.

};
#endif
