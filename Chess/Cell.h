#pragma once

class Piece;
class Cell
{
	
public:
	
	Cell();
	virtual ~Cell();
	virtual void Identify();
	bool IsEmpty();

	Piece* CastToPiece();
};

