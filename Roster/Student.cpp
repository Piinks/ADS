#include "Student.h"
#include <string>
#include <stdexcept>
using namespace std;


Student::Student(void)
{}


string Student::getID(void) const {
	return m_id;
}

void Student::setID(string id) {
	m_id = id;
}

void Student::changeScore(const ScoreType type, const int score) {
	m_score[type] = score;
}

int Student::getScore(const ScoreType type) const {
	return m_score[type];
}
