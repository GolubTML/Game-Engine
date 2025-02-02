#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.h"

class Camera2D
{
public:
	Vector2 position;
	float zoom, rotation;
	float viewportWidth; 
	float viewportHeight;

	Camera2D();
	Camera2D(const Vector2& position, float w, float h);

	void center(const Vector2& target);
	void applyTransform() const;
	void move(const Vector2& delta);
	void setZoom(float newZoom);
	void rotate(float angles);
};