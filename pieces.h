#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <string>

class pieces {

public :

	pieces();
	virtual ~pieces();

	virtual bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k); //checks the legality of the move
	void printPiece();

	char getPieceText();
	int getTeam();
	int getId();

protected :

	int teamWhite; //what team the piece is- true is white, false is pink
	char pieceText; //the text for the piece
	int id; //the id of the piece (will be its starting point on the grid)
	int team;

};

#endif