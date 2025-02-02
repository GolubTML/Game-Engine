#include "../../include/Player.h"

Player::Player(Texture* texture, const Vector2& position, const Vector2& velocity, float w, float h, bool onGround) : texture(texture), position(position), velocity(velocity), onGround(onGround), width(w), height(h) { }

void Player::Update(GLFWwindow * window, Camera2D & camera, std::vector<std::vector<Block>> map, float deltaTime)
{
    Vector2 horizontalPosition = position;
    Vector2 verticalPosition = position;

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        horizontalPosition.x -= velocity.x;
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        horizontalPosition.x += velocity.x;
    }

    if (onGround && glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        velocity.y = -jumpPower * deltaTime;
        onGround = false;
    }


    if (!grounded(map, { horizontalPosition.x, position.y }))
    {
        position.x = horizontalPosition.x;
    }

    if (!onGround)
    {
        velocity.y += gravityScale * deltaTime;
    }

    verticalPosition.y += velocity.y;

    if (grounded(map, { position.x, verticalPosition.y }))
    {
        if (velocity.y > 0)
        {
            verticalPosition.y = position.y;
            onGround = true;
            velocity.y = 0;
        }
        else if (velocity.y < 0)
        {
            verticalPosition.y = position.y; 
            velocity.y = 0;
        }
    }
    else
    {
        onGround = false;
    }

    position.y = verticalPosition.y;
    camera.center(position);
}

void Player::Draw(Texture* texture)
{
    texture->bind();

    Vector2 vertices[4] =
    {
        position + Vector2(-width / 2, -height / 2),
        position + Vector2(width / 2, -height / 2),
        position + Vector2(width / 2,  height / 2),
        position + Vector2(-width / 2,  height / 2)
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

bool Player::grounded(std::vector<std::vector<Block>> map, const Vector2& newPosition) const
{
    Rectangle playerRect(newPosition, width, height);

    for (const auto& row : map)
    {
        for (const auto& block : row)
        {
            Rectangle blockRect(block.getPos(), block.getSize(), block.getSize());

            if (playerRect.intersects(blockRect))
                return true;
        }
    }
    return false;
}

Rectangle Player::getPlayerRect() const
{
    return Rectangle(position, width, height);
}

Texture* Player::getTexture()
{
    return texture;
}