#include "RangedPiece.h"
#include "Owner.h"
#include <vector>
#include "Vector2.h"
using namespace std;

RangedPiece::RangedPiece(Owner owner, bool* image, vector<Vector2>& movement, int range) {
	this->owner = owner;
	this->movement = movement;

	for (int y = 0; y < cellSize; y++) {
		for (int x = 0; x < cellSize; x++) {
			this->image[y][x] = *(image + y * cellSize + x);
		}
	}
	
	this->range = range;
}
vector<Vector2> RangedPiece::GetPossibleMovement(Board& board, Vector2& position) {
	vector<Vector2> possibleMovement;
	for (int i = 0; i < (int)size(movement); i++) {
		vector<Vector2> slided = Slide(board, position, movement[i], range);
		possibleMovement.insert(possibleMovement.end(), slided.begin(), slided.end());
	}
	return possibleMovement;
}