/**
 * @filename main.cpp
 * @author Alex Euzent
 * @date 4/22/2014
 */
#include <iostream>
#include "deck.h"
#include "hand.h"
#include "card.h"

using namespace std;


/**
 * Function to fill a hand and
 * shuffle deck if needed.
 * @param hand
 * @param deck
 * @param num
 */
void fillHand(Hand &hand, StandardDeck &deck, int num){
    for(int x = 0; x < num; x++){
        if(deck.hasFree()){
            Card crd = deck.dealCard();
            hand.addCard(crd);
        } else {
            hand.clearHand();
            deck.shuffle();
            for(int z = 0; z < x; z++){
                Card crd = deck.dealCard();
                hand.addCard(crd);
            }
        }
    }
}

/**
 * main function
 */
int main()
{
    StandardDeck deck;
    deck.shuffle();

    for(int x = 0; x < 17; x++){
        Hand hand(5);
        fillHand(hand, deck, 5);
        hand.printHand();
        cout << endl << endl;
    }

    return 0;
}
