#include "PawnPiece.h"
#include "Board.h"

vector<Vector2> PawnPiece::GetPossibleMovement(Board& board, Vector2& position) {
	vector<Vector2> returnMovement;
	int range;
	if (position.y == startingRank) {
		range = startingMovementRange;
	}
	else {
		range = movementRange;
	}

	Vector2 currentPosition = position;
	for (int i = 0; i < range; i++) {
		currentPosition += movement;
		if (board.GetPosition(currentPosition)->IsEmpty()) {
			returnMovement.push_back(currentPosition);
		}
		else {
			break;
		}
	}

	for (int i = 0; i < captureMovement.size(); i++) {
		Vector2 currentPosition = captureMovement[i] + position;

		if (!board.GetPosition(currentPosition)->IsEmpty() && ((Piece*)(board.GetPosition(currentPosition)))->owner != owner) {
			returnMovement.push_back(currentPosition);
		}
	}
	return returnMovement;
}

PawnPiece::PawnPiece(Owner owner, bool* image, Vector2 movement, vector<Vector2> captureMovement, int startingMovementRange, int movementRange, int startingRank) {
	this->owner = owner;
	SetImage(image);
	this->movement = movement;
	this->captureMovement = captureMovement;
	this->startingMovementRange = startingMovementRange;
	this->movementRange = movementRange;
	this->startingRank = startingRank;
}
