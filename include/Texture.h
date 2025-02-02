#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();
	bool loadFromFile(const std::string& filePath);
	void bind() const;
	GLuint getID() const;

	int getWidth() const;
	int getHeight() const;

private:
	GLuint m_textureID;
	int width, height, channels;
};