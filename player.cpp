#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    bord = new Board();
    ourSide = side;
    if(ourSide == WHITE){
        otherSide = BLACK;
    }
    if(ourSide == BLACK){
        otherSide = WHITE;
    }
    std::cerr << "blah" << std::endl;
	//hi this is to commit
    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {

    delete bord;

}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    bord->doMove(opponentsMove, otherSide);
    int maxScore = 0;
    Move * currentbest = nullptr;
    int score = 0;
    std::cerr << "moving" << std::endl;
    //while(msLeft > 0){
        for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            score = 0;
            Move * current =  new Move(i,j);
            if (bord->checkMove(current, ourSide)){
                if((i == 0 or i == 7) and (j == 0 or j == 7)){
                    score += 3;
                }
                else if((i == 0 or i == 7)  or (j == 0 or j == 7)){
                    score += 2;
                }
                else if((i == 1 or i == 6)  and (j == 1 or j == 6)){
                    score -= 3;
                }
                else if((i == 1 or i == 6)  or (j == 1 or j == 6)){
                    score -= 2;
                }
                else{
                    std::cerr << "yyy" << std::endl;
                    score += 1;
                }
                if(score > maxScore){
                    maxScore = score;
                    currentbest = current;
                    std::cerr << "move picked" << std::endl;
                }

            }
            //delete current;
            }}

    //}
    if(currentbest == nullptr){
        return nullptr;
    }
    else{
    std::cerr << maxScore << std::endl;
    std::cerr << currentbest->getX() << std::endl;
    std::cerr << currentbest->getY() << std::endl;
    std::cerr << "check valid" << bord->checkMove(currentbest, ourSide) << std::endl;
    bord->doMove(currentbest, ourSide);
    //delete currentbest;
    return currentbest;}
}
