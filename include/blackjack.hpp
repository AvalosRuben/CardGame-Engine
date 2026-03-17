#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "card.hpp"
#include <vector>

namespace blackjack{
    //HandResult
    //Card Value
    //evaluate_hand
    struct HandResult{
        int value;
        bool is_blackjack;
        bool is_bust;
        bool is_soft; 
        //Constructor initializing everything
        HandResult() : value(0), is_blackjack(false), is_bust(false), is_soft(false) {}
        HandResult(int v, bool bj, bool bust, bool soft)
        : value(v), is_blackjack(bj), is_bust(bust), is_soft(soft) {}
    };

    
    int card_value(const Card& card);
    HandResult evaluate_hand(const std::vector<Card>& hand);

};

#endif