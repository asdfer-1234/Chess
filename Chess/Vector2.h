#pragma once
class Vector2
{
public:
	int x, y;
	Vector2();
	Vector2(int x, int y);
	Vector2 operator+(Vector2 other);
	Vector2& operator += (Vector2 other);
	bool operator == (Vector2 other);
	Vector2 operator*(int other);
};

