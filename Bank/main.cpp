/**
 * @filename main.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include <iostream>
#include <string>
#include "Date.h"
#include "Bank.h"

using namespace std;

int main()
{
    Bank bank;
    if(bank.readFile()){
        bank.doInterest();

        cout << "------------------" << endl;
        cout << "Current Accounts: " << endl;
        cout << "------------------" << endl;
        bank.printAccounts();

        bank.writeFile();
    }
}
