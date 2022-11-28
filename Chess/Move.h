#pragma once
#include "Vector2.h"
class Move
{
public:
	Vector2 from;
	Vector2 to;
	Move();
	Move(Vector2 from, Vector2 to);
};

