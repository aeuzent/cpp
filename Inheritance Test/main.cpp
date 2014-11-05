#include <iostream>
#include "Shark.h"

using namespace std;

int main()
{
    string name = "Dave";
    string waterType = "Salt";
    string type = "Great White";
    Shark current(name, waterType, type);

    cout << "Name is " << current.name << endl;
    cout << "Water type is " << current.waterType << endl;
    cout << "Type is " << current.type << endl;

    return 0;
}
