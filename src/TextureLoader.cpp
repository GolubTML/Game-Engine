#include "../../include/TextureLoader.h"

TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
}

bool TextureLoader::loadTexture(const std::string& textureName, const std::string& filePath)
{
    Texture texture;
    if (texture.loadFromFile(filePath))
    {
        m_textures[textureName] = texture;
        return true;
    }
    return false;
}

Texture* TextureLoader::getTexture(const std::string& textureName)
{
    auto it = m_textures.find(textureName);
    if (it != m_textures.end())
    {
        return &it->second;
    }
    return nullptr;
}