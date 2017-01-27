// Kate Archer - OLA1
// main.cpp

#include "BigInt.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	BigInt largeNum("7234987645791286234124781481841814812481247");
	cout << "The mod division of ";
	largeNum.display();
	cout << " by 97 is: " << largeNum.mod(97) << endl;

	string newLNum;
	cout << "Enter another number: ";
	cin >> newLNum;
	BigInt largeNum2(newLNum);
	cout << "The mod division of " << newLNum << " by 97 is " << largeNum2.mod(97) << endl;

	return 0;
}
