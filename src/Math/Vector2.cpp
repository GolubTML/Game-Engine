#include "../../include/Vector2.h"

Vector2::Vector2() : x(0), y(0) { }
Vector2::Vector2(float x, float y) : x(x), y(y) { }

float Vector2::magnitude() const
{
	return std::sqrt(pow(x, 2) + pow(y, 2));
}

Vector2 Vector2::normalized() const
{
	return Vector2(magnitude(), magnitude());
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const
{
	if (scalar == 0)
	{
		return *this;
	}
	else
	{
		return Vector2(x / scalar, y / scalar);
	}
}

Vector2 Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2 Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

Vector2 Vector2::operator/=(float scalar)
{
	if (scalar == 0) 
	{
		return *this;
	}
	x /= scalar;
	y /= scalar;
	
	return *this;
}

Vector2 Vector2::operator=(const Vector2& other)
{
	float newX = other.x;
	float newY = other.y;

	return Vector2(newX, newY);
}

Vector2 Vector2::rotate(float angles) const
{
	float cosAngle = cos(angles);
	float sinAngle = sin(angles);

	float newX = x * cosAngle - y * sinAngle;
	float newY = x * sinAngle + y * cosAngle;

	return Vector2(newX, newY);
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}