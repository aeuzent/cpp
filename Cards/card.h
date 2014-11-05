/**
 * @filename card.h
 * @author Alex Euzent
 * @date 4/22/2014
 */
#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;


class Card
   {
   friend ostream& operator<<( ostream &stream, const Card &card );
   public:
        Card(int in);
   private:
        int rank;
        int suit;
        static string suit_str[4];         // output strings for suit
        static string rank_str[13];        // output strings for rank
   };

#endif
