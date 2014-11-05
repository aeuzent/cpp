/**
 * @filename card.cpp
 * @author Alex Euzent
 * @date 4/22/2014
 */
#include "card.h"
#include <iostream>

using namespace std;

string Card::rank_str[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string Card::suit_str[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};


/**
 * Constructor for Card
 * @param in
 */
Card::Card(int in){
    suit = in / 13;
    rank = in % 13;
}


/**
 * Overloaded operator to pass cards
 * to streams
 * @param stream
 * @param card
 */
ostream& operator<<( ostream &stream, const Card &card )
   {
   stream << Card::rank_str[ card.rank ] << " of "
          << Card::suit_str[ card.suit ];
   return stream;
   }




