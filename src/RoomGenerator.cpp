#include "../../include/RoomGenerator.h"

RoomGenerator::RoomGenerator() : width(0), height(0), rCount(0), minSize(0), maxSize(0) { }

RoomGenerator::RoomGenerator(int width, int height, int rCount, int minSize, int maxSize) : width(width), height(height), rCount(rCount), minSize(minSize), maxSize(maxSize)
{
	blocks.resize(height, std::vector<Block>(width, Block(nullptr, Vector2(0, 0), 0.0f)));
}

Room RoomGenerator::createRoom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> sizeDist(minSize, maxSize);
    std::uniform_int_distribution<> xDist(1, width - maxSize - 1);
    std::uniform_int_distribution<> yDist(1, height - maxSize - 1);

    int w = sizeDist(gen);
    int h = sizeDist(gen);
    int x = xDist(gen);
    int y = yDist(gen);

    return Room(Vector2(x, y), w, h);
}

void RoomGenerator::connectRooms(const Room& a, const Room& b)
{
    int ax = a.position.x + a.width / 2;
    int ay = a.position.y + a.height / 2;
    int bx = b.position.x + b.width / 2;
    int by = b.position.y + b.height / 2;

    if (ax < bx)
    {
        for (int x = ax; x <= bx; ++x)
        {
            
        }
    }
    else
    {
        for (int x = bx; x <= ax; ++x)
        {
            
        }
    }

    if (ay < by)
    {
        for (int y = ay; y <= by; ++y)
        {
            
        }
    }
    else
    {
        for (int y = by; y <= ay; ++y)
        {
            
        }
    }
}

std::vector<std::vector<Block>> RoomGenerator::generate(Texture* blockTex)
{
    rooms.clear();

    for (int i = 0; i < rCount; ++i)
    {
        Room room = createRoom();

        bool valid = true;
        for (const auto& other : rooms)
        {
            if (room.intersects(other))
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            rooms.push_back(room);

            for (int y = room.position.y; y < room.position.y + room.height; ++y)
            {
                for (int x = room.position.x; x < room.position.x + room.width; ++x)
                {
                    blocks[y][x] = Block(blockTex, Vector2(x, y), 1.0f);
                }
            }
        }
    }

    for (size_t i = 1; i < rooms.size(); ++i)
    {
        connectRooms(rooms[i - 1], rooms[i]);
    }

    return blocks;
}

void RoomGenerator::Draw(Texture* texture) const
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (blocks[y][x].getSize() > 0.0f)
            {
                blocks[y][x].Draw(texture);
            }
        }
    }
}