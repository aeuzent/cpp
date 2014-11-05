/**
 * @filename CheckingAcct.h
 * @author Alex Euzent
 * @date 5/5/2014
 */

#ifndef CHECKINGACCT_H
#define CHECKINGACCT_H

#include <vector>
#include "Transaction.h"
#include "Account.h"


class CheckingAcct : public Account {

    public:
        CheckingAcct() : Account(Account::CHECKING)
        {
            history.reserve(30);
        };
        CheckingAcct(int acctNum, int newBalance): Account(acctNum, newBalance, Account::CHECKING)
        {
            history.reserve(30);
        };
};

#endif // CHECKINGACCT_H
