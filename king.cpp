#include "king.h"

using namespace std;

//default constructor
king::king() {

}

//overloaded constructor

king::king(int n) {

	id = n;

	if (id < 16) {

		teamWhite = 0;
		pieceText = 'K';
		team = 15;

	}

	if (id > 16) {

		teamWhite = 1;
		pieceText = 'K';
		team = 13;

	}

}

//destructor
king::~king() {

}

bool king::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {
	//to check whether or not the piece is allowed to move to the selected square

	if (((selectedSquare - selectedPiece) == 9 || (selectedSquare - selectedPiece) == 7 || (selectedSquare - selectedPiece) == -9 || (selectedSquare - selectedPiece) == -7 || selectedSquare == (selectedPiece + 1) || selectedSquare == (selectedPiece - 1)) && teamWhite != turnTeamWhite) {

		bool move = true;
		return move;

	}

	else {

		bool move = false;
		return move;

	}

}

