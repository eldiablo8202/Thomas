#include "LevelManager.h"
#include "TextureHolder.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>
#include <fstream>

int **LevelManager::nextLevel(VertexArray &rVaLevel)
{
	m_levelSize.x = 0;
	m_levelSize.y = 0;
	
	//get the next Level
	m_currentLevel++;
	if(m_currentLevel > NUM_LEVELS)
	{
		m_currentLevel = 1;
		m_timeModifier -= 0.1f;
	}
	
	//load the appropriate level from a textfile
	string levelToLoad;
	switch(m_currentLevel)
	{
		case 1:
			levelToLoad = "levels/level1.txt";
			m_startPosition.x = 100;
			m_startPosition.y = 100;
			m_baseTimeLimit = 30.0f;
			break;
			
		case 2:
			levelToLoad = "levels/level2.txt";
			m_startPosition.x = 100;
			m_startPosition.y = 2600;
			m_baseTimeLimit = 100.0f;
			break;
			
		case 3:
			levelToLoad = "levels/level3.txt";
			m_startPosition.x = 1250;
			m_startPosition.y = 0;
			m_baseTimeLimit = 30.0f;
			break;
			
		case 4:
			levelToLoad = "levels/level4.txt";
			m_startPosition.x = 50;
			m_startPosition.y = 200;
			m_baseTimeLimit = 50.0f;
			break;
	}//end switch
	
	ifstream inputFile(levelToLoad);
	string s;
	
	//count the number of rows in the inputFile
	while(getline(inputFile, s))
		++m_levelSize.y;
	
	//store the length of the rows
	m_levelSize.x = s.length();
	
	//go back to the start of the inputFile
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	//prepapre the 2d arrayto hold the int values from the inputFile
	int **arrayLevel = new int*[m_levelSize.y];
	for(int i = 0; i < m_levelSize.y; ++i)
	{
		//add a new array into each array element
		arrayLevel[i] = new int[m_levelSize.x];
	}
	
	//loop throught the file and store all the values in the 2d array
	string row;
	int y = 0;
	
	while(inputFile >> row)
	{
		for(int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}
		y++;
	}
	
	//close the file
	inputFile.close();
	
	//what type of primitive are we using
	rVaLevel.setPrimitiveType(Quads);
	
	//set the size of the vertex array
	rVaLevel.resize(m_levelSize.x * m_levelSize.y * VERTS_IN_QUAD);
	
	//start at the begiinig of the vertex array
	int currentVertex = 0;
	
	for(int x = 0; x < m_levelSize.x; x++)
	{
		for(int y = 0; y < m_levelSize.y; y++)
		{
			//position each vertex int the current Quads
			rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);
			rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);
			
			//which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[x][y] * TILE_SIZE;
			
			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0+ verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
			
			//position ready for the next four vertices
			currentVertex += VERTS_IN_QUAD;
		}
	}
	
	return arrayLevel;
}

Vector2i LevelManager::getLevelSize()
{
	return m_levelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_currentLevel;
}

float LevelManager::getTimeLimit()
{
	return m_baseTimeLimit * m_timeModifier;
}

Vector2f LevelManager::getStartPosition()
{
	return m_startPosition;
}
