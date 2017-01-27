#include "Course.h"
#include <string>
#include <iostream>
using namespace std;


Course::Course(string n)
{
	courseName = n;
}

void Course::addStudent(string n, int b) {
	Student s;
	s.name = n;
	s.bid = b;
	if (students.size() == 0) {
		students.push_back(s);
		iter = students.begin();
	}
	else {
		for (iter = students.begin(); (iter < students.end()) && (s.bid < iter->bid); iter++) {}
		students.insert(iter, s);
	}
}

void Course::removeStudent(string n) {
	for (iter = students.begin(); iter < students.end(); iter++) {
		if (n == iter->name) { 
			students.erase(iter);
			break;
		}
	}
}

string Course::getCourseName() {
	return courseName;
}

int Course::getCourseNum() {
	return stoi(courseName.substr(2, 10));
}

ostream& operator<<(ostream& os, const Course& rhs) {
	int capacity;
	os << "What is the capacity for " << rhs.courseName << '?' << endl;
	cin >> capacity;
	os << "Student list registered for " << rhs.courseName << ':' << endl << endl;

	if (capacity > rhs.students.size()) { capacity = rhs.students.size(); }

	for (int i = 0; i < capacity; i++) {
		os << rhs.students[i].name << "\t" << rhs.students[i].bid << endl;
	}

	return os;
}

Course::~Course()
{
}
