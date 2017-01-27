#include "RegSystem.h"
#include <iostream>

int main() {
	cout << "Welcome to the MTSU Registration Management System!" << endl << endl;
	RegSystem fall16 = RegSystem("Fall 2016");

	fall16.readFile("test2.txt");

	fall16.printRegistration();

	return 0;
}
