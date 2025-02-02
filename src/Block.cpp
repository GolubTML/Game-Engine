#include "../../include/Block.h"

Block::Block(Texture* tex, Vector2 pos, float size) : texture(tex), position(pos), size(size) { }

void Block::Draw(Texture* tex) const
{
    texture->bind();

    Vector2 vertices[4] =
    {
        position + Vector2(-size / 2, -size / 2),
        position + Vector2(size / 2, -size / 2),
        position + Vector2(size / 2,  size / 2),
        position + Vector2(-size / 2,  size / 2)
    };

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(vertices[0].x, vertices[0].y);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(vertices[1].x, vertices[1].y);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(vertices[2].x, vertices[2].y);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(vertices[3].x, vertices[3].y);

    glEnd();
}

void Block::DrawHitBox() const
{
    Vector2 hitboxVertices[4] =
    {
        position + Vector2(-size / 2, -size / 2),
        position + Vector2(size / 2, -size / 2),
        position + Vector2(size / 2, size / 2),
        position + Vector2(-size / 2, size / 2)
    };

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);

    glVertex2f(hitboxVertices[0].x, hitboxVertices[0].y);
    glVertex2f(hitboxVertices[1].x, hitboxVertices[1].y);
    glVertex2f(hitboxVertices[2].x, hitboxVertices[2].y);
    glVertex2f(hitboxVertices[3].x, hitboxVertices[3].y);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
}

Vector2 Block::getPos() const
{
    return position;
}

float Block::getSize() const
{
    return size;
}