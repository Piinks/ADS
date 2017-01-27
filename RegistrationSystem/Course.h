#pragma once

#ifndef COURSE
#define COURSE

#include <vector>
#include <string>
using namespace std;

struct Student {
	string name;
	int bid;
};

class Course
{
public:
	Course(string n);
	void addStudent(string n, int b);
	void removeStudent(string n);
	string getCourseName();
	int getCourseNum();
	friend ostream& operator<<(ostream& os, const Course& rhs);
	~Course();

private:
	vector<Student> students;
	vector<Student>::iterator iter;
	string courseName;
};

#endif