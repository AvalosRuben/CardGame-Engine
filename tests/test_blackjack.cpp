#include <iostream>
#include <vector>
#include <cassert>
#include "blackjack.hpp"
#include "card.hpp"

using blackjack::evaluate_hand;
using blackjack::HandResult;

void print_result(const std::string& name, const HandResult& r) {
    std::cout << name
              << " -> value: " << r.value
              << " blackjack: " << r.is_blackjack
              << " bust: " << r.is_bust
              << " soft: " << r.is_soft
              << std::endl;
}

void run_test(const std::string& name,
              const std::vector<Card>& hand,
              int expected_value,
              bool expected_blackjack,
              bool expected_bust,
              bool expected_soft)
{
    HandResult r = evaluate_hand(hand);

    print_result(name, r);

    assert(r.value == expected_value);
    assert(r.is_blackjack == expected_blackjack);
    assert(r.is_bust == expected_bust);
    assert(r.is_soft == expected_soft);
}

int main() {

    std::cout << "Running Blackjack Engine Tests...\n\n";

    // Blackjack
    run_test(
        "Blackjack",
        { {Suit::Hearts, Rank::Ace}, {Suit::Spades, Rank::King} },
        21, true, false, true
    );

    // Hard 21 (not blackjack)
    run_test(
        "Hard 21",
        { {Suit::Hearts, Rank::Seven},
          {Suit::Clubs, Rank::Seven},
          {Suit::Spades, Rank::Seven} },
        21, false, false, false
    );

    // Soft hand
    run_test(
        "Soft 17",
        { {Suit::Hearts, Rank::Ace}, {Suit::Clubs, Rank::Six} },
        17, false, false, true
    );

    // Soft -> Hard conversion
    run_test(
        "Ace adjustment",
        { {Suit::Hearts, Rank::Ace},
          {Suit::Clubs, Rank::Nine},
          {Suit::Spades, Rank::Eight} },
        18, false, false, false
    );

    // Multiple aces
    run_test(
        "Multiple aces",
        { {Suit::Hearts, Rank::Ace},
          {Suit::Clubs, Rank::Ace},
          {Suit::Spades, Rank::Nine} },
        21, false, false, true
    );

    // Bust
    run_test(
        "Bust",
        { {Suit::Hearts, Rank::Ten},
          {Suit::Clubs, Rank::Eight},
          {Suit::Spades, Rank::Seven} },
        25, false, true, false
    );

    // Many cards
    run_test(
        "Long hand",
        { {Suit::Hearts, Rank::Two},
          {Suit::Clubs, Rank::Three},
          {Suit::Spades, Rank::Four},
          {Suit::Diamonds, Rank::Five},
          {Suit::Hearts, Rank::Six} },
        20, false, false, false
    );

    // Ace edge case
    run_test(
        "Triple Ace",
        { {Suit::Hearts, Rank::Ace},
          {Suit::Clubs, Rank::Ace},
          {Suit::Spades, Rank::Ace},
          {Suit::Diamonds, Rank::Eight} },
        21, false, false, true
    );

    std::cout << "\nAll tests passed.\n";

    return 0;
}