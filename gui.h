#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>
#include "allHeadersChess.h"
#include <vector>

void printGrid(int i); //'i' will show how many iterations of the loop- which grid line to print
void printGridNum(int i); //prints the x axis underneath grid
int calcSelectedPiece(int kk, int ii); //calculates the array value of the selected piece depending on the inputted x and y values

class square {

public:
	square();

	void setSquareGray(int i, int k);

	void setOccupantObject(pieces* pointer);
	void clearSquare(pieces* defaultPiecePtr); //will clear the square after a piece has left it

	pieces* getOccupantObject();

	void printSquare(); //a 'square' is a grid line that contains occupying pieces

protected:

	pieces* occupantObject;
	bool squareGray; //the color of the square: true is gray, false is black

};

#endif
