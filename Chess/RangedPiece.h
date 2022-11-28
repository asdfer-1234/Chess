#pragma once
#include "SlidingPiece.h"
class RangedPiece : public SlidingPiece
{
protected:
	int range;
public:
	RangedPiece(Owner owner, bool* image, vector<Vector2>& movement, int range);

	vector<Vector2> GetPossibleMovement(Board& board, Vector2& position);
	
};

