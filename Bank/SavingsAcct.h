/**
 * @filename SavingsAcct.h
 * @author Alex Euzent
 * @date 5/5/2014
 */

#ifndef SAVINGSACCT_H
#define SAVINGSACCT_H

#include <vector>
#include "Transaction.h"
#include "Account.h"

class SavingsAcct : public Account{

    public:
        SavingsAcct() : Account(Account::SAVINGS)
        {
            history.reserve(10);
        };
        SavingsAcct(int acctNum, int newBalance) : Account(acctNum, newBalance, Account::SAVINGS)
        {
            history.reserve(10);
        };
        void processTrans(Transaction &tAction);
        void addInterest();
    private:
        void addToHistory(Transaction &tAction);

};

#endif // SAVINGSACCT_H
