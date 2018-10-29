#include "Engine.h"

void Engine::input()
{
	Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == Event::KeyPressed)
		{
			//handle the player quitting
			if(Keyboard::isKeyPressed(Keyboard::Escape))
				m_window.close();
			
			//handle the player starting the game
			if(Keyboard::isKeyPressed(Keyboard::Return))
				m_playing = true;
			
			//switch between thomas and bob
			if(Keyboard::isKeyPressed(Keyboard::Q))
				m_character1 = !m_character1;
			
			//switch between full and split screen
			if(Keyboard::isKeyPressed(Keyboard::E))
				m_splitScreen = !m_splitScreen;
		}
	}
	
	//handle input for thomas
	if(m_thomas.handleInput())
	{
		//play a jump sound
	}
	
	//handle input for bob
	if(m_bob.handleInput())
	{
		//play a jump sound
	}
}
