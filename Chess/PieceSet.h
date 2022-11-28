#pragma once
class Vector2;
class Cell;
class SlidingPiece;
class Piece;
class RangedPiece;
class PawnPiece;

class PieceSet{
public:
	static Cell* empty;
	static SlidingPiece* whiteRook;
	static SlidingPiece* blackRook;
	static SlidingPiece* whiteBishop;
	static SlidingPiece* blackBishop;
	static SlidingPiece* whiteQueen;
	static SlidingPiece* blackQueen;
	static RangedPiece* whiteKing;
	static RangedPiece* blackKing;
	static RangedPiece* whiteKnight;
	static RangedPiece* blackKnight;
	static PawnPiece* whitePawn;
	static PawnPiece* blackPawn;
};
