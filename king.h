#ifndef KING_H
#define KING_H

#include "pieces.h"

class king : public pieces {

	public :
		king();
		king(int n);

		~king();

		bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) override;

	protected :

};

#endif // !KING_H
