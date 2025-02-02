#pragma once
#include "Vector2.h"

class Rectangle
{
public:
	Vector2 position, center;
	float width, height;

	Rectangle(Vector2 pos, float w, float h);

	Vector2 setCenter();
	float getArea() const;
	bool intersects(const Rectangle& other) const;
};