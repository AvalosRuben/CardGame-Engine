# CardGame-Engine

## Description

This C++ module is a Card Game engine, although it only has the blackjack functionalities, it has the bases to support other card games, such as poker, 'viuda', etc. The blackjack functionalities were added for an MVP and it may or may not be finished.

The objective of this module is to be used on a python server and creating a multiplayer game which can use mainly blackjack, but that could implement other card games.

## Language - C++

## Structure

### Include Folder

As it suggests, it has the .hpp's files where we define what each file has access to, what it includes we could say, it has:

- blackjack.hpp
- card.hpp
- deck.hpp

### Src Folder

It has the .cpp's files, where the full implementations were written, it contains

- blackjack.cpp
- deck.cpp

As you can see, we don't have card.cpp, as everything it needed was trivial, so a .cpp wasn't necessary.

### Tests

Here you can find a test for the blackjack.cpp, where we, well obviously, test that the logic implemented is working, it can be modified and then we run the command to write the executable, which right now is on the repo and can be executed via terminal with the next command: ./test_blackjack
