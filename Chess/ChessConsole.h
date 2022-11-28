#pragma once
#include "Board.h"
#include "Color.h"
#include "Owner.h"
#include "Vector2.h"
#include <Windows.h>
#include <iostream>
#include "Size.h"


using namespace std;

class ChessConsole
{
private:
	Board board;

	void PrintPixel(Color color, char character = ' ');
	void SetColor(Color background, Color foreground = Color::LGray, HANDLE handle = NULL);
	int GetColorInt(Color background, Color foreground);
	void GenerateBoardImage(Color image[imageSize][imageSize]);
	bool Vector2FromCoords(string& coords, Vector2& out);
	void BorderCell(Color image[imageSize][imageSize], Vector2 position);
	void PrintImage(Color image[imageSize][imageSize]);
	char GetPixelCharacter(Vector2 position);
	bool AskCoordinate(Vector2& out);
	
	void PrintBoard();
	void PrintBoardWithPossibleMovement(Vector2& position);
	bool AskMove(Owner owner);

	void ResetConsole();
public:
	
	void Play();
};

