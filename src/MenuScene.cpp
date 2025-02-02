#include "../../include/MenuScene.h"
#include "../../include/Vector2.h"
#include <iostream>

MenuScene::MenuScene(GLFWwindow* window, FontLoader fontLoader) : window(window), fontLoader(fontLoader)
{
    std::shared_ptr<FontLoader> fontLoaderPtr = std::make_shared<FontLoader>(fontLoader);

    Vector2 playButtonPos(100.f, 200.f);
    Vector2 exitButtonPos(100.f, 300.f);

    Button playButton(playButtonPos, Vector2(200.f, 60.f), "START", fontLoaderPtr, []() { std::cout << "Start Button Clicked\n"; });
    Button exitButton(exitButtonPos, Vector2(120.f, 60.f), "EXIT", fontLoaderPtr, [window]() { glfwSetWindowShouldClose(window, GLFW_TRUE); });

    buttons =
    {
        playButton,
        exitButton
	};
}

MenuScene::~MenuScene() {}

void MenuScene::Update(float deltaTime)
{
    double mx, my;
    glfwGetCursorPos(window, &mx, &my);
    Vector2 mousePos(static_cast<float>(mx), static_cast<float>(my));

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) 
    {
        for (auto& button : buttons) 
        {
            if (button.isHovered(mousePos)) 
            {
                button.onClick();
            }
        }
    }
}

void MenuScene::Draw()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& button : buttons)
    {
        button.Draw();
    }
}