#include "pieces.h"
#include <windows.h>
#include "gui.h"

using namespace std;

pieces::pieces() {

	teamWhite = 3; //0 is white, 1 is pink, 3 is empty
	pieceText = ' ';

}

pieces::~pieces() {

}

bool pieces::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {

	bool move = false;
	return move;

}

int pieces::getId() {

	return id;

}

int pieces::getTeam() {

	return teamWhite;

}

char pieces::getPieceText() {

	return pieceText;

}