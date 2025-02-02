#include "../../include/Rectangle.h"

Rectangle::Rectangle(Vector2 pos, float w, float h) : position(pos), width(w), height(h)
{
	setCenter();
}

Vector2 Rectangle::setCenter()
{
	center = Vector2(width / 2.f, height / 2.f);
	return center;
}

float Rectangle::getArea() const
{
	return width * height;
}

bool Rectangle::intersects(const Rectangle& other) const
{
	return (position.x < other.position.x + other.width && position.x + width > other.position.x && position.y < other.position.y + other.height && position.y + height > other.position.y);
}