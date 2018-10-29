#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class LevelManager
{
private:
	Vector2i m_levelSize;
	Vector2f m_startPosition;
	
	float m_timeModifier = 1;
	float m_baseTimeLimit = 0;
	
	int m_currentLevel = 0;
	const int NUM_LEVELS = 4;
	
public:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	float getTimeLimit();
	Vector2f getStartPosition();
	int **nextLevel(VertexArray &rVaLevel);
	Vector2i getLevelSize();
	int getCurrentLevel();
};
