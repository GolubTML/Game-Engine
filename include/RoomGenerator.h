#pragma once
#include "Block.h"
#include "Vector2.h"
#include <random>
#include <vector>
#include <algorithm>

struct Room
{
	Vector2 position;
	int width, height;
	 
	Room(const Vector2& pos, int w, int h) : position(pos), width(w), height(h) {}

	bool intersects(const Room& other) const
	{
		return position.x < other.position.x + other.width && position.x + width > other.position.x && position.y < other.position.y + other.height && position.y + height > other.position.y;
	}
};

class RoomGenerator
{
public:
    int width, height, rCount, minSize, maxSize;
    std::vector<std::vector<Block>> blocks;
    std::vector<Room> rooms;

    Room createRoom();

	void connectRooms(const Room& a, const Room& b);

	RoomGenerator();
    RoomGenerator(int width, int height, int rCount, int minSize, int maxSize);

	std::vector<std::vector<Block>> generate(Texture* blockTex);
	void Draw(Texture* texture) const;
};