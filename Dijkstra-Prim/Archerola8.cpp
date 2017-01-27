#include <iostream>
#include <fstream>
#include <set>
#include <stack>
using namespace std;


int main() {
	int graphMatrix[100][100];
	set<int> vertices;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			graphMatrix[i][j] = 200;
		}
	}
	int row, col, weight;
	ifstream myIn;
	myIn.open("graphdata.txt");

	while (myIn) {
		myIn >> row >> col >> weight;
		row -= 1;
		col -= 1;
		vertices.insert(row);
		vertices.insert(col);
		graphMatrix[row][col] = weight;
		graphMatrix[col][row] = weight; // This is to account for UNDIRECTED graph as per assignment.
	}

	int startVertex, endVertex, graphSize;
	graphSize = vertices.size();
	cout << "Start Vertex? ";
	cin >> startVertex;
	cout << "Target Vertex? ";
	cin >> endVertex;

	// *******************************************************
	// Finding the shortest path Weighted - Dijkstra's
	int d[graphSize];
	int s[graphSize];
	bool f[graphSize];
	int min;
	int index;

	// Initializations

	for (int i = 0; i < graphSize; i++) {
		d[i] = graphMatrix[startVertex - 1][i];
	}
	for (int j = 0; j < graphSize; j++) {
		s[j] = startVertex - 1;
	}
	for (int k = 0; k < graphSize; k++) {
		f[k] = false;
	}

	f[startVertex - 1] = true;
	d[startVertex-1] = 0;
	int nodeCount = 1;
	while (nodeCount <= graphSize) {
		min = 200;
		// Greedy Algorithm to find next shortest path.
		for (int i = 0; i < graphSize; i++) {
			if (!f[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}
		// Updates any vertices with a shorter path.
		f[index] = true;
		for (int j = 0; j < graphSize; j++) {
			if (!f[j] && d[j] > (d[index] + graphMatrix[index][j])) {
				d[j] = d[index] + graphMatrix[index][j];
				s[j] = index;
			}
		}
		nodeCount++;
	}

	// Print the path
	stack<int> path;
	int currentIndex = endVertex - 1;
	cout << "Weighted: " << endl << "path1: ";
	path.push(currentIndex);
	while (currentIndex != startVertex - 1) {
		currentIndex = s[currentIndex];
		path.push(currentIndex);
	}
	while (!path.empty()) {
		cout << (path.top() + 1) << ' ';
		path.pop();
	}
	cout << endl;
	cout << "d = " << d[endVertex - 1] << endl;


	// ***************************************************
	//Finding the shortest path Unweighted - Prim's

	// Initializations

	for (int i = 0; i < graphSize; i++) {
		if (graphMatrix[startVertex-1][i] != 200)
			d[i] = 1;
		else
			d[i] = 200;
	}
	for (int j = 0; j < graphSize; j++) {
		s[j] = startVertex - 1;
	}
	for (int k = 0; k < graphSize; k++) {
		f[k] = false;
	}
	f[startVertex - 1] = true;
	nodeCount = 0;

	// Finding the path
	while (nodeCount <= graphSize) {
		min = 200;
		for (int i = 0; i < graphSize; i++) {
			if (!f[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}
		// Updates any vertices with a shorter path.
		f[index] = true;
		for (int j = 0; j < graphSize; j++) {
			if (!f[j] && d[j] >graphMatrix[index][j]) {
				d[j] = d[index] + graphMatrix[index][j];
				s[j] = index;
			}
		}
		nodeCount++;
	}

	// Print the path
 	currentIndex = endVertex - 1;
	cout << "Unweighted: " << endl << "path2: ";
	path.push(currentIndex);
	while (currentIndex != startVertex - 1) {
		currentIndex = s[currentIndex];
		path.push(currentIndex);
	}
	while (!path.empty()) {
		cout << (path.top() + 1) << ' ';
		path.pop();
	}
	cout << endl;
	cout << "d = " << d[endVertex - 1] << endl;

	return 0;
}
