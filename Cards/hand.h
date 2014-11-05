/**
 * @filename hand.h
 * @author Alex Euzent
 * @date 4/22/2014
 */

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "deck.h"
#include "card.h"


class Hand {
    public:
        Hand(int n);
        void printHand();
        void clearHand();
        void addCard(Card &card);

   private:
       vector<Card> hand;
};

#endif
