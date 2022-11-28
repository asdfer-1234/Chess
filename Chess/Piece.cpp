#include "Piece.h"
#include <iostream>
void Piece::SetImage(bool* image)
{
	for (int y = 0; y < cellSize; y++) {
		for (int x = 0; x < cellSize; x++) {
			this->image[y][x] = *(image + y * cellSize + x);
		}
	}
}
vector<Vector2> Piece::GetPossibleMovement(Board& board, Vector2& position)
{
	return vector<Vector2>(0);
}
void Piece::Identify()
{
	std::cout << "Piece\n";
}

Piece::~Piece() {
	//std::cout << "piece delete\n";
}