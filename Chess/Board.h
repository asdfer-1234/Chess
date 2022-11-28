#pragma once
#include "Cell.h"
#include "Vector2.h"
#include "Move.h"
#include "State.h"
#include "Owner.h"
#include "Piece.h"
#define boardSize 8
class Board
{
private:
	Cell* board[boardSize][boardSize];
public:
	Board();
	~Board();
	Cell* GetPosition(Vector2 position);
	void SetPosition(Vector2 position, Cell* cell);
	bool PositionValid(Vector2 position);
	void ExecuteMove(Move move);
	Board& MoveExecuted(Move move);

	void SetBoard();
	//void SetBoard(Board board);
	Vector2 GetPiecePosition(Piece* piece);
	//State CheckState(Owner owner);
	//bool TargetsPosition(Owner owner, Vector2 position);
	
};

