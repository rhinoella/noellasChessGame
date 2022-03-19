#ifndef QUEEN_H
#define QUEEN_H	

#include "pieces.h"
#include <iostream>
#include <string>

class queen : public pieces {

public:
	queen();
	queen(int n);

	~queen();
	bool move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k) override;

protected:

};

#endif // !
