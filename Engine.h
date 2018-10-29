#pragma once

#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
private:
	//the texture TextureHolder
	TextureHolder th;
	
	//thomas and bob
	Thomas m_thomas;
	Bob m_bob;
	
	//a class to manage levels
	LevelManager m_levelManager;
	
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	//the force in pushing the characters down
	const int GRAVITY = 300;
	
	//renderwindow
	RenderWindow m_window;
	
	//the main views
	View m_mainView;
	View m_rightView;
	View m_leftView;
	
	//three view for the background
	View m_BGMainView;
	View m_BGRightView;
	View m_BGLeftView;
	
	View m_hudView;
	
	//declare a sprite and texture for the background
	Sprite m_backgroundSprite;
	Texture m_backgroundTexture;
	
	//is the game currently playing
	bool m_playing = false;
	
	//is character 1 or 2 the current focus
	bool m_character1 = true;
	
	//start in fullscreen mode
	bool m_splitScreen = false;
	
	//how much time left in the curren level
	float m_timeRemaining = 10;
	Time m_gameTimeTotal;
	
	//is it time for a new/first level
	bool m_newLevelRequired = true;
	
	//the vertex array for level TILEs
	VertexArray m_levelVertexArray;
	//the 2d array with the map for the level
	//a pointer to a pointer
	int **m_arrayLevel = NULL;
	//texture for the level tiles
	Texture m_textureTiles;
	
	//private functions for internal use only
	void input();
	void update(float deltaTimeAsSeconds);
	void draw();
	
	//load a new level
	void loadLevel();
	
public:
	//the engine constructor
	Engine();
	
	//run will call all private functions
	void run();
};
