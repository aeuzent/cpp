/**
* @filename Project.cpp
* @author Alex Euzent
* @date 4/03/2014
*/

#include <iostream>
#include "FineCalculator.h"

using namespace std;

class Project {
public:
	Project();
private:
	bool processFee(FineCalculator& fineCalc);

};

/**
* Constructor for Project1
* initiates console menu
*/
Project::Project(){
	int courtFees = 0;
	bool done = false;

	cout << "Speeding Fine Calculator" << endl << endl;
	cout << "Enter court fees: ";
	cin >> courtFees;
	cout << endl;

	FineCalculator fineCalc(courtFees);

	do{
	done = processFee(fineCalc);
	}while(done);

}

/**
* Receives a FineCalculator object
* by reference and processes a single
* fee. Returns true if user requests
* an additional fee processing
* @param fineCalc
* @return bool
*/
bool Project::processFee(FineCalculator& fineCalc){

	bool result = false;
	int zone = 0;
	int speedLimit = 0;
	int actualSpeed = 0;
	int choice = 0;
	int totalFee = 0;

	cout << "Speeding Zone Types" << endl;
	cout << "\t1 for Regular" << endl;
	cout << "\t2 for Highway" << endl;
	cout << "\t3 for Residential" << endl;
	cout << "Enter zone: ";
	cin >> zone;

	cout << "Enter speed limit: ";
	cin >> speedLimit;

	cout << "Enter the vehicle's speed: ";
	cin >> actualSpeed;

	cout << endl;


	totalFee = fineCalc.getFine(zone, speedLimit, actualSpeed);
	cout << "Total fine is $" << totalFee << endl << endl;

	cout << "Enter 1 to process another fee, 0 to quit: ";
	cin >> choice;
	cout << endl;

	if (choice == 1){
		result = true;
	}
	return result;
}

int main(){
	Project go;
	return 0;
}
