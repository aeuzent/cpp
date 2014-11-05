/**
 * @filename Transaction.h
 * @author Alex Euzent
 * @date 5/5/2014
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"

class Transaction
{
    public:
        Transaction(int type, int acct, Date &date, int amt);
        int getType() const;
        int getAcct() const;
        Date getDate() const;
        int getAmt() const;
        static const int DEPOSIT = 0;
        static const int WITHDRAW = 1;
        Transaction& operator=(const Transaction &tAction);
        friend ostream& operator<< (ostream &out, Transaction &tAction);


    private:
        int type;
        int acct;
        Date date;
        int amt;
};

#endif // TRANSACTION_H
