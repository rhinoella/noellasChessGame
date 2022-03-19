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
		team = 15;

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'R';
		team = 13;

	}

}

//destructor
rook::~rook() {

}

bool rook::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {
	//to check whether or not the piece is allowed to move to the selected square

	if (( selectedSquare > 8 * i && selectedSquare < ((i - 1) * (8)) + 1 && selectedSquare - selectedPiece % 8 != 0) || teamWhite == turnTeamWhite) {

		bool move = false;
		return move;

	}

	else {

		bool move = true;
		return move;

	}

}
