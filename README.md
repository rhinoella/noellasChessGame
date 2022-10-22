
# CLI Chess Game
University of Reading Programming Final Project

## Specifications:

The aim of this program was to create a C++ console-run, multiplayer chess game that maintained the simplicity of playing chess on a physical board. Chess is a two-player board game that takes place on an eight by eight grid with sixteen chess pieces of different types on each team. This game follows the rule of early Sanskrit chess in which a team is victorious when they capture the opponent’s king by landing on the square it occupies. These chess rules were chosen because it is how I was taught by my father and I wanted to recreate how we played. Chess was chosen because the game is quite complex and provided a challenge.

This program was designed to include the most fundamental rules of chess:

 - Pawns can only move forwards by one square, except on their first move where 
   there is the option to move two squares
 - Pawns can only capture other pieces diagonally
 - Rooks can only move horisontally or vertically
 - Knights can only move in an ‘L’ shape
 - Bishops can only move diagonally
 - Queens can move in any direction
 - Kings can move only one square in any direction
 - All pieces except knights cannot jump over other pieces
 - Players can only capture pieces on the opposing team
 - If a pawn reaches the opposite side of the board, they can be promoted to any piece 
   except a king
 - A team is victorious if they capture the other team’s king
 
Additionally, the program required certain features so that it could be a playable game:

 - A chequered grid must be printed out to the console
 - There must be a clear way to differentiate between the piece’s team
 - The user must be able to select a piece and its movement, the legality of this must be 
   checked as well
 - The game must alternate between players
 - The piece’s movement must be outputted on the console
 
 Here is a flow chart of how the program was planned to work:
 
 ![program flow chart](https://i.imgur.com/5DpWI4w.png)
 
 
## Subroutines

### Verifying Moves
One of the program requirements was that it would have a form of rule moderation to check and confirm the legality 
of a player’s move. One factor of legality is checking if there are any pieces that are obstructing another piece’s 
move- only the Knights can jump over other pieces. To design this subroutine, a plan was needed for the layout of 
the grid. The figure below illustrates the layout of the chess board. Each square is numbered n corresponding to 
their index (n - 1) in the ‘square’ array. 

![chess board numbering system](https://i.imgur.com/NaepM3J.png)

A formula that detected each type of move (diagonal, vertical and horisontal) was created. For example, a diagonal 
northwest/southeast movement could be detected by checking if the remainder of the number of the selected piece 
subtracted from the number of the selected square divided by nine was zero. Then, depending on which type of move it 
was, a ‘for’ loop would need to iterate through every square following that movement to check if there is an 
obstructing piece. For checking if the move is legal to a piece (i.e. Bishops can only move diagonal), these same 
formulas for detecting the type of move could be used.

![flow chart that illustrates move checking routine](https://i.imgur.com/N9uTWXL.png)


### User Input Verification
 
This program aimed to have better error-handling than current console chess games. To achieve this, a subroutine was 
designed to handle all user inputs to check if they were of the correct value range and of the correct datatype. 
After every user input, a loop was designed that would check for these errors and only allow the input loop to break 
if the user entered an acceptable value. 


## Development

### Classes

The first step in development was to create the classes. There were eight classes total: a general class for the 
pieces, six specific piece classes and a class for the squares. The general ‘pieces’ class contained the functions 
and data that was universal for every chess piece (their team, their id, their text etc.) and a virtual function: 
‘move’. This class was necessary because it allowed the program to use pointers to the base class as a reference to 
a derived object. Therefore, instead of writing multiple of the same procedures for each derived class, only one of 
each is needed. 

The six derived classes each contained their own constructor that set their text symbol and their team, as well as a 
function called ‘move’ (determines if the move is legal to that piece) that overrides the same function in the base 
class. This use of function overriding means that only one call to ‘move’ was needed in the main and depending on 
which class the pointer that is calling the function belongs to, the program will dynamically call the specific 
function for that class.  

The last class in the program was the class for the squares. It was decided that the data contained in each square 
would be dealt with using a class rather than another structure (i.e. arrays) due to the fact that the squares were 
assigned the responsibility of formatting (containing information needed for the text colour and highlighting) as 
well as containing pointers to pieces. Therefore, the use of objects allowed for more efficient data handling.

![UML Class diagram](https://i.imgur.com/LpNEjB3.png)


### User Interface

Creating an appealing user interface was one of the core requirements for this project. Some existing programs that were reviewed utilised ASCII characters to create the white squares, however this method has significant limitations. The text itself are unable to be highlighted and therefore always have black backgrounds even on a white square. It was decided that instead of this method, the Windows API would be utilised, with the drawback of the code being platform-dependent to the Windows operating system.

```
void square::printSquare() {
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int occupantTeamColour = 0;
	
	if (occupantObject->getTeam() == 0) { //if the pieces team is white, the font 	colour is set to white

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

```


### Game Mechanics

After the array index of the selected piece was calculated, it was passed into the ‘square’ array to locate the 
piece’s pointer. Two ‘if’ statements then confirmed that the user did not select an empty square, and that they 
selected a piece on their team. When these were confirmed, the outer loop that contained each set of input stages 
(selecting the piece or selecting the move) broke, and the program proceeded to the next process of verifying the 
move.

Chess pieces each have their own set of rules that determine how they can move. Instead of creating a separate 
function in the main for each piece, this program took advantage of C++’s polymorphism ability and created a virtual 
‘move’ function in the ‘pieces’ class that was inherited and overridden for each derived class. 

```
moveLegal = square[selectedPiece].getOccupantObject()->move(selectedPiece, selectedSquare, teamWhite, turnTeamWhite, 
            i, k, ii, kk);
```

The move function checked the move to see if it was legal (i.e. a bishop can 
only move diagonally) and it ensured that the piece is not moving onto a square that is already occupied by a piece 
on its team. This code snippet above displays the call to the ‘move’ function in the main. Below is the overridden 
function definition for the ‘bishop’ class.

```
bool bishop::move(int selectedPiece, int selectedSquare, int teamWhite, int turnTeamWhite, int i, int k, int ii, int 
                  kk) {

	if (((selectedSquare - selectedPiece) % 9 == 0 || (selectedSquare - selectedPiece) % 7 == 0) && 	teamWhite !=    
      turnTeamWhite) {

		bool move = true;
		return move;

	}

	else {

		bool move = false;
		return move;

	}

}

```

During the process of development, variables were localised to routines as much as possible. This aided in increasing the readability of the code and avoided naming conflicts. The entirety of the move selection and verification process was contained inside of a ‘do while’ loop. Once the move was verified, the loop broke and the process of moving the piece begun.

To move the piece, the program first had to recognise what type of move it was. There were three different possibilities with three different outcomes: 
  1. The piece is landing on a square that is occupied by the other team’s king, leading to a victory. 
  2. The piece is a pawn, and it has reached the other side, meaning it can be promoted to any piece
  3. The piece is making a regular move

```
if (square[selectedSquare].getOccupantObject()->getTeam() != turnTeamWhite && square[selectedSquare].getOccupantObject()->getPieceText() == 'K')
				
else if ((square[selectedPiece].getOccupantObject()->getPieceText() == 'P' && selectedSquare > 55) || (square[selectedPiece].getOccupantObject()->getPieceText() == 'P'&& selectedSquare < 8))
				
else //...
```

‘If’ statements (shown above) were written to detect the type of move a piece was making. Each condition contained 
the same routine to move a piece. After selecting the square that a piece would move to, its pointer was added to 
the ‘square’ object at that position. Then, in the ‘square’ object that previously held that piece, the pointer it 
held was replaced to a pointer to a blank piece object. If the first condition was true, the program would terminate 
and output the winning team. If the second condition was true, the user was prompted to choose a piece to promote 
the pawn to. Once the user made their decision, a new object of that piece class was constructed. The pointer to the 
pawn would then be replaced to the pointer for this newly constructed object. Using pointers greatly simplified the 
development of this process as pieces and all their data could be moved throughout the squares with ease. 
Furthermore, the use of pointers allowed member functions to be called dynamically without having to specifically 
mention the object that the function belonged to.



## Conclusion and Reflection

This project allowed for the opportunity to reinforce good programming practises such as minimising variable scope 
whenever possible, using files to separate classes, utilising pointers, function overriding and reducing the 
probability of user error. Initially during the development, arrays were used to store the objects, however this 
caused some difficulties in calling the overloaded constructor. Using arrays to do this was more complicated and 
inefficient, therefore vectors were learned and utilised. Furthermore, at the beginning, pointers were a difficult 
subject to understand and were avoided. However, this caused issues after it was discovered that objects could not 
store other objects within them, rather they could only store pointers to objects. This discovery resulted in 
further exploration surrounding pointers and allowed them to be implemented in this program.

In retrospect, if this program were to be redone in the future, certain changes should be made to improve the code. 
Firstly, there was no need to create separate vectors for each piece type, as this just cluttered the code. Using 
one vector to hold all the pieces would be more efficient. Secondly, the use of a 2D array to store the ‘square’ 
objects on would create a more readable code. Rather than having to decipher all the formulas and the use of 1D and 
2D coordinates, it would have been easier if the program had kept a consistent coordinate system. Overall, this 
project provided a challenge and an opportunity to learn new skills in C++ and was successful and satisfied all its 
requirements. 
