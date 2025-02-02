#include "../../include/Texture.h"
#include <iostream>
#include <stb/stb_image.h>

Texture::Texture() : m_textureID(0), width(0), height(0), channels(0) { }

Texture::~Texture()
{
	if (m_textureID != 1)
	{
		glDeleteTextures(1, &m_textureID);
	}
}

bool Texture::loadFromFile(const std::string& filePath)
{
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
	if (!data)
	{
		return false;
	}

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	
	stbi_image_free(data);

	return true;
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

GLuint Texture::getID() const
{
	return m_textureID;
}

int Texture::getWidth() const
{
	return width;
}

int Texture::getHeight() const
{
	return height;
}