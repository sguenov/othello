#include "board.hpp"
int Cscore(Board * b, Move *m, Side side){
	Board * board = b->copy();
	board->doMove(m, side);
	int cnt = board->count(side);
	return cnt;
}