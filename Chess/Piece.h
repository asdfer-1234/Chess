#pragma once
#include "Cell.h"
#include "Vector2.h"
#include "Size.h"
#include "Owner.h"
class Board;
#include <vector>
#include <iostream>
using namespace std;

class Piece : public Cell
{
protected:
	void SetImage(bool* image);
public:
	virtual vector<Vector2> GetPossibleMovement(Board& board, Vector2& position);
	Owner owner;
	virtual void Identify();
	
	~Piece();
	bool image[cellSize][cellSize];

	
};

