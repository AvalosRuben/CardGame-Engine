#include "deck.hpp"
#include <stdexcept>
#include <random>
#include <algorithm>

//Change the enums
namespace{
    const Suit allSuits[4] = {Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades};
    const Rank allRanks[13] = {Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King, Rank::Ace};
    }

void Deck::fillDeck(){
    cards.clear();
    for (int i=0; i < sizeof(allSuits)/sizeof(allSuits[0]); i++){
        for (int j=0; j < sizeof(allRanks)/sizeof(allRanks[0]); j++){

            //Change to create the card on the push_back
            cards.push_back(Card{allSuits[i], allRanks[j]});
        }
    }
}

Card Deck::draw(){
    if (cards.empty() ) {
        throw std::range_error("The deck is empty");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

void Deck::shuffle(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::shuffle(cards.begin(), cards.end(), rng);
}

void Deck::shuffle(unsigned int seed){
    std::mt19937 rng(seed);
    std::shuffle(cards.begin(), cards.end(), rng);
}