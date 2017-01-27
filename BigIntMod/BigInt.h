// Kate Archer - OLA1
// BigInt.h

#include <iostream>
#include <string>
using namespace std;

#ifndef BIGINT_H
#define BIGINT_H

class BigInt{

public:
	BigInt(string sNum);

	void set(string sNum);
	void display();
	int mod(int modNum);

	~BigInt();

private:
	string stringNum;
	int remainder;
};

#endif
