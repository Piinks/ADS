#include "Roster.h"
#include <string>
#include <stdexcept>
#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

Roster::Roster(string courseName)
{
	m_courseName = courseName;
	m_studentNum = 0;
}

void Roster::readStudentRecord(string fileName)
{
	ifstream inFile;
	inFile.open(fileName); //fileName.c_str()
	getline(inFile, heading);
	heading = heading.substr(2, 52);
	string id;
	int score;

	while (inFile) {
		Student aStudent;
		inFile >> id;
		aStudent.setID(id);
		inFile >> score;
		aStudent.changeScore(Student::CLA, score);
		inFile >> score;
		aStudent.changeScore(Student::OLA, score);
		inFile >> score;
		aStudent.changeScore(Student::QUIZ, score);
		inFile >> score;
		aStudent.changeScore(Student::HOMEWORK, score);
		inFile >> score;
		aStudent.changeScore(Student::EXAM, score);
		inFile >> score;
		aStudent.changeScore(Student::BONUS, score);

		m_students[m_studentNum] = aStudent;
		m_studentNum++;
	}
}

void Roster::displayRosterMenu(void) {
	cout << "***********Welcome to the class roster for " << m_courseName << "!***********" << endl;
	cout << "Enter I for an individual student, C to view the whole class, or Q to quit!" << endl << endl;
}

void Roster::singleStudent(std::string id) {
	cout << heading << endl;
	for (int i = 0; i < (m_studentNum-1); i++) {
		if (m_students[i].getID() == id) {
			cout << m_students[i].getID() << "\t  " << m_students[i].getScore(Student::CLA) << '\t' << m_students[i].getScore(Student::OLA)
				<< '\t' << m_students[i].getScore(Student::QUIZ) << '\t' << m_students[i].getScore(Student::HOMEWORK)
				<< '\t' << m_students[i].getScore(Student::EXAM) << '\t' << m_students[i].getScore(Student::BONUS) << endl;
			break;
		}
	}
}

void Roster::printRoster(void) {
	cout << heading << endl;
	for (int i = 0; i < (m_studentNum-1); i++) {
		cout << m_students[i].getID() << "\t  " << m_students[i].getScore(Student::CLA) << '\t' << m_students[i].getScore(Student::OLA)
			<< '\t' << m_students[i].getScore(Student::QUIZ) << '\t' << m_students[i].getScore(Student::HOMEWORK)
			<< '\t' << m_students[i].getScore(Student::EXAM) << '\t' << m_students[i].getScore(Student::BONUS) << endl;
	}
}

