#ifndef ROOK_H
#define ROOK_H

#include "pieces.h"
#include <iostream>
#include <string>

class rook : public pieces {

public:
	rook();
	rook(int n);

	~rook();

	bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int kk) override;

protected:

};

#endif // !

