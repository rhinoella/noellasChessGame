#ifndef PAWN_H
#define PAWN_H

#include "pieces.h"
#include <iostream>
#include <string>

class pawn : public pieces {

	public:

		pawn();
		pawn(int k);
		~pawn();

		bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) override;

	protected:

		int moves;

};

#endif
