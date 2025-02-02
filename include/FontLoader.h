#pragma once
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Vector2.h"

struct Character
{
	GLuint textureID;
	GLuint advance;
	Vector2 size;
	Vector2 bearing;
};

class FontLoader
{
public:
	std::map<char, Character> characters;

	FontLoader() = default;

	bool loadFont(const std::string& path, int fontSize);

	void Draw(const std::string& text, float x, float y, float scale);
};