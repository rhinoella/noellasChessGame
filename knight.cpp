#include "knight.h"

using namespace std;

//default constructor
knight::knight() {

}

//overloaded constructor

knight::knight(int n) {

	id = n;

	if (id < 16) {

		teamWhite = 0;
		pieceText = 'k';
		team = 15;

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'k';
		team = 13;

	}

}

//destructor
knight::~knight() {

}

bool knight::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {
	//to check whether or not the piece is allowed to move to the selected square

	if ((selectedSquare == selectedPiece - 17 && selectedSquare == selectedPiece - 15 && selectedSquare == selectedPiece - 6 && selectedSquare == selectedPiece - 10 && selectedSquare == selectedPiece + 17 && selectedSquare == selectedPiece + 15 && selectedSquare == selectedPiece + 6 && selectedSquare == selectedPiece + 10) || teamWhite == turnTeamWhite) {

		bool move = false;
		return move;

	}

	else {

		bool move = true;
		return move;

	}

}


