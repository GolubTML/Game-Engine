#include <iostream>
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <stb/stb_image.h>
#include <vector>
#include "../../include/Vector2.h"
#include "../../include/Texture.h"
#include "../../include/TextureLoader.h"
#include "../../include/Camera2D.h"
#include "../../include/Player.h"
#include "../../include/Block.h"
#include "../../include/Scene.h"
#include "../../include/SceneManager.h"
#include "../../include/GameScene.h"
#include "../../include/MenuScene.h"
#include "../../include/FontLoader.h"
#include "../../include/RoomGenerator.h"

void drawSquare(const Vector2& position, float size, Texture* texture)
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

std::vector<std::vector<Block>> gen_world(int x, int y, Texture* texture)
{
    std::vector<std::vector<Block>> world;
    for (int i = 0; i < x; ++i)
    {
        std::vector<Block> row;
        for (int j = 0; j < y; ++j)
        {
            Block block(texture, Vector2(i * 32.f, j * 32.f), 32.f);
            row.push_back(block);
        }

        world.push_back(row);
    }

    return world;
}

int main() 
{
    if (!glfwInit()) 
    {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "GameEngine from Scratch", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(0, 800, 600, 0, -1, 1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    TextureLoader textureLoader;
    textureLoader.loadTexture("test", "textures/dark-grey-block.png");
    Texture* texture = textureLoader.getTexture("test");

    Vector2 position(0.f, -100.f);
    float speed = 2.0f;
    float size = 40.f;

    Camera2D camera(Vector2(0.f, 0.f), 800.f, 600.f);

    Player player(texture, position, Vector2(speed, speed), size, size, false);

    RoomGenerator roomGen(50, 50, 5, 5, 15);

    std::vector<std::vector<Block>> world = gen_world(100, 100, texture);

    SceneManager sceneManager;
    FontLoader fontLoader;

    fontLoader.loadFont("font/PlushwieFont1-Regular_4.otf", 110.f);

    auto gameScene = std::make_shared<GameScene>(window, world, texture, player);
    auto menuScene = std::make_shared<MenuScene>(window, fontLoader);

    menuScene->buttons[0].onClick = [&]()
        {
            sceneManager.setScene(gameScene);
        };

    sceneManager.setScene(menuScene);
    

    glEnable(GL_TEXTURE_2D);
    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) 
    {
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime); 
        lastTime = currentTime;

        glClear(GL_COLOR_BUFFER_BIT);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            sceneManager.setScene(menuScene);

        sceneManager.Update(deltaTime);
        sceneManager.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}