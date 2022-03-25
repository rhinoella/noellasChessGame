#ifndef BISHOP_H
#define BISHOP_H

#include "pieces.h"
#include <iostream>
#include <string>

class bishop : public pieces {

	public :

		bishop();
		bishop(int l);
		~bishop();

		bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) override;

	protected :

};

#endif