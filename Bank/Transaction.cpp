/**
 * @filename Transaction.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include "Transaction.h"
#include <string>

using namespace std;


/**
 * Constructor for Transaction
 * @param type
 * @param acct
 * @param date
 * @param amt
 */
Transaction::Transaction(int type, int acct, Date &date, int amt){
    this->type = type;
    this->acct = acct;
    this->date = date;
    this->amt = amt;
}


/**
 * Accessor for type
 * @return int
 */
int Transaction::getType() const{
    return type;
}


/**
 * Accessor for account#
 * @return int
 */
int Transaction::getAcct() const{
    return acct;
}


/**
 * Accessor for date
 * @return Date
 */
Date Transaction::getDate() const{
    return date;
}


/**
 * Accessor for amount
 * @return int
 */
int Transaction::getAmt() const{
    return amt;
}


/**
 * Overloaded operator for =
 * @return Transaction
 */
Transaction& Transaction::operator=(const Transaction &tAction){
    if(this == &tAction)
        return *this;

    this->type = tAction.getType();
    this->acct = tAction.getAcct();
    this->date = tAction.getDate();
    this->amt = tAction.getAmt();
    return *this;
}


/**
 * Overloaded operator for <<
 * @return ostream
 */
ostream& operator<< (ostream &out, Transaction &tAction)
{
    string typeStr = "";
    if(tAction.getType() == Transaction::WITHDRAW){
        typeStr = "Withdraw";
    } else if (tAction.getType() == Transaction::DEPOSIT){
        typeStr = "Deposit";
    }

    out << tAction.getDate() << " - " << typeStr << " of $"
        << tAction.getAmt() << " to account #" << tAction.getAcct();

    return out;
}
