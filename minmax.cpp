// minimax function
// takes in board, returns optimal next move

Move *Player::minimax(Board * b) {
	Move * go = new Move(0, 0);
	int max = -999999;
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
		Move * test = new Move(i, j);
		
		// for every one of our possible moves
		if (b->checkMove(test, ourSide)){
			// hypothetically do the move
			Board * b2 = b->copy();
			b2->doMove(test, ourSide);
			int min = 999999;
			
			for (int m = 0; m < 8; m++) {
			for (int n = 0; n < 8; n++) {
				Move * test2 = new Move(m, n);
				// then for every one of opponent's next possible moves
				if (b2->checkMove(test2, otherSide)) {
					// hypothetically do the move
					Board * b3 = b2->copy();
					b3->doMove(test2, otherSide);
					// check our final score after opponent's move
					int score = b3->count(ourSide) - b3->count(otherSide);
					// find the minimum score of the branch
					if (score < min) {
						min = score;
					}
				}
			}
			}
			
			// find the highest minimum score from our possible moves
			// this is the move we want
			if (min > max) {
				max = min;
				go->x = i;
				go->y = j;
			}
		}
	}
	}
	return go;
}
