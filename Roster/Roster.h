#pragma once

#ifndef __CSCI3110_ROSTER__
#define __CSCI3110_ROSTER__

#include <string>
#include <stdexcept>
#include "Student.h"

class Roster
{
public:

	// constructor, the parameter is the course name
	// Create an empty roster, i.e. m_studentNum = 0 for
	// a specific course
	Roster(std::string courseName);

	// This function reads student information from a file
	// The parameter is a file name
	// post-condition:
	//		m_students contains student information read from the file
	//		m_studentNum is the number of students read from the file
	void readStudentRecord(std::string fileName);

	void displayRosterMenu(void);
	void singleStudent(std::string id);
	void printRoster(void);
private:
	static const int	MAX_NUM = 25;			// The maximum # of students of a class
												// Class constant. All objects share the same copy
	std::string			m_courseName;			// The name of the course
	int					  m_studentNum;			// Actual Student #
	Student				m_students[MAX_NUM]; 	// The array of student objects
	std::string heading;
};
#endif
