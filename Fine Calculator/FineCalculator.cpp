/**
* @filename FineCalculator.cpp
* @author Alex Euzent
* @date 4/03/2014
*/

#include "FineCalculator.h"

using namespace std;

/**
* Default constructor for
* FineCalculator
*/
FineCalculator::FineCalculator(){
	_courtFees = 0;
}

/**
* Constructor for FineCalculator
* that initializes courtFees
*/
FineCalculator::FineCalculator(int courtFees){
	_courtFees = courtFees;
}

/**
* Calculates a fine based on
* parameters received
* @param zone
* @param speedLimit
* @param actualSpeed
* @return int
*/
int FineCalculator::getFine(int zone, int speedLimit, int actualSpeed) const {
	int milesOver = 0;
	int totalFee = 0;
	if (actualSpeed>speedLimit){
		milesOver = actualSpeed - speedLimit;
	}

	switch (zone){
	case 1: totalFee = milesOver * 5 + _courtFees;
		break;
	case 2: totalFee = milesOver * 6 + _courtFees;
		break;
	case 3: totalFee = milesOver * 7 + 200 + _courtFees;
		break;
	}
	return totalFee;
}
