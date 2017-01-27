#include "RegSystem.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

RegSystem::RegSystem(string n)
{
	sysName = n;
}

void RegSystem::readFile(string n) {
	ifstream inFile;
	inFile.open(n);

	while (inFile) {
		inFile >> bidDrop;
		inFile >> bid;
		inFile >> courseName;
		inFile >> fName;
		inFile >> lName;
		string name = fName + ' ' + lName;

		if (bidDrop == 'B') { 
			if (findCourse(courseName)) {
				it->addStudent(name, bid);
			}
			else {
				Course aCourse(courseName);
				aCourse.addStudent(name, bid);
				addCourse(aCourse);
			}
		}
		
		else { 
			findCourse(courseName);
			it->removeStudent(name); 
		}
	}
}

void RegSystem::addCourse(Course& aCourse) {
	bool courseAdded = false;
	if (courses.size() == 0) { 
		courses.push_back(aCourse);
		courseAdded = true;
		it = courses.begin();
	}

	else{
		for (it = courses.begin(); it < courses.end(); it++) {
			if (it->getCourseNum() > aCourse.getCourseNum()) {
				courses.insert(it, aCourse);
				courseAdded = true;
				break;
			}
		}
	}
	if (!courseAdded) { courses.push_back(aCourse); }
}

bool RegSystem::findCourse(string cN) {
	for (it = courses.begin(); it < courses.end(); it++) {
		if (it->getCourseName() == cN) {
			return true;
			break;
		}
	}
	return false;
}

void RegSystem::printRegistration() {
	for (int i = 0; i < courses.size(); i++) {
		cout << courses[i] << endl;
	}
}

