#pragma once

#ifndef REGSYSTEM
#define REGSYSTEM

#include <vector>
#include "Course.h"
#include <string>
using namespace std;

class RegSystem 
{
public:
	RegSystem(string n);
	void readFile(string n);
	void printRegistration();

private:
	string sysName;
	void addCourse(Course& aCourse);
	bool findCourse(string cN);
	vector<Course> courses;
	vector<Course>::iterator it;

	//Reading variables
	char bidDrop;
	int bid;
	string courseName;
	string fName;
	string lName;

};
#endif
