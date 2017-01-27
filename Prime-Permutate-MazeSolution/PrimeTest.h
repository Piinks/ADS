// Kate Archer
// PrimeTest.h

#pragma once

#ifndef PRIMETEST
#define PRIMETEST

#include <iostream>
#include <fstream>
using namespace std;

class PrimeTest
{
public:
	PrimeTest(ifstream& inFile);	// Constructor
	bool isNotPrime(int mid);		// Recursive prime test
	void printResult();				// Prints result of prime test
	~PrimeTest();

private:
	int num;		// Number to test
	int middle;		// Middle number to set boundaries of recursive function
	bool isPrime;	// bool for primality.
};

#endif
