#pragma once

#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
private:
	//a map container from the STL
	//that holds related apirs of string and TEXTURE
	map<string, Texture> m_textures;
	
	//a pointer of the same type as the class itself
	//the one and only instance
	static TextureHolder *m_s_instance;
	
public:
	TextureHolder();
	static Texture& getTexture(string const& filename);
	
};

#endif
