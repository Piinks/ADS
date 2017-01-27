#include "Card.h"
using namespace std;

Card::Card(){
	faceValue = 0;
	pointValue = 0;
}

Card::Card(int fV, suite t) {
	type = t;
	faceValue = fV;
	if (fV == 1)
		pointValue = 15;
	else if (fV >= 10)
		pointValue = 10;
	else
		pointValue = fV;
}

ostream& operator<<(ostream& os, const Card& cd) {
	if (cd.faceValue == 1)
		os << 'A';
	else if (cd.faceValue == 11)
		os << 'J';
	else if (cd.faceValue == 12)
		os << 'Q';
	else if (cd.faceValue == 13)
		os << 'K';
	else
		os << cd.faceValue;

	if (cd.type == hearts)
		os << ((char)0x03);
	else if (cd.type == clubs)
		os << ((char)0x05);
	else if (cd.type == spades)
		os << ((char)0x06);
	else
		os << ((char)0x04);

	os << '[' << cd.pointValue << "] ";
	return os;
}

bool Card::operator < (const Card& cd) const {
	return (pointValue < cd.pointValue);
}

bool Card::operator > (const Card& cd) const {
	return (pointValue > cd.pointValue);
}

bool Card::operator == (const Card& cd) const {
	return (pointValue == cd.pointValue);
}

int Card::getPointValue() const {
	return pointValue;
}

