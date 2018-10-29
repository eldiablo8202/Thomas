#include "Engine.h"

Engine::Engine()
{
	//get the screen resolution
	//create a sfml window and view
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	
	m_window.create(VideoMode(resolution.x, resolution.y), "Thomas", Style::Fullscreen);
	
	//initialise the fullscreen view
	m_mainView.setSize(resolution);
	m_hudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	
	//initialise the splitscreen views
	m_leftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_rightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	
	//can this pc use shaders
	if(!Shader::isAvailable())
		m_window.close();
	
	m_backgroundTexture = TextureHolder::getTexture("graphics/background.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	
	//load the texture for the background vertex array
	m_textureTiles = TextureHolder::getTexture("graphics/tiles_sheet.png");
}

void Engine::run()
{
	//timing
	Clock clock;
	
	while(m_window.isOpen())
	{
		Time deltaTime = clock.restart();
		
		//update the total game time
		m_gameTimeTotal +=  deltaTime;
		//make a decima; fraction from the delta time
		float deltaTimeAsSeconds = deltaTime.asSeconds();
		
		//call each part of the game loop in turn
		input();
		update(deltaTimeAsSeconds);
		draw();
	}
}

