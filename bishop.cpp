#include "bishop.h"

using namespace std;

//default constructor
bishop::bishop() {

}

//overloaded constructor

bishop::bishop(int n) {

	id = n;


	if (id < 16) {

		teamWhite = 0;
		pieceText = 'B';

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'B';

	}

}

//destructor
bishop::~bishop() {

}

//to check whether or not the piece is allowed to move to the selected square

bool bishop::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {

	//to check whether or not the piece is allowed to move to the selected square

	if (((selectedSquare - selectedPiece) % 9 == 0 || (selectedSquare - selectedPiece) % 7 == 0) && teamWhite != turnTeamWhite) {

		bool move = true;
		return move;

	}

	else {

		bool move = false;
		return move;

	}

}