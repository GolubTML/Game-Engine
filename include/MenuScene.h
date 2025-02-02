#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <functional>
#include <string>
#include <memory>
#include "Texture.h"
#include "Vector2.h"
#include "Scene.h"
#include "FontLoader.h"

using namespace std;

class Button
{
public:
	Vector2 position;
	Vector2 size;
	std::string label;
	std::shared_ptr<FontLoader> fontLoader;
	std::function<void()> onClick;

	Button(Vector2 position, Vector2 size, const string& label, shared_ptr<FontLoader> fontLoader, function<void()> onClick) 
		: position(position), size(size), label(label), fontLoader(fontLoader), onClick(onClick) { }

	~Button() {}

	void Draw()
	{
		glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.8f);
		glVertex2f(position.x, position.y);
		glVertex2f(position.x + size.x, position.y);
		glVertex2f(position.x + size.x, position.y + size.y);
		glVertex2f(position.x, position.y + size.y);
		glEnd();

		if (fontLoader)
		{
			/*float textX = position.x + size.x / 2;
			float textY = position.y + size.y / 2;*/
			fontLoader->Draw(label, position.x, position.y + (size.y / 4), 0.5f);
		}
	}

	bool isHovered(const Vector2& mousePos)
	{
		return mousePos.x >= position.x && mousePos.x <= position.x + size.x && mousePos.y >= position.y && mousePos.y <= position.y + size.y;
	}
};

class MenuScene : public Scene
{
public:
	std::vector<Button> buttons;
	FontLoader fontLoader;

	MenuScene(GLFWwindow* window, FontLoader fontLoader);
	~MenuScene();

	void Update(float deltaTime) override;
	void Draw() override;

private:
	GLFWwindow* window;
};