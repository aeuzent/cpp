/**
 * @filename hand.cpp
 * @author Alex Euzent
 * @date 4/22/2014
 */
#include "hand.h"
#include "deck.h"
#include "card.h"
#include <iostream>

using namespace std;


/**
 * Constructor for Hand
 * @param n
 */
Hand::Hand(int n){
    hand.reserve(n);
}


/**
 * Function to print hand
 */
void Hand::printHand(){
    for(unsigned int x = 0; x < hand.size(); x++){
        cout << hand.at(x) << endl;
    }
}


/**
 * Function to clear hand
 */
void Hand::clearHand(){
    hand.clear();
}


/**
 * Function to add card to hand
 */
void Hand::addCard(Card &card){
    hand.push_back(card);
}
