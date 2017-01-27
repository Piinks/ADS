// Kate Archer
// PrimeTest.cpp

#include "PrimeTest.h"
#include <iostream>
#include <fstream>
using namespace std;


PrimeTest::PrimeTest(ifstream& inFile) {
	inFile >> num;						// Sets num
	middle = (num / 2) + 1;				// Sets middle number
	isPrime = !(isNotPrime(middle));	// Calls isNotPrime function
}

bool PrimeTest::isNotPrime(int mid) {	// recursive prime function
	if (mid == 2)
		return ((num % mid) == 0);		// tests for the number being divisible from 2 to the middle number.
	else
		return ((num % mid) == 0) || isNotPrime(mid - 1);
}

void PrimeTest::printResult() {
	cout << num << " is ";			// Prints result.
	if (isPrime)
		cout << "a prime number." << endl;
	else
		cout << "not a prime number." << endl;
}
PrimeTest::~PrimeTest()
{
}
