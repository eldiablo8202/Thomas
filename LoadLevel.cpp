#include "Engine.h"

void Engine::loadLevel()
{
	m_playing = false;
	
	//delete the previously allocated memory
	for(int i = 0; i < m_levelManager.getLevelSize().y; ++i)
		delete[] m_arrayLevel[i];
	
	delete[] m_arrayLevel;
	
	//load the next 2d array with the map for the Level
	//and repopulate the vertex array
	m_arrayLevel = m_levelManager.nextLevel(m_levelVertexArray);
	
	//how long is the new time limit
	m_timeRemaining = m_levelManager.getTimeLimit();
	
	//spawn thomas and bob
	m_thomas.spawn(m_levelManager.getStartPosition(), GRAVITY);
	m_bob.spawn(m_levelManager.getStartPosition(), GRAVITY);
	
	//make sure this code isn't run again
	m_newLevelRequired = false;
}
