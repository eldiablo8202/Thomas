#include "Engine.h"

#include <iostream>

void Engine::update(float deltaTimeAsSeconds)
{
	if(m_newLevelRequired)
	{
		//load a level
		loadLevel();
	}
	
	if(m_playing)
	{
		//update thomas
		m_thomas.update(deltaTimeAsSeconds);
		
		//update m_bob
		m_bob.update(deltaTimeAsSeconds);
		
		//count down the time the player has left
		m_timeRemaining -= deltaTimeAsSeconds;
		
		//have thomas and bob run out of time
		if(m_timeRemaining > 0)
			m_newLevelRequired = true;
	}//end if(m_playing)
	
	//set the appropriate view around each character
	if(m_splitScreen)
	{
		m_leftView.setCenter(m_thomas.getCenter());
		m_rightView.setCenter(m_bob.getCenter());
	}
	else
	{
		//center full screen around appropriate character
		if(m_character1)
			m_mainView.setCenter(m_thomas.getCenter());
		else
			m_mainView.setCenter(m_bob.getCenter());
	}
	
}
