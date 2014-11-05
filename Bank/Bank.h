/**
 * @filename Bank.h
 * @author Alex Euzent
 * @date 5/5/2014
 */

#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Account.h"
#include "Date.h"

class Bank
{
    public:
        Bank();
        ~Bank();
        bool readFile();
        void writeFile();
        void printAccounts();
        void doInterest();

    private:
        vector<Account*> accounts;
        vector<string> rawAccts;
        vector<string> rawTacts;
        void loadAccounts();
        void loadTransactions();
        Date parseDate(string &dateStr);
        string * split(string &str, int size, char &delim);


};

#endif // BANK_H
