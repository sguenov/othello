// minimax function
// takes in board, returns optimal next move

Move *Player::minimax(Board * b, int msleft) {
	Move * go = nullptr;
	double max = -999999.0;
	for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
		if(msleft < 3000){
					break;
				}
		Move * test = new Move(i, j);
		
		// for every one of our possible moves
		if (b->checkMove(test, ourSide)){
			// hypothetically do the move
			Board * b2 = b->copy();
			b2->doMove(test, ourSide);
			double min = 999999.0;
			
			for (int m = 0; m < 8; m++) {
			for (int n = 0; n < 8; n++) {
				
				Move * test2 = new Move(m, n);
				// then for every one of opponent's next possible moves
				if (b2->checkMove(test2, otherSide)) {
					// hypothetically do the move
					double ourScore = calcOtherScore(b2, test2, otherSide);
					double otherScore = calcScore(b2, test2, otherSide);
					double score = ourScore - otherScore;
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
				go = test;

			}
		}
	}
	}
	return go;
}
