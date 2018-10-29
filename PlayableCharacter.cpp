#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	//place the player at the syarting point
	m_position.x = startPosition.x;
	m_position.y = startPosition.y;
	
	//initialise the gravity
	m_gravity = gravity;
	
	//move the sprite into m_position
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::update(float elapsedTime)
{
	if(m_rightPressed)
		m_position.x += m_speed * elapsedTime;
	
	if(m_leftPressed)
		m_position.x -= m_speed * elapsedTime;
	
	//handle jumping
	if(m_isJumping)
	{
		//update how long the jump has been going
		m_timeThisJump += elapsedTime;
		
		//is the jump going upwards
		if(m_timeThisJump < m_jumpDuration)
		{
			//move up at twice gravity
			m_position.y -= m_gravity * 2 * elapsedTime;
		}
		else
		{
			m_isJumping = false;
			m_isFalling = true;
		}
	}
	
	//apply gravity
	if(m_isFalling)
		m_position.y += m_gravity * elapsedTime;
	
	//update the rect for all body parts
	FloatRect r = getPosition();
	
	//feet
	m_feet.left = r.left + 3;
	m_feet.top = r.top + r.height -1;
	m_feet.width = r.width - 6;
	m_feet.height = 1;
	
	//head
	m_head.left = r.left;
	m_head.top = r.top + (r.height * 0.3);
	m_head.width = r.width;
	m_head.height = 1;
	
	//right
	m_right.left = r.left + r.width - 2;
	m_right.top = r.top + r.height * 0.35;
	m_right.width = 1;
	m_right.height = r.height * 0.3;
	
	//left
	m_left.left = r.left;
	m_left.top = r.top + r.height * 0.5;
	m_left.width = 1;
	m_left.height = r.height * 0.3;
	
	//move the sprite into Position
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopFalling(float position)
{
	m_position.y = position - getPosition().height;
	m_sprite.setPosition(m_position);
	m_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	m_position.x = position - m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_position.x = position + m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopJump()
{
	//stop a jump early
		m_isJumping = false;
		m_isFalling = true;
}

FloatRect PlayableCharacter::getPosition()
{
	return m_sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(m_position.x + m_sprite.getGlobalBounds().width / 2,
					m_position.y + m_sprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet()
{
	return m_feet;
}

FloatRect PlayableCharacter::getHead()
{
	return m_head;
}

FloatRect PlayableCharacter::getLeft()
{
	return m_left;
}

FloatRect PlayableCharacter::getRight()
{
	return m_right;
}

Sprite PlayableCharacter::getSprite()
{
	return m_sprite;
}
