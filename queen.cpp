#include "queen.h"

using namespace std;

//default constructor
queen::queen() {

}

//overloaded constructor

queen::queen(int n) {

	id = n;

	if (id < 16) {

		teamWhite = 0;
		pieceText = 'Q';

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'Q';

	}

}

//destructor
queen::~queen() {

}

bool queen::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) {

	//to check whether or not the piece is allowed to move to the selected square

	if (((selectedSquare - selectedPiece) % 9 != 0 && (selectedSquare - selectedPiece) % 7 != 0 && selectedSquare > (8 * i) && selectedSquare < ((i - 1) * (8)) + 1 && (selectedSquare - selectedPiece) % 8 != 0 ) || teamWhite == turnTeamWhite) {

		bool move = false;
		return move;

	}

	else {

		bool move = true;
		return move;

	}

}

