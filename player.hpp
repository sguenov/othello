#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int calcScore(Board * b, Move *m, Side side);
    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Side ourSide;
    Side otherSide;
    Board *bord;
};

#endif
