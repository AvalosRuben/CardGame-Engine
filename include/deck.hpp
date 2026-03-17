#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "card.hpp"
#include <cstddef>

class Deck{
    private:
        std::vector<Card> cards;
        void fillDeck();

    public:
    //Deck constructor with autocreation 
    Deck(){
        fillDeck();
    }
    void shuffle();
    void shuffle(unsigned int seed);
    Card draw();
    size_t size() const {return cards.size();}
    bool empty() const {return cards.empty();}
};

#endif