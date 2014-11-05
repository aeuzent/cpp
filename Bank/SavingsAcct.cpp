/**
 * @filename SavingsAcct.cpp
 * @author Alex Euzent
 * @date 5/5/2014
 */

#include <iostream>
#include "SavingsAcct.h"
#include "Account.h"
#include "Transaction.h"
#include "Date.h"

using namespace std;


/**
 * Processes a Transaction if limit
 * has not been reached in the last
 * 30 days
 * @param tAction
 */
void SavingsAcct::processTrans(Transaction &tAction){
    Date today;
    Date limit = today.subDays(30);
    int inLimit = 0;
    for(unsigned int x = 0; x < history.size(); x++){
        Date curr = history.at(x).getDate();

        if(curr > limit){
            inLimit++;
        }
    }

    if(inLimit < 3){
        Account::processTrans(tAction);
    } else {
        cout << "Transaction limit reached for account# " << acctNum << endl;
        cout << "Failed: " << tAction << endl << endl;
    }
}


/**
 * Adds interest as a non-Transaction
 */
void SavingsAcct::addInterest(){
    credit(balance*interest);
}
