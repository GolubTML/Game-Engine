#pragma once
#include "../../include/FontLoader.h"

bool FontLoader::loadFont(const std::string& path, int fontSize)
{
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
	{
		std::cerr << "Fainled to init free type library!" << std::endl;
		return false;
	}

	FT_Face face;
	if (FT_New_Face(ft, path.c_str(), 0, &face))
	{
		std::cerr << "Failed to load font: " << path << std::endl;
		return false;
	}

	FT_Set_Pixel_Sizes(face, 0, fontSize);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (unsigned char c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cerr << "Failed to load glyph of characters: " << c << std::endl;
			continue;
		}

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        Character character = {
            texture,
            static_cast<GLuint>(face->glyph->advance.x),
            Vector2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            Vector2(face->glyph->bitmap_left, face->glyph->bitmap_top)
        };

        characters.insert(std::make_pair(c, character));
	}

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    return true;
}

void FontLoader::Draw(const std::string& text, float x, float y, float scale)
{
    glEnable(GL_BLEND);

    for (char c : text) 
    {
        Character ch = characters[c];

        float xpos = x + ch.bearing.x * scale;
        float ypos = y - (ch.size.y - ch.bearing.y) * scale;

        float w = ch.size.x * scale;
        float h = ch.size.y * scale;

        glBindTexture(GL_TEXTURE_2D, ch.textureID);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(xpos, ypos + h);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(xpos + w, ypos + h);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(xpos + w, ypos);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(xpos, ypos);
        glEnd();

        x += (ch.advance >> 6) * scale; 
    }
    glDisable(GL_BLEND);
}