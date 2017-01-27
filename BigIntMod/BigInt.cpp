// Kate Archer - OLA1
// BigInt.cpp

#include "BigInt.h"
#include <string>
#include <iostream>
using namespace std;


BigInt::BigInt(string sNum)
{
	stringNum = sNum;
	remainder = 0;
}

void BigInt::set(string sNum) {
	stringNum = sNum;
}

void BigInt::display() {
	cout << stringNum;
}

int BigInt::mod(int modNum) {
	int numLength = stringNum.length();
	int count = 1;
	int index = 0, substrLength = 7;
	int tempInt = 0;
	string tempString;

	tempString = stringNum.substr(index, substrLength);

	while((substrLength*count) <= numLength){
		tempInt = stoi(tempString);
		remainder = tempInt % modNum;
		count++, index +=7;
		tempString = to_string(remainder) + stringNum.substr(index, substrLength);
	}

	tempInt = stoi(tempString);

	remainder = tempInt % modNum;
	return remainder;
};

BigInt::~BigInt(){}
