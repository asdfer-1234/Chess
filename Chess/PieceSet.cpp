#include "PieceSet.h"
#include "Size.h"
#include "Vector2.h"
#include <vector>
#include "Cell.h"
#include "SlidingPiece.h"
#include "RangedPiece.h"
#include "PawnPiece.h"
#define t true
#define f false
// A set of pieces
Cell* PieceSet::empty = new Cell();
static bool rookImage[cellSize][cellSize] = {
	{f,f,f,f,f,f,f},
	{f,t,f,t,f,t,f},
	{f,t,t,t,t,t,f},
	{f,f,t,t,t,f,f},
	{f,f,t,t,t,f,f},
	{f,t,t,t,t,t,f},
	{f,f,f,f,f,f,f}
};

static vector<Vector2> rookMovement{ Vector2(1, 0), Vector2(-1, 0), Vector2(0, 1), Vector2(0, -1) };

SlidingPiece* PieceSet::whiteRook = new SlidingPiece(Owner::White, *rookImage, rookMovement);
SlidingPiece* PieceSet::blackRook = new SlidingPiece(Owner::Black, *rookImage, rookMovement);

static bool bishopImage[cellSize][cellSize] = {
	{f,f,f,f,f,f,f},
	{f,f,f,t,f,f,f},
	{f,f,t,f,t,f,f},
	{f,f,t,t,t,f,f},
	{f,f,f,t,f,f,f},
	{f,t,t,f,t,t,f},
	{f,f,f,f,f,f,f}
};

static vector<Vector2> bishopMovement{ Vector2(1, 1), Vector2(1, -1), Vector2(-1, 1), Vector2(-1, -1) };

SlidingPiece* PieceSet::whiteBishop = new SlidingPiece(Owner::White, *bishopImage, bishopMovement);
SlidingPiece* PieceSet::blackBishop = new SlidingPiece(Owner::Black, *bishopImage, bishopMovement);

static bool queenImage[cellSize][cellSize] = {
	{f,f,f,f,f,f,f},
	{f,t,f,t,f,t,f},
	{f,t,f,t,f,t,f},
	{f,t,f,t,f,t,f},
	{f,f,t,t,t,f,f},
	{f,f,t,t,t,f,f},
	{f,f,f,f,f,f,f}
};

static vector<Vector2> queenMovement = { Vector2(1, 0), Vector2(-1, 0), Vector2(0, 1), Vector2(0, -1), Vector2(1, 1), Vector2(1, -1), Vector2(-1, 1), Vector2(-1, -1) };

SlidingPiece* PieceSet::whiteQueen = new SlidingPiece(Owner::White, *queenImage, queenMovement);
SlidingPiece* PieceSet::blackQueen = new SlidingPiece(Owner::Black, *queenImage, queenMovement);

static bool kingImage[cellSize][cellSize]{
	{f,f,f,f,f,f,f},
	{f,f,f,t,f,f,f},
	{f,f,t,t,t,f,f},
	{f,f,f,t,f,f,f},
	{f,t,t,t,t,t,f},
	{f,f,t,t,t,f,f},
	{f,f,f,f,f,f,f}
};

RangedPiece* PieceSet::whiteKing = new RangedPiece(Owner::White, *kingImage, queenMovement, 1);
RangedPiece* PieceSet::blackKing = new RangedPiece(Owner::Black, *kingImage, queenMovement, 1);

static bool knightImage[cellSize][cellSize]{
	{f,f,f,f,f,f,f},
	{f,f,t,t,t,f,f},
	{f,t,t,t,t,t,f},
	{f,f,f,t,t,t,f},
	{f,f,t,t,t,f,f},
	{f,t,t,t,t,t,f},
	{f,f,f,f,f,f,f}
};

static vector<Vector2> knightMovement{ Vector2(2, 1), Vector2(-2, 1), Vector2(2, -1), Vector2(-2, -1), Vector2(1, 2), Vector2(-1, 2), Vector2(1, -2), Vector2(-1, -2) };

RangedPiece* PieceSet::whiteKnight = new RangedPiece(Owner::White, *knightImage, knightMovement, 1);
RangedPiece* PieceSet::blackKnight = new RangedPiece(Owner::Black, *knightImage, knightMovement, 1);

static bool pawnImage[cellSize][cellSize]{
	{f,f,f,f,f,f,f},
	{f,f,f,f,f,f,f},
	{f,f,f,t,f,f,f},
	{f,f,t,t,t,f,f},
	{f,f,f,t,f,f,f},
	{f,f,t,t,t,f,f},
	{f,f,f,f,f,f,f}
};

static vector<Vector2> whitePawnCaptureMovement{Vector2(1, -1), Vector2(-1, -1)};
static vector<Vector2> blackPawnCaptureMovement{ Vector2(1, 1), Vector2(-1, 1)};

PawnPiece* PieceSet::whitePawn = new PawnPiece(Owner::White, *pawnImage, Vector2(0, -1), whitePawnCaptureMovement, 2, 1, 6);
PawnPiece* PieceSet::blackPawn = new PawnPiece(Owner::Black, *pawnImage, Vector2(0, 1), blackPawnCaptureMovement, 2, 1, 1);

