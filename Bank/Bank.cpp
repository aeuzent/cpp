/**
 * @filename Bank.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Bank.h"
#include "SavingsAcct.h"
#include "CheckingAcct.h"
#include "Date.h"

using namespace std;

/**
 * Constructor for Bank
 */
Bank::Bank()
{
    accounts.reserve(50);
    rawAccts.reserve(50);
    rawTacts.reserve(50);
}

Bank::~Bank(){
    for(unsigned int x = 0; x < accounts.size(); x++){
        delete accounts[x];
    }
    accounts.clear();
}

/**
 * Loads data from file
 * @return bool
 */
bool Bank::readFile(){
    cout << "Loading file..." << endl;
    bool result = false;
    string line = "";
    ifstream inFile;
    inFile.open("input.txt");
    if(inFile.is_open()){
        while(getline(inFile, line)){
            string header = line.substr(0,4);
            if(header == "acct"){
                rawAccts.push_back(line);
            } else if (header == "tact"){
                rawTacts.push_back(line);
            }
        }
        inFile.close();
        result = true;
        loadAccounts();
        loadTransactions();
    }

    return result;
}


/**
 * Converts raw account to Account
 * object and adds to Bank
 */
void Bank::loadAccounts(){
    cout << "Loading accounts..." << endl;
    char delim = ',';
    for(unsigned int x = 0; x < rawAccts.size(); x++){
        string *curr = split(rawAccts.at(x),4,delim);
        int type = atoi(curr[1].c_str());
        int acctNum = atoi(curr[2].c_str());
        int balance = atoi(curr[3].c_str());
        if(type == Account::SAVINGS){
            accounts.push_back(new SavingsAcct(acctNum, balance));
        } else if (type == Account::CHECKING){
            accounts.push_back(new CheckingAcct(acctNum, balance));
        }
    }
}


/**
 * Converts raw transaction to
 * Transaction object and adds to
 * proper account
 */
void Bank::loadTransactions(){
    cout << "Loading transactions..." << endl;
    char delim = ',';
    for(unsigned int x = 0; x < rawTacts.size(); x++){
        string *curr = split(rawTacts.at(x),5,delim);
        int type = atoi(curr[1].c_str());
        int acctNum = atoi(curr[2].c_str());
        Date date = parseDate(curr[3]);
        int amt = atoi(curr[4].c_str());

        Transaction currTrans(type, acctNum, date, amt);
        for(unsigned int i = 0; i < accounts.size(); i++){

            if(accounts.at(i)->getAcctNum() == acctNum){
                    accounts.at(i)->processTrans(currTrans);

            }
        }
    }

}


/**
 * Splits a string into an array
 * of strings on a delimiter
 * @param str
 * @param size
 * @param delim
 * @return string*
 */
string * Bank::split(string &str, int size, char &delim){
    string *out = new string[size];
    int count = 0;
    int lastFound = 0;

    for(unsigned int x = 0; x < str.length(); x++){
        if(str.at(x) == delim){
            out[count] = str.substr(lastFound, x-lastFound);
            count++;
            lastFound = x+1;
        }
        if(x == str.length()-1){
            out[count] = str.substr(lastFound, x-str.length());
        }
    }

    return out;
}


/**
 * Converts raw date to Date
 * object
 * @param dateStr
 * @return Date
 */
Date Bank::parseDate(string &dateStr){

    char delim = '/';
    string *parts = split(dateStr,3,delim);
    int month = atoi(parts[0].c_str());
    int day = atoi(parts[1].c_str());
    int year = atoi(parts[2].c_str());

    Date newDate(month,day,year);
    return newDate;
}


/**
 * Prints all accounts in Bank
 */
void Bank::printAccounts(){
    cout << endl;
    for(unsigned int x = 0; x < accounts.size(); x++){
            Account *current = accounts.at(x);
            cout << *current << endl << endl;

    }
}


/**
 * Calls interest method on each account
 * if it's the first of the month
 */
void Bank::doInterest(){
    Date today;
    if(today.getDay() == 1){
        for(unsigned int x = 0; x < accounts.size(); x++){
            Account *current = accounts.at(x);
            current->addInterest();
        }
    }
}


/**
 * Writes all accounts to file
 */
void Bank::writeFile(){
    cout << "Writing accounts to output.txt...." << endl;
    ofstream outFile("output.txt");
    if(outFile.is_open()){
        outFile << "//Accounts" << endl;
        outFile << "//acct,<type>,<acctNum>,<balance>" << endl;
        for(unsigned int x = 0; x < accounts.size(); x++){
            Account *current = accounts.at(x);
            string temp = current->outFormat();
            outFile << temp << endl;;
        }
    }
}
