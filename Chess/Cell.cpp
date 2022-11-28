#include <iostream>
#include "Cell.h"
#include "Piece.h"



Cell::Cell() {
	//std::cout << "cell constructed\n";
}

Cell::~Cell() {
	//std::cout << "cell deleted\n";
}

void Cell::Identify() {
	std::cout << "Cell\n";
}

bool Cell::IsEmpty() {
	return dynamic_cast<Piece*>(this) == NULL;
}

Piece* Cell::CastToPiece() {
	if (this->IsEmpty() ) {
		return NULL;
	}
	else {
		return (Piece*)(this);
	}
}