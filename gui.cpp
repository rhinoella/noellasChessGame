#include "gui.h"
#include "pawn.h"
#include <windows.h> //winAPI to get coloured text output
#include <string>

using namespace std;

void printGrid(int i) {

	//for coloured text formatting
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (i % 2 == 0) { //an even number corresponds to a grid line that begins with pattern BLACK-GRAY

		for (int j = 0; j < 4; j++) { //pattern printed four times

			SetConsoleTextAttribute(h, 15);
			cout << "     ";
			SetConsoleTextAttribute(h, 143);
			cout << "     ";

		}

		SetConsoleTextAttribute(h, 15);
		cout << "\n";

	}

	if (i % 2 != 0) { //an even number corresponds to a grid line that begins with pattern GRAY-BLACK

		for (int j = 0; j < 4; j++) { //pattern printed four times

			SetConsoleTextAttribute(h, 143);
			cout << "     ";
			SetConsoleTextAttribute(h, 15);
			cout << "     ";

		}

		SetConsoleTextAttribute(h, 15);
		cout << "\n";

	}
	

}

void printGridNum(int i) {

	if (i == 7) {

		cout << "\n  1    2    3    4    5    6    7    8  \n";

	}

}

int calcSelectedPiece(int kk, int ii) {

	int selectedPiece = ((ii - 1) * 8) + kk - 1;
	return selectedPiece;

}



square::square() {

}

void square::setSquareGray(int i, int k) { //sets whether or not the square will be grey or black at the beggining

	if (i % 2 != 0 && k % 2 !=0 || i % 2 == 0 && k % 2 == 0) {

		squareGray = false;

	}

	if (i % 2 != 0 && k % 2 == 0 || i % 2 == 0 && k % 2 != 0) {

		squareGray = true;

	}

}

void square::setOccupantObject(pieces* pointer) {

	occupantObject = pointer;

}

void square::clearSquare(pieces* defaultPiecePtr) {

	setOccupantObject(defaultPiecePtr);

}


pieces* square::getOccupantObject() {

	return occupantObject;

}

//will print the square

void square::printSquare() {
	
	//for coloured text formatting
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int occupantTeamColour = 0;
	
	if (occupantObject->getTeam() == 0) { //if the pieces team is white, the font colour is set to white

		occupantTeamColour = 15;

	}

	if (occupantObject->getTeam() == 1) occupantTeamColour = 13;

	//sets the background colour and prints the square
	if (squareGray == true) {

		SetConsoleTextAttribute(h, occupantTeamColour + 16 * 8);
		cout << "  " << occupantObject->getPieceText() << "  ";

		SetConsoleTextAttribute(h, 15);
	}

	if (squareGray == false) {

		SetConsoleTextAttribute(h, occupantTeamColour);
		cout << "  " << occupantObject->getPieceText() << "  ";

		SetConsoleTextAttribute(h, 15);

	}

}
