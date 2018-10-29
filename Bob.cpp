#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	//associate a texture with the sprite
	m_sprite = Sprite(TextureHolder::getTexture("graphics/bob.png"));
	
	m_jumpDuration = 0.25;
}

bool Bob::handleInput()
{
	m_justJumped = false;
	
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		//start a jump if not already jumping but only if not falling
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
	
	if(Keyboard::isKeyPressed(Keyboard::Left))
		m_leftPressed = true;
	else
		m_leftPressed = false;
	
	if(Keyboard::isKeyPressed(Keyboard::Right))
		m_rightPressed = true;
	else
		m_rightPressed = false;
	
	return m_justJumped;
}
