#pragma once
#include "Texture.h"
#include <unordered_map>
#include <string>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	bool loadTexture(const std::string& textureName, const std::string& filePath);
	Texture* getTexture(const std::string& textureName);

private:
	std::unordered_map<std::string, Texture> m_textures;
};