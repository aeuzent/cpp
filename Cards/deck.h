/**
 * @filename deck.h
 * @author Alex Euzent
 * @date 4/22/2014
 */
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"


class StandardDeck {
    public:
        StandardDeck();
        void shuffle();
        void printDeck();                // shuffle the deck
        Card dealCard();
        bool hasFree();
   private:
        int top;
        bool called[52];
        vector<Card> deck;             // the deck of cards
        void swap( Card &, Card & );   // used for shuffling
};
#endif
