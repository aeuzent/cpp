/**
 * @filename Account.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Account.h"
#include "Transaction.h"
#include "Date.h"

using namespace std;


/**
 * Constructor for Account
 * @param type
 */
Account::Account(int type){
    balance = 0;
    acctNum = 0;
    this->type = type;
    if(type == Account::CHECKING){
        maxTrans = 30;
        interest = 0.01;
    } else if (type == Account::SAVINGS){
        maxTrans = 10;
        interest = 0.015;
    }
}


/**
 * Constructor for Account
 * @param acctNum
 * @param newBalance
 * @param type
 */
Account::Account(int acctNum, int newBalance, int type){
    this->acctNum = acctNum;
    if(newBalance >= 0){
        balance = newBalance;
    } else {
        balance = 0;
        cout << "New balance for account #" << acctNum <<" invalid" << endl << endl;
    }
    this->type = type;
    if(type == Account::CHECKING){
        maxTrans = 30;
    } else if (type == Account::SAVINGS){
        maxTrans = 10;
    }
}


/**
 * Adds amount to balance
 * @param amount
 */
void Account::credit(int amount){
    balance += amount;
}


/**
 * Removes amount from balance
 * if available
 * @param amount
 * @return bool
 */
bool Account::debit(int amount){
    bool result = false;
    int testBalance = balance;
    int newBalance = testBalance - amount;
    if(newBalance > 0){
        balance = newBalance;
        result = true;
    }
    return result;
}


/**
 * Accessor for balance
 * @return int
 */
int Account::getBalance(){
    return balance;
}


/**
 * Accessor for account number
 * @return int
 */
int Account::getAcctNum(){
    return acctNum;
}


/**
 * Accessor for transaction
 * history
 * @return vector<Transaction>
 */
vector<Transaction> Account::getHistory(){
    return history;
}


/**
 * Accessor for type
 * @return int
 */
int Account::getType(){
    return type;
}


/**
 * Orders transaction history
 * by date using a bubble sort
 */
void Account::sortHistory(){
    bool done = false;
    while(!done){
        done = true;
        for(unsigned int x = 0; x < history.size()-1; x++){
            Date a = history.at(x).getDate();
            Date b = history.at(x+1).getDate();
            if(a > b){
                Transaction tmp = history.at(x);
                history.at(x) = history.at(x+1);
                history.at(x+1) = tmp;
                done = false;
            }
        }
    }
}


/**
 * Processes Transaction object
 * to account
 * @param tAction
 */
void Account::processTrans(Transaction &tAction){
    if(tAction.getType() == Transaction::DEPOSIT){
        credit(tAction.getAmt());
        addToHistory(tAction);
    } else if (tAction.getType() == Transaction::WITHDRAW){
            if(debit(tAction.getAmt())){
                addToHistory(tAction);
            } else {
                cout << "Insufficient funds in account #" << acctNum << " for transaction: " << endl;
                cout << tAction << endl << endl;
            }
    }
}


/**
 * Overloaded operator for <<
 * @return ostream
 */
ostream& operator<< (ostream &out, Account &acct)
{
    if(acct.getType() == Account::CHECKING){
        out << "Checking Account#: " << acct.getAcctNum() << endl;
    } else if (acct.getType() == Account::SAVINGS){
        out << "Savings Account#: " << acct.getAcctNum() << endl;
    }
    out << "Balance: $" << acct.getBalance() << endl
        << "Transaction History: " << endl;


    for(unsigned int x = 0; x < acct.getHistory().size(); x++){
        out << acct.getHistory().at(x) << endl;
    }

    return out;
}


/**
 * Saves Transaction to history
 * @param tAction
 */
void Account::addToHistory(Transaction &tAction){
    if(history.size() != maxTrans){
        history.push_back(tAction);
        sortHistory();
    } else {
        history.pop_back();
        history.push_back(tAction);
        sortHistory();
    }
}


/**
 * Adds interest as a non-Transaction
 */
void Account::addInterest(){
    if(balance < 10000){
        credit(balance*interest);
    }
}


/**
 * Formats Account as string
 * for writing to file
 * @return string
 */
string Account::outFormat(){
    ostringstream os;
    os << "acct," << getType() << "," << getAcctNum() << "," << getBalance();
    string out = os.str();
    return out;
}
