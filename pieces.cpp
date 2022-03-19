#include "pieces.h"
#include <windows.h>
#include "gui.h"

using namespace std;

pieces::pieces() {

	teamWhite = 3; //0 is white, 1 is pink, 3 is empty
	pieceText = ' ';
	team = 15;

}

pieces::~pieces() {

}

bool pieces::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) {

	bool move = false;
	return move;

}


void pieces::printPiece() {

	//for coloured text formatting
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, team);
	cout << getPieceText();

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