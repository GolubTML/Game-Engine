#pragma once
#include "Texture.h"
#include "Vector2.h"
#include "Camera2D.h"
#include "Block.h"
#include "Rectangle.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <vector>

class Player
{
public:
	Player(Texture* texture, const Vector2& position, const Vector2& velocity, float w, float h, bool onGround);

	void Update(GLFWwindow* window, Camera2D& camera, std::vector<std::vector<Block>> map, float deltaTime);
	void Draw(Texture* texture);
	
	bool grounded(std::vector<std::vector<Block>> map, const Vector2& newPosition) const;

	Rectangle getPlayerRect() const;

	Texture* getTexture();

private:
	Texture* texture;
	Vector2 position;
	Vector2 velocity;
	float gravityScale = 9.81f;
	float jumpPower = 250.f;
	float width, height;
	bool onGround;
};