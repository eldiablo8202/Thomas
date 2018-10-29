#include "TextureHolder.h"

#include <assert.h>

TextureHolder *TextureHolder::m_s_instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}

Texture &TextureHolder::getTexture(string const &filename)
{
	//get a reference to m_textures using m_s_instance
	auto &m = m_s_instance->m_textures; //auto is the equivalent of map<string, Texture>
	
	//create an iterator to hold a key-value pair
	//and search for the required pair using the passed in filename
	auto keyValuePair = m.find(filename); //auto is equivalent to map<string, Texture>::iterator
	
	if(keyValuePair != m.end())
	{
		//found
		//return the texture, the second part of the keyValuePair
		return keyValuePair->second;
	}
	else
	{
		//not found
		//create a new key value pair using the filename
		auto &texture = m[filename];
		//load the texture from file
		texture.loadFromFile(filename);
		
		//return the texture to the calling code
		return texture;
	}
	
}
