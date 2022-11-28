#include "Vector2.h"


Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator+(Vector2 other) {
	return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(Vector2 other) {
	*this = *this + other;
	return *this;
}

bool Vector2::operator==(Vector2 other)
{
	if (other.x == this->x && other.y == this->y) {
		return true;
	}
	return false;
}

Vector2 Vector2::operator* (int other) {
	return Vector2(x * other, y * other);
}