#include "../../include/Camera2D.h"
#include <cmath>

Camera2D::Camera2D() : position(Vector2(0.f, 0.f)), zoom(1.f), rotation(0.f), viewportWidth(0), viewportHeight(0) { }

Camera2D::Camera2D(const Vector2& position, float w, float h) : position(position), zoom(1.f), rotation(0.f), viewportWidth(w), viewportHeight(h) { }

void Camera2D::center(const Vector2& target)
{
	/*position.x = target.x - (viewportWidth / 2.0f);
	position.y = target.y - (viewportHeight / 2.0f);*/
	move(target);
}

void Camera2D::applyTransform() const
{
	glScalef(zoom, zoom, 1.0f);
	glRotatef(rotation * 180.0f / 3.14, 0.0f, 0.0f, 1.0f);
	glTranslatef(-position.x, -position.y, 0.f);
}

void Camera2D::move(const Vector2& targetPosition)
{
	const float smoothingFactor = 0.1f;

	float targetX = targetPosition.x - (viewportWidth / 2.0f);
	float targetY = targetPosition.y - (viewportHeight / 2.0f);

	position.x += (targetX - position.x) * smoothingFactor;
	position.y += (targetY - position.y) * smoothingFactor;
}

void Camera2D::setZoom(float newZoom)
{
	if (newZoom > 0.f)
		zoom = newZoom;
}

void Camera2D::rotate(float angle)
{
	rotation += angle;
}