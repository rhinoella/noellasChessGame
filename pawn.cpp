﻿#include "pawn.h"

using namespace std;

//default constructor
pawn::pawn() {

}

//overloaded constructor

	pawn::pawn(int k) {

		id = k;
		moves = 0;

		if (id < 16) {

			teamWhite = 0;
			pieceText = 'P';

		}

		if (id > 16) {

			teamWhite = 1;
			pieceText = 'P';

		}
	
	}

//destructor
pawn::~pawn() {

}

bool pawn::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) {

	//to check whether or not the piece is allowed to move to the selected square
	//the team matters because pawns can only move in the foward direction
	if (turnTeamWhite == 0) {

		if (moves == 0) { //on the first move pawns can move two spaces fowards

			if (selectedSquare == selectedPiece + 8 && teamWhite == 3) {

				moves++;
				bool move = true;
				return move;

			}

			else if (selectedSquare == selectedPiece + 16 && teamWhite == 3) {

				moves++;
				bool move = true;
				return move;

			}

			else {

				bool move = false;
				return move;

			}

		}

		else if (selectedSquare == selectedPiece + 8 && teamWhite == 3) {

			bool move = true;
			return move;

		}

		else if ((selectedSquare == selectedPiece + 7 || selectedSquare == selectedPiece + 9) && teamWhite == 1) { //pawns can only kill diagonal

		bool move = true;
		return move;

		}

		else {

			bool move = false;
			return move;

		}

	}

	else if (turnTeamWhite == 1 ) {


		if (moves == 0) { //on the first move pawns can move two spaces fowards

			if (selectedSquare == selectedPiece - 8 && teamWhite == 3) {
				
				moves++;
				bool move = true;
				return move;

			}

			else if (selectedSquare == selectedPiece - 16 && teamWhite == 3) {
				
				moves++;
				bool move = true;
				return move;
				

			}

			else {

				bool move = false;
				return move;

			}

		}

		else if (selectedSquare == selectedPiece - 8 && teamWhite == 3) {

			bool move = true;
			return move;

		}

		else if ((selectedSquare == selectedPiece - 7 || selectedSquare == selectedPiece - 9) && teamWhite == 0) {

			bool move = true;
			return move;

		}

		else {

			bool move = false;
			return move;

		}

	}


}


