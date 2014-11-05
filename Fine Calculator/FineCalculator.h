/**
* @filename FineCalculator.h
* @author Alex Euzent
* @date 4/03/2014
*/

#ifndef FINECALCULATOR_H

using namespace std;

class FineCalculator {
public:
	FineCalculator();
	FineCalculator(int courtFees);
	int getFine(int zone, int speedLimit, int actualSpeed) const;
private:
	int _courtFees;
};
#define FINECALCULATOR_H
#endif
