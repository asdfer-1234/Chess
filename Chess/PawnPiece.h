#pragma once
#include <iostream>
#include <vector>
#include "Owner.h"
#include "Piece.h"
#include "Vector2.h"


using namespace std;
class PawnPiece : public Piece
{
	Vector2 movement;
	int startingMovementRange;
	
	int movementRange;
	vector<Vector2> captureMovement;
public:
	int startingRank;
	vector<Vector2> GetPossibleMovement(Board& board, Vector2& position);
	PawnPiece(Owner owner, bool* image, Vector2 movement, vector<Vector2> captureMovement, int startingMovementRange, int movementRange, int startingRank);
};
