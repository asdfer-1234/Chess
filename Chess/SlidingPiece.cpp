#include "SlidingPiece.h"
#include "Board.h"

SlidingPiece::SlidingPiece() {

}

SlidingPiece::SlidingPiece(Owner owner, bool* image, vector<Vector2>& movement) {
	this->owner = owner;
	this->movement = movement;

	for (int y = 0; y < cellSize; y++) {
		for (int x = 0; x < cellSize; x++) {
			this->image[y][x] = *(image + y * cellSize + x);
		}
	}
}


vector<Vector2> SlidingPiece::GetPossibleMovement(Board& board, Vector2& position) {
	vector<Vector2> possibleMovement;
	for (int i = 0; i < (int)size(movement); i++) {
		

		vector<Vector2> slided = Slide(board, position, movement[i]);

		possibleMovement.insert(possibleMovement.end(), slided.begin(), slided.end());


	}
	return possibleMovement;
}

vector<Vector2> SlidingPiece::Slide(Board& board, Vector2 position, Vector2& direction, int range) {
	vector<Vector2> slided;
	
	for(int i = 0; i < range; i++){
		position += direction;
		
		if (board.PositionValid(position)) {
			if (board.GetPosition(position)->IsEmpty()) {
				slided.push_back(position);
			}
			else {
				Piece* piecePosition = (Piece*)(board.GetPosition(position));

				if (piecePosition->owner != this->owner) {
					slided.push_back(position);
				}
				break;
			}
		}
		else {
			break;
		}
		

	}


	return slided;
}