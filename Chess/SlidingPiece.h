#pragma once
#include "Piece.h"
#include "Vector2.h"
#include <vector>
using namespace std;



class SlidingPiece : public Piece
{
protected:
	vector<Vector2> movement;
	vector<Vector2> Slide(Board& board, Vector2 position, Vector2& direction, int range = 8);

public:
	SlidingPiece();
	SlidingPiece(Owner owner, bool* image, vector<Vector2>& movement);
	virtual vector<Vector2> GetPossibleMovement(Board& board, Vector2& position);
	
	

};

