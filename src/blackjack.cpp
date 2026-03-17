#include "blackjack.hpp"
#include <stdexcept>

int blackjack::card_value(const Card& card){
    //Later may be changed to either lookup tables or constexpr mappings
    switch(card.rank){
        case Rank::Two:
            return 2;
        case Rank::Three:
            return 3;
        case Rank::Four:
            return 4;
        case Rank::Five:
            return 5;
        case Rank::Six:
            return 6;
        case Rank::Seven:
            return 7;
        case Rank::Eight:
            return 8;
        case Rank::Nine:
            return 9;
        case Rank::Ten:
        case Rank::Jack:
        case Rank::Queen:
        case Rank::King:
            return 10;
        case Rank::Ace:
            return 11;
        default:
            throw std::logic_error("Invalid card rank");
    }
}

blackjack::HandResult blackjack::evaluate_hand (const std::vector<Card>& hand) {
    //know the total value of the hand
    int value = 0;
    bool is_soft = false;
    bool is_blackjack = false;
    bool is_bust = false;
    int ace_count = 0;
    for(const Card& card : hand) {
        value += blackjack::card_value(card);
        if(card.rank == Rank::Ace){
            ace_count += 1;
        }
    }

    while(value > 21 && ace_count > 0){
        value -= 10;
        ace_count--;
    }

    if(ace_count > 0){
        is_soft = true;
    }

    if(value>21){
        is_bust = true;   
    }

    if(value == 21 && hand.size() == 2){
        is_blackjack = true;
    }

    return HandResult{value, is_blackjack, is_bust, is_soft};

}