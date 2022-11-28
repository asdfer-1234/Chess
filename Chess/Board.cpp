#include "Board.h"
#include "PieceSet.h"
#include <iostream>
#include "PawnPiece.h"
#include "SlidingPiece.h"
#include "RangedPiece.h"

using namespace std;
Board::Board() {
	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			board[y][x] = PieceSet::empty;
		}
	}
}

Board::~Board() {
	
}

Cell* Board::GetPosition(Vector2 position) { // Getter
	if (PositionValid(position)) {
		return board[position.y][position.x];
	}
	return NULL;
}

void Board::SetPosition(Vector2 position, Cell* cell) { //Setter
	
	board[position.y][position.x] = cell;
}
bool Board::PositionValid(Vector2 position) { // Checks if positions is placable in board
	return position.x >= 0 && position.x < boardSize && position.y >= 0 && position.y < boardSize;
}

void Board::ExecuteMove(Move move) { // applies the move
	SetPosition(move.to, GetPosition(move.from));
	SetPosition(move.from, PieceSet::empty);
}
/*
Board& Board::MoveExecuted(Move move)
{
	Board board;
	board.SetBoard(board);
	board.ExecuteMove(move);
	return board;
}

void Board::SetBoard(Board board) {
	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			this->board[y][x] = board.board[y][x];
		}
	}
}
*/
void Board::SetBoard() // Makes Inital positions
{
	for (int i = 0; i < boardSize; i++) {
		SetPosition(Vector2(i, PieceSet::whitePawn->startingRank), PieceSet::whitePawn);
		SetPosition(Vector2(i, PieceSet::blackPawn->startingRank), PieceSet::blackPawn);
	}
	SetPosition(Vector2(0, 0), PieceSet::blackRook);
	SetPosition(Vector2(1, 0), PieceSet::blackKnight);
	SetPosition(Vector2(2, 0), PieceSet::blackBishop);
	SetPosition(Vector2(3, 0), PieceSet::blackQueen);
	SetPosition(Vector2(4, 0), PieceSet::blackKing);
	SetPosition(Vector2(5, 0), PieceSet::blackBishop);
	SetPosition(Vector2(6, 0), PieceSet::blackKnight);
	SetPosition(Vector2(7, 0), PieceSet::blackRook);

	SetPosition(Vector2(0, 7), PieceSet::whiteRook);
	SetPosition(Vector2(1, 7), PieceSet::whiteKnight);
	SetPosition(Vector2(2, 7), PieceSet::whiteBishop);
	SetPosition(Vector2(3, 7), PieceSet::whiteQueen);
	SetPosition(Vector2(4, 7), PieceSet::whiteKing);
	SetPosition(Vector2(5, 7), PieceSet::whiteBishop);
	SetPosition(Vector2(6, 7), PieceSet::whiteKnight);
	SetPosition(Vector2(7, 7), PieceSet::whiteRook);
}
Vector2 Board::GetPiecePosition(Piece* piece) {
	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			if (GetPosition(Vector2(x, y)) == piece) {
				return Vector2(x, y);
			}
		}
	}
}
// some dummy data that could not be implemented
/*
bool Board::TargetsPosition(Owner owner, Vector2 position) {
	for (int y = 0; y < boardSize; y++) {
		for (int x = 0; x < boardSize; x++) {
			Vector2 position = Vector2(x, y);
			if (!(GetPosition(position)->IsEmpty()) && GetPosition(position)->CastToPiece()->owner == owner) {
				for (Vector2 i : GetPosition(position)->CastToPiece()->GetPossibleMovement(*this, position)) {
					if (position == i) {
						return true;
					}
				}
				
			}
		}
	}
	return false;
}



State Board::CheckState(Owner owner) {
	State state;
	Vector2 kingPosition;
	if (owner == Owner::White) {
		kingPosition = GetPiecePosition(PieceSet::whiteKing);
	}
	else {
		kingPosition = GetPiecePosition(PieceSet::blackKing);
	}
	Owner oppositeOwner = owner == Owner::White ? Owner::Black : Owner::White;
	if (TargetsPosition(oppositeOwner, kingPosition)) {
		bool isCheckmate = true;
		for (Vector2 i : GetPosition(kingPosition)->CastToPiece()->GetPossibleMovement(*this, kingPosition)) {
			if (TargetsPosition(oppositeOwner, i)) {
				isCheckmate = false;
			}
		}
		if (isCheckmate) {
			return State::Checkmate;
		}
		else {
			return State::Check;
		}
	}
	return State::Normal;
}
*/