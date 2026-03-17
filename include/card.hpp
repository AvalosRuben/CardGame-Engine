#ifndef CARD_HPP
#define CARD_HPP

//Card atributes
enum class Suit{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

struct Card{
    Suit suit;
    Rank rank;
};

#endif