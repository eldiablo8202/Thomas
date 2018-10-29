#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	//associate a texture with the sprite
	m_sprite = Sprite(TextureHolder::getTexture("graphics/thomas.png"));
	
	m_jumpDuration = 0.45;
}

//a virtual function
bool Thomas::handleInput()
{
	m_justJumped = false;
	
	if(Keyboard::isKeyPressed(Keyboard::W))
	{
		//start a jump if not already jumping
		//but only if standing on a block
		if(!m_isJumping && !m_isFalling)
		{
			m_isJumping = true;
			m_timeThisJump = 0;
			m_justJumped = true;
		}
	}
	else
	{
		m_isJumping = false;
		m_isFalling = true;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::A))
		m_leftPressed = true;
	else
		m_leftPressed = false;
	
	if(Keyboard::isKeyPressed(Keyboard::D))
		m_rightPressed = true;
	else
		m_rightPressed = false;
	
	return m_justJumped;
}
