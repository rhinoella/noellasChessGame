#ifndef KNIGHT_H
#define KNIGHT_H

#include "pieces.h"
#include <iostream>
#include <string>

class knight : public pieces {

	public :
		knight();
		knight(int n);

		~knight();

		bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) override;

	protected :

};

#endif // !
