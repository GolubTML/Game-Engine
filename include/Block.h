#pragma once
#include "Vector2.h"
#include "Texture.h"

class Block
{
public:
	Block(Texture* tex, Vector2 pos, float size);

	void Draw(Texture* tex) const;
	void DrawHitBox() const;

	Vector2 getPos() const;
	float getSize() const;

private:
	Texture* texture;
	Vector2 position;
	float size;
};