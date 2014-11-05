/**
 * @filename deck.cpp
 * @author Alex Euzent
 * @date 4/22/2014
 */
#include "deck.h"
#include "card.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


/**
 * Constructor for
 * StandardDeck
 */
StandardDeck::StandardDeck(){
    top = 0;
    deck.reserve(52);
    for(int x = 0; x < 52; x++){
        Card curr(x);
        deck.push_back(curr);
        called[x] = false;
    }
}


/**
 * Function to shuffle deck
 */
void StandardDeck::shuffle() {
    cout << "Shuffling Deck" << endl << endl;
    for (unsigned int i=0; i < deck.size(); i++){
        swap( deck.at(i), deck.at(rand() % deck.size()));
        called[i] = false;
    }
    top = 0;
}


/**
 * Function to swap cards
 * @param c1
 * @param c2
 */
void StandardDeck::swap( Card &c1, Card &c2 ) {
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}


/**
 * Function to print entire deck
 */
void StandardDeck::printDeck(){
    for(unsigned int x = 0; x < deck.size(); x++){
        cout << deck.at(x) << endl;
    }
}


/**
 * Function to deal a free
 * random card from the deck
 * @return Card
 */
Card StandardDeck::dealCard(){
    top = rand() % deck.size();
    while(called[top]){
        top = rand() % deck.size();
    }
    Card out = deck.at(top);
    called[top] = true;
    return out;
}


/**
 * Function to check if deck
 * still has free cards
 * @return bool
 */
bool StandardDeck::hasFree(){
    bool result = false;
    for(int z = 0; z < 52; z++){
        if(!called[z]){
            result = true;
        }
    }
    return result;
}
