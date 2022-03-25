#include "allHeadersChess.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

int main() {

	bool done = false;
	int promotedPawns = 4;

	//creating 64 square objects
	square square[64];

	//setting the colour of each square
	for (int i = 0; i < 8; i++) { //i is the vertical axis

		for (int k = 0; k < 8; k++) { //k is the horisontal axis

			int l = (((i + 1) - 1) * 8) + (k + 1) - 1; //formula for l (square array index) as a function of k and i
			square[l].setSquareGray(i, k);

		}

	}

	//filling the squares with default occupants
	pieces defaultPiece;
	pieces* defaultPiecePtr = &defaultPiece;

	for (int l = 16; l < 48; l++) {

		square[l].setOccupantObject(defaultPiecePtr);

	}

	//creating the pieces - using a vector so i can call on overloaded constructor
	vector<pawn> pawnVector;
	for (int l = 0; l < 16; l++) {

		int k = 0;

		if (l < 8) {
		
			k = l + 8;
			pawnVector.push_back(pawn(k));
		
		}

		else if (l >= 8) {
		
			k = l + 40;
			pawnVector.push_back(pawn(k)); 

		}
		
	}

	vector<bishop> bishopVector(16); //the values are their starting positions- calls the overloaded constructor
	bishopVector[0] = bishop(2);
	bishopVector[1] = bishop(5);
	bishopVector[2] = bishop(58);
	bishopVector[3] = bishop(61);
	vector<knight> knightVector(16);
	knightVector[0] = knight(1);
	knightVector[1] = knight(6);
	knightVector[2] = knight(57);
	knightVector[3] = knight(62);
	vector<rook> rookVector(16);
	rookVector[0] = rook(0);
	rookVector[1] = rook(7);
	rookVector[2] = rook(56);
	rookVector[3] = rook(63);
	vector<queen> queenVector(16);
	queenVector[0] = queen(4);
	queenVector[1] = queen(60);
	king whiteKing(3), pinkKing(59);

	//putting the pieces on their starting positions and setting their font colours, storing the pointers to the object

	for (int k = 0; k < 4; k++) { //knights, bishops and rooks

		int l = knightVector[k].getId();
		square[l].setOccupantObject(&knightVector[k]);
		l = bishopVector[k].getId();
		square[l].setOccupantObject(&bishopVector[k]);
		l = rookVector[k].getId();
		square[l].setOccupantObject(&rookVector[k]);

	}

	//queens
	for (int k = 0; k < 2; k++) {

		int l = queenVector[k].getId();
		square[l].setOccupantObject(&queenVector[k]);


	}
	
	square[whiteKing.getId()].setOccupantObject(&whiteKing);
	square[pinkKing.getId()].setOccupantObject(&pinkKing);


	for (int k = 8; k < 16; k++) { //pawns

		int l = k - 8;
		square[k].setOccupantObject(&pawnVector[l]);

	}

	for (int k = 48; k < 56; k++) {

		int l = k - 40;
		square[k].setOccupantObject(&pawnVector[l]);

	}

	int rounds = 1;

	bool startgame = false;

	do {

		int x = 0;
		cout << "Welcome to chess!" << endl;
		cout << "Typing '111' in the move select menu will allow you to reselect a piece" << endl;
		cout << "Typing '222' in the move select menu will allow you to terminate the program\n" << endl;
		cout << "Type 1 to start the game\n\n" << endl;
		
		//waiting for the user to type 1 to start
		while (x != 1) {

			if (cin >> x) {

				if (x == 1) {

					startgame = true;
					cout << "Game started.\n\n";

				}
				else {

					cout << "\nInvalid input, try again:\n\n";
					cin.clear();
					cin.ignore(100, '\n');

				}

			}

			else { //if the user types something that is not of int datatype

				cout << "\nInvalid input, try again:\n\n";
				cin.clear();
				cin.ignore(100, '\n');

			}

		}

	}

	while (startgame == false);

start:

	while (done == false) {

		string turnTeam;
		int turnTeamWhite;

		if (rounds % 2 != 0) { //every even round is team white's turn

			turnTeam = "white";
			turnTeamWhite = 0;

		}

		else {

			turnTeam = "pink";
			turnTeamWhite = 1;

		}

		//printing the grid
		for (int i = 0; i < 8; i++) { //i for vertical axis

			printGrid(i); //prints the first line of the squares

			for (int k = 0; k < 8; k++) { //k represents the horisontal axis

				int l = (((i + 1) - 1) * 8) + (k + 1) - 1; //formula for l (square array index) as a function of k and i
				square[l].printSquare(); //prints the middle line of the squares (that contains the chess piece)

			}

			cout << "  " << i + 1 << "\n";

			printGrid(i); //prints the last line of the squares
			printGridNum(i); //prints the numbers at the bottom

		}

		bool roundDone = false;

		while (roundDone == false) {

			int i = 0;
			int k = 0;
		
			bool teamSelectDone = false;
			int selectedPiece = 0;
			int selectedSquare = 0;

			while (teamSelectDone == false) {

				int ii = 0;
				int kk = 0;

				bool pieceXSelectDone = false;

				while(pieceXSelectDone == false) {

					while (kk == 0) {

						cout << "\nTeam " << turnTeam << ", enter the X value of the piece you want to move : " << flush;
						
						if (cin >> kk) {

							if (kk > 8 && kk != 222) { //if the input is higher that 8 (not possible)

								cout << "\nThe values cannot be higher than 8, try again\n\n";
								kk = 0;

							}

							else if (kk == 222) { //will terminate the program

								goto end;

							}

							else pieceXSelectDone = true;

						}

						else { //if the user types something that is not of int datatype

							cout << "\nInvalid input, try again.\n";
							cin.clear();
							cin.ignore(100, '\n');
							

						}

					}

				}

				bool pieceYSelectDone = false;

				while (pieceYSelectDone == false) {

					while (ii == 0) {

						cout << "Team " << turnTeam << ", enter the Y value of the piece you want to move : " << flush;

						if (cin >> ii) {

							if (ii > 8 && ii != 222) { //if the input is higher that 8 (not possible)

								cout << "\nThe values cannot be higher than 8, try again\n\n";
								ii = 0;

							}

							else if (ii == 222) { //will terminate the program

								goto end;

							}

							else pieceYSelectDone = true;

						}

						else { //if the user types something that is not of int datatype

							cout << "\nInvalid input, try again.\n";
							cin.clear();
							cin.ignore(100, '\n');

						}

					}

				}

				selectedPiece = calcSelectedPiece(kk, ii);

				k = kk;
				i = ii;

				//checking to see if the piece is on the player's team

				if ((square[selectedPiece].getOccupantObject()->getTeam() != turnTeamWhite) && (square[selectedPiece].getOccupantObject()->getTeam() != 3)) {

					cout << "\nCannot move a piece on a different team\n\n";

				}

				//checking to see if the square is empty

				else if (square[selectedPiece].getOccupantObject()->getTeam() == 3) {

					cout << "\nThis square is empty, try again.\n\n";

				}

				else teamSelectDone = true;

			}

			bool moveNotObstructed = false;
			bool moveLegal = false;
			bool moveCheck = false;

		selectMove:
			do {

				int ii = 0;
				int kk = 0;

				bool moveXSelectDone = false;

				while (moveXSelectDone == false) {

					while (kk == 0) {

						cout << "Team " << turnTeam << ", enter the X value of the square you want to move the piece to : " << flush;

						if (cin >> kk) {

							if (kk > 8 && kk != 111 && kk != 222) { //if the input is higher that 8 (not possible)

								cout << "\nThe values cannot be higher than 8, try again\n\n";
								kk = 0;

							}

							else if (kk == 222) { //will terminate the program

								goto end;

							}

							else if (kk == 111) { //this will allow for the player to restart and go back to the piece selection process


								goto start;

							}

							else moveXSelectDone = true;

						}

						else { //if the user types something that is not of int datatype

							cout << "\nInvalid input, try again.\n";
							cin.clear();
							cin.ignore(100, '\n');

						}

					}

				}
				
				bool moveYSelectDone = false;

				while (moveYSelectDone == false) {

					while (ii == 0) {

						cout << "Team " << turnTeam << ", enter the Y value of the square you want to move the piece to : " << flush;

						if (cin >> ii) {

							if (ii > 8 && ii != 111 && ii != 222) { //if the input is higher that 8 (not possible)

								cout << "\nThe values cannot be higher than 8, try again\n\n";
								ii = 0;

							}

							else if (ii == 222) { //will terminate the program

								goto end;

							}
							
							else if (ii == 111) { //this will allow for the player to restart and go back to the piece selection process


								goto start;

							}

							else moveYSelectDone = true;

						}

						else { //if the user types something that is not of int datatype

							cout << "\nInvalid input, try again.\n";
							cin.clear();
							cin.ignore(100, '\n');

						}

					}

				}

				selectedSquare = calcSelectedPiece(kk, ii);

				int id = square[selectedPiece].getOccupantObject()->getId();
				char pieceText = square[selectedPiece].getOccupantObject()->getPieceText();

				//checking if there are obstructions in the path for all pieces that can move more than one square at a time and that they are moving more than one square
				if ((pieceText == 'P' || pieceText == 'Q' || pieceText == 'R' || pieceText == 'B') && abs(ii - i) != 1 && abs(kk - k) != 1) { //abs()- absolute value function

					//diagonal movements
					if ((selectedSquare - selectedPiece) % 9 == 0) {

						if (selectedSquare > selectedPiece) {

							for (int l = 1; l < (ii - i); l++) {

								if (square[selectedPiece + (9 * l)].getOccupantObject()->getTeam() < 3) { //if there is a piece blocking the move, the move is prevented

									moveNotObstructed = false;
									break;

								}

								else if (l == ii - i - 1) { //if the iterator gets to the end without the loop breaking, there are no pieces blocking 

									moveNotObstructed = true;

								}


							}


						}

						else {

							for (int l = 1; l < (i - ii); l++) {

								if (square[selectedPiece + (-9 * l)].getOccupantObject()->getTeam() < 3) {

									moveNotObstructed = false;
									break;

								}

								else if (l == i - ii - 1) {

									moveNotObstructed = true;
									
								}

							}
						}

					}

					//diagonal leftward movements
					else if ((selectedSquare - selectedPiece) % 7 == 0) {

						if (selectedSquare > selectedPiece) {

							for (int l = 1; l < (ii - i); l++) {

								if (square[selectedPiece + (7 * l)].getOccupantObject()->getTeam() < 3) { //if there is a piece blocking the move, the move is prevented

									moveNotObstructed = false;
									break;

								}

								else if (l == ii - i - 1) { //if the iterator gets to the end without the loop breaking, there are no pieces blocking 

									moveNotObstructed = true;

								}

							}

						}

						else {

							for (int l = 1; l < (i - ii); l++) {

								if (square[selectedPiece + (-7 * l)].getOccupantObject()->getTeam() < 3) {

									moveNotObstructed = false;
									break;

								}

								else if (l == i - ii - 1) {

									moveNotObstructed = true;

								}

							}

						}

					}

					//horizontal movements
					else if (i == ii) { 

						if (selectedSquare > selectedPiece) {

							for (int l = selectedPiece + 1; l < selectedSquare; l++) {

								if (square[l].getOccupantObject()->getTeam() < 3) {

									moveNotObstructed = false;
									break;

								}

								else if (l == selectedSquare - 1) moveNotObstructed = true;


							}

						}

						else {

							for (int l = selectedPiece - 1; l > selectedSquare; l--) {

								if (square[l].getOccupantObject()->getTeam() < 3) {

									moveNotObstructed = false;
									break;

								}

								else if (l == selectedSquare + 1) moveNotObstructed = true;

							}

						}

					}

					//for vertical movements
					else if (k == kk) {  

					if (selectedSquare > selectedPiece) {

						for (int l = 1; l < ii - i; l++) {

							if (square[selectedPiece + (l * 8)].getOccupantObject()->getTeam() < 3) {

								moveNotObstructed = false;
								break;

							}

							else if (l == ii - i - 1) moveNotObstructed = true;

						}
					}

					else if (selectedSquare < selectedPiece) {

						for (int l = 1; l < i - ii; l++) {

							if (square[selectedPiece - (l * 8)].getOccupantObject()->getTeam() < 3) {

								moveNotObstructed = false;
								break;

							}

							else if (l == i - ii - 1) moveNotObstructed = true;

						}

					}

				}

				}
				else moveNotObstructed = true;

				int teamWhite = square[selectedSquare].getOccupantObject()->getTeam();
				moveLegal = square[selectedPiece].getOccupantObject()->move(selectedPiece, selectedSquare, teamWhite, turnTeamWhite, i, k, ii, kk);

				if (moveNotObstructed == false) {

					cout << "\nThe move is obstructed by another piece, try again.\n\n";

				}

				else if (moveLegal == false) {

					cout << "\nCannot move piece there, try again.\n\n";

				}

				moveCheck = moveNotObstructed && moveLegal;

			}
		
			while (moveCheck == false);

			//doing the approved movements

			//if the move kills the king::
			if (square[selectedSquare].getOccupantObject()->getTeam() != turnTeamWhite && square[selectedSquare].getOccupantObject()->getPieceText() == 'K') {

				square[selectedSquare].setOccupantObject(square[selectedPiece].getOccupantObject()); //moving the object
				square[selectedPiece].clearSquare(defaultPiecePtr); //clearing the square the piece was just on

				cout << "\n" << turnTeam << " team victory! ";

				roundDone = true;
				done = true;

			}

			//if a pawn reaches the other side

			else if ((square[selectedPiece].getOccupantObject()->getPieceText() == 'P' && selectedSquare > 55) || (square[selectedPiece].getOccupantObject()->getPieceText() == 'P' && selectedSquare < 8)) {

				square[selectedSquare].setOccupantObject(square[selectedPiece].getOccupantObject()); //moving the object
				square[selectedPiece].clearSquare(defaultPiecePtr); //clearing the square the piece was just on

				int pawnChoice = 5;
				
				bool pawnSelectDone = false;

				while (pawnSelectDone == false) {

					while (pawnChoice == 5) {

						cout << "Your pawn has reached the other side. You may now turn it into any type of piece.\n0 : remain a pawn\n1 : queen\n2 : bishop\n3 : knight\n4 : rook\nEnter the number of your choice : \n" << flush;

						if (cin >> pawnChoice) {

							if (pawnChoice > 4) { //if the input is higher that 4 (not possible)

								cout << "\nThe value cannot be higher than 4, try again\n\n";
								pawnChoice = 5;

							}

							else pawnSelectDone = true;

						}

						else { //if the user types something that is not of int datatype

							cout << "\nInvalid input, try again.\n";
							cin.clear();
							cin.ignore(100, '\n');

						}

					}

				}


				if (pawnChoice == 0) {

					rounds++;
					roundDone = true;

				}

				else if (pawnChoice == 1) {

					int l = square[selectedSquare].getOccupantObject()->getId();
					queenVector[promotedPawns] = queen(l);
					square[selectedSquare].setOccupantObject(&queenVector[promotedPawns]);
					promotedPawns++;
					rounds++;
					roundDone = true;

				}

				else if (pawnChoice == 2) {

					int l = square[selectedSquare].getOccupantObject()->getId();
					bishopVector[promotedPawns] = bishop(l);
					square[selectedSquare].setOccupantObject(&bishopVector[promotedPawns]);
					promotedPawns++;
					rounds++;
					roundDone = true;

				}

				else if (pawnChoice == 3) {

					int l = square[selectedSquare].getOccupantObject()->getId();
					knightVector[promotedPawns] = knight(l);
					square[selectedSquare].setOccupantObject(&knightVector[promotedPawns]);
					promotedPawns++;
					rounds++;
					roundDone = true;

				}

				else if (pawnChoice == 4) {

					int l = square[selectedSquare].getOccupantObject()->getId();
					rookVector[promotedPawns] = rook(l);
					square[selectedSquare].setOccupantObject(&rookVector[promotedPawns]);
					promotedPawns++;
					roundDone = true;

				}

				
		
			}

			// default move:
			else {
				
				square[selectedSquare].setOccupantObject(square[selectedPiece].getOccupantObject()); //moving the object
				square[selectedPiece].clearSquare(defaultPiecePtr); //clearing the square the piece was just on
				rounds++;
				roundDone = true;

			}


		}


	}

	end :
	cout << "Program finished.\n\n";
	return 0;
}