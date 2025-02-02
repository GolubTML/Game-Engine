#pragma once
#include <cmath>

class Vector2
{
public:
	float x, y;

	Vector2();
	Vector2(float x, float y);

	float magnitude() const;

	Vector2 normalized() const;
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator/(float scalar) const;
	Vector2 operator*(float scalar) const;

	Vector2 operator+=(const Vector2& other);
	Vector2 operator-=(const Vector2& other);
	Vector2 operator/=(float scalar);
	Vector2 operator*=(float scalar);

	Vector2 operator=(const Vector2& other);

	Vector2 rotate(float angles) const;

	float dot(const Vector2& other) const;
};