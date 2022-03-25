#include "rook.h"

using namespace std;

//default constructor
rook::rook() {

}

//overloaded constructor

rook::rook(int n) {

	id = n;

	if (id < 16) {

		teamWhite = 0;
		pieceText = 'R';

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'R';

	}

}

//destructor
rook::~rook() {

}

bool rook::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) {
	//to check whether or not the piece is allowed to move to the selected square

	if ((ii == i || kk == k) && teamWhite != turnTeamWhite) {

		bool move = true;
		return move;

	}

	else{

		bool move = false;
		return move;

	}

}
