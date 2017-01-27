#include "Student.h"
#include "Roster.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

	Roster ads = Roster("Algorithms and Data Structures");

	ads.readStudentRecord("point.dat");

	char menuEntry = 'x';
	string id;

	ads.displayRosterMenu();
	cin >> menuEntry;
	menuEntry = toupper(menuEntry);

	while (menuEntry != 'Q') {
		if (menuEntry == 'I') {
			cout << "Please enter the Student ID." << endl;
			cin >> id;
			ads.singleStudent(id);
			cout << endl;
		}
		else {
			cout << "Here is the entire Roster:" << endl;
			ads.printRoster();
			cout << endl;
		}
		ads.displayRosterMenu();
		cin >> menuEntry;
		menuEntry = toupper(menuEntry);
	}

	return 0;
}