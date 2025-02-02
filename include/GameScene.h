#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include "Player.h"
#include "Block.h"
#include "Camera2D.h"
#include "Scene.h"
#include "RoomGenerator.h"

class GameScene : public Scene
{
public:
    GameScene(GLFWwindow* window, std::vector<std::vector<Block>> world, Texture* blockTexture, Player player);

    void Update(float deltaTime) override;
    void Draw() override;

private:
    GLFWwindow* window;
    Camera2D camera;
    Player player;
    RoomGenerator map;
    std::vector<std::vector<Block>> world;

    Texture* blockTexture;
};