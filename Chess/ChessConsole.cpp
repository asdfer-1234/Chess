#include "ChessConsole.h"
#include <iostream>
#include "Piece.h"
#include "PieceSet.h"
#include "Board.h"
#include "Color.h"
#include <Windows.h>
#include <string>
#include "Move.h"
#include "Vector2.h"
using namespace std;

void ChessConsole::PrintBoard() { // Prints the board
	system("cls");
	
	Color image[imageSize][imageSize]; // image format that this program will use
	GenerateBoardImage(image); // generates the image without borders or stuff
	PrintImage(image); // prints it
}

void ChessConsole::PrintBoardWithPossibleMovement(Vector2& position) { // PrintBoard with ui for movable positions
	system("cls");
	Color image[imageSize][imageSize];
	GenerateBoardImage(image);
	if (!(board.GetPosition(position)->IsEmpty())) {
		for (Vector2 i : ((Piece*)board.GetPosition(position))->GetPossibleMovement(board, position)) {
			BorderCell(image, i);
		}
	}
	PrintImage(image);
}


void ChessConsole::PrintImage(Color image[imageSize][imageSize]) // Prints the board
{
	for (int y = 0; y < boardSize * cellSize; y++) {
		for (int x = 0; x < boardSize * cellSize; x++) { // remember to use y first in these kind of print statements

			PrintPixel(image[y][x], GetPixelCharacter(Vector2(x, y)));
		}
		SetColor(Color::Black);
		std::cout << "\n";
	}
}

char ChessConsole::GetPixelCharacter(Vector2 position) { // string coords to vector2
	if (position.x % cellSize == 0 && position.y == imageSize - 1) {
		return 'a' + position.x / cellSize;
	}
	if (position.y % cellSize == 0 && position.x == imageSize - 1) {
		return '1' + 7 - position.y / cellSize;
	}
	return ' ';
}

void ChessConsole::BorderCell(Color image[imageSize][imageSize], Vector2 position) { // borders a cell, only used in printboardwithpossiblemovements()
	Vector2 newPosition = position * cellSize;
	for (int y = 0; y < cellSize; y++) {
		for (int x = 0; x < cellSize; x++) {
			if (x == 0 || y == 0 || x == cellSize - 1 ||	y == cellSize - 1) {
				image[newPosition.y + y][newPosition.x + x] = Color::DBlue;
			}
		}
	}

}


void ChessConsole::GenerateBoardImage(Color image[imageSize][imageSize]) // makes the image for the board. borders not included
{
	for (int y = 0; y < boardSize; y++) for (int x = 0; x < boardSize; x++) { // Nested for loops in an interesting and somewhat readable way
		bool isEmpty = board.GetPosition(Vector2(x, y))->IsEmpty();

		for (int cy = 0; cy < cellSize; cy++) for (int cx = 0; cx < cellSize; cx++) {

			Color* currentPixel = &image[y * cellSize + cy][x * cellSize + cx];
			if (!isEmpty && ((Piece*)board.GetPosition(Vector2(x, y)))->image[cy][cx]) {
				*currentPixel = ((Piece*)board.GetPosition(Vector2(x, y)))->owner == Owner::White ? Color::White : Color::Black;
			}
			else {
				*currentPixel = (x + y) % 2 == 0 ? Color::DYellow : Color::DMagenta;
			}
		}
	}
}



void ChessConsole::PrintPixel(Color color, char character) { // prints a pixel with color and character
	SetColor(color, Color::White);
	printf("%c", character);
}

void ChessConsole::ResetConsole() { // init stuff
	system(" mode  con lines=60   cols=56 ");
	SetColor(Color::Black, Color::LGray);
}

bool ChessConsole::AskMove(Owner owner) { // asks the move. the main function
	
	std::cout << (owner == Owner::White ? "White" : "Black") << "'s turn :";

	Move askedMove;
	
	if (!AskCoordinate(askedMove.from)) {
		PrintBoard();
		std::cout << "Coordinate Invalid\n";
		return false;
	}

	if (board.GetPosition(askedMove.from)->IsEmpty()) {
		PrintBoard();
		std::cout << "Cannot move an empty piece\n";
		return false;
	}

	if (((Piece*)(board.GetPosition(askedMove.from)))->owner != owner) {
		PrintBoard();
		std::cout << "You do not own that piece\n";
		return false;
	}

	PrintBoardWithPossibleMovement(askedMove.from);

	if (!AskCoordinate(askedMove.to)) {
		PrintBoard();
		std::cout << "Coordinate Invalid\n";
		return false;
	}

	bool isMovable = false;

	for (Vector2& i : ((Piece*)board.GetPosition(askedMove.from))->GetPossibleMovement(board, askedMove.from)) {
		if (i == askedMove.to) {
			isMovable = true;
			break;
		}
	}
	if (!isMovable) {
		PrintBoard();
		std::cout << "Cannot move there\n";
		return false;
	}

	Owner winner;
	bool isWin = false;

	if (board.GetPosition(askedMove.to) == (Cell*)PieceSet::blackKing) {
		isWin = true;
		winner = Owner::White;
		
	}
	else if (board.GetPosition(askedMove.to) == (Cell*)PieceSet::whiteKing) {
		isWin = true;
		winner = Owner::Black;
		
	}

	board.ExecuteMove(askedMove);
	PrintBoard();
	if (isWin) {
		if (winner == Owner::White) {
			std::cout << "White Wins!\n";
		}
		else {
			std::cout << "Black Wins!\n";
		}
	}
	

	

	
	return true;	
}

bool ChessConsole::AskCoordinate(Vector2& out) { // asks a coord
	string input;
	cin >> input;
	if (input == "quit") {
		exit(0);
	}
	return Vector2FromCoords(input, out);
}

bool ChessConsole::Vector2FromCoords(string& coords, Vector2& out) { // coord string to vector2
	Vector2 returnVector;
	if (coords.length() == 2) {
		returnVector.x = coords[0] - 97;
		returnVector.y = 7 - (coords[1] - 49);
		if (board.PositionValid(returnVector)) {
			out = returnVector;
			return true;
		}
	}
	return false;
}

void ChessConsole::SetColor(Color background, Color foreground, HANDLE handle) { // basically setconsoletextattribute but in a fancy and convineint way
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static int currentColorInt = (int)Color::LGray;
	int colorInt = GetColorInt(background, foreground);
	if (handle != NULL) {
		hConsole = handle;
	}

	if (currentColorInt != colorInt) {
		SetConsoleTextAttribute(hConsole, colorInt);
		currentColorInt = colorInt;
	}

}

int ChessConsole::GetColorInt(Color background, Color foreground) { // colors into bg and fg
	return (int)background * 16 + (int)foreground;
}


void ChessConsole::Play() { // basically main() but in chessconsole
	ResetConsole();

	board.SetBoard();
	PrintBoard();
	for (bool i = true;; i = AskMove(i ? Owner::White : Owner::Black) ? !i : i);
		
}