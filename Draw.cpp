#include "Engine.h"

void Engine::draw()
{
	//rub out the last frame
	m_window.clear(Color::White);
	
	if(!m_splitScreen)
	{
		//switch to background view
		m_window.setView(m_BGMainView);
		//draw the background
		m_window.draw(m_backgroundSprite);
		//switch to main view
		m_window.setView(m_mainView);
		
		//draw the level
		m_window.draw(m_levelVertexArray, &m_textureTiles);
		
		//draw thomas
		m_window.draw(m_thomas.getSprite());
		
		//draw bobs
		m_window.draw(m_bob.getSprite());
	}
	else
	{
		//split screen is active
		
		//first draw thomas side of the screen
		//switch to background left view
		m_window.setView(m_BGLeftView);
		//draw the background
		m_window.draw(m_backgroundSprite);
		//switch to left view
		m_window.setView(m_leftView);
		
		//draw the level
		m_window.draw(m_levelVertexArray, &m_textureTiles);
		
		//draw thomas and bobs
		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());
		
		//now draqw bobs side
		//switch to background right view
		m_window.setView(m_BGRightView);
		//draw the background
		m_window.draw(m_backgroundSprite);
		//switch to right view
		m_window.setView(m_rightView);
		
		//draw the level
		m_window.draw(m_levelVertexArray, &m_textureTiles);
		
		//draw thomas and bobs
		m_window.draw(m_thomas.getSprite());
		m_window.draw(m_bob.getSprite());
	}
	
	//draw the hud
	//switch to hud view
	m_window.setView(m_hudView);
	//show everrything we have drawn
	m_window.display();
}
