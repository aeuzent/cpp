#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "Transaction.h"

class Account {

    public:
        Account(int type);
        Account(int acctNum, int newBalance, int type);
        int getBalance();
        int getAcctNum();
        int getType();
        static const int SAVINGS = 0;
        static const int CHECKING = 1;
        vector<Transaction> getHistory();
        friend ostream& operator<< (ostream &out, Account &acct);
        virtual void processTrans(Transaction &tAction);
        virtual void addInterest();
        string outFormat();
    protected:
        void credit(int ammount);
        bool debit(int ammount);
        void addToHistory(Transaction &tAction);
        void sortHistory();
        int acctNum;
        int balance;
        int type;
        double interest;
        unsigned int maxTrans;
        vector<Transaction> history;
};

#endif // ACCOUNT_H
