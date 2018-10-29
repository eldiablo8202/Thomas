#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	Sprite m_sprite;
	
	//how long does a jump last
	float m_jumpDuration;
	
	//is character currectly jumping or falling
	bool m_isJumping, m_isFalling;
	
	//which directio is the character moving
	bool m_leftPressed, m_rightPressed;
	
	//how long has this jump lasted
	float m_timeThisJump;
	
	//has the player just initiate a jump
	bool m_justJumped = false;
	
private:
	//what is the gravity
	float m_gravity;
	
	//how fast is the character
	float m_speed = 400;
	
	//where is the player
	Vector2f m_position;
	
	//where are the characters body parts
	FloatRect m_feet, m_head, m_left, m_right;
	
	//texture
	Texture m_texture;
	
public:
	void spawn(Vector2f startPosition, float gravity);
	
	//this is a pure virtual function
	bool virtual handleInput() = 0; //this class is now abstract and cannot be instantiated
	
	//where is the player
	FloatRect getPosition();
	
	//a rectangle representing different parts of the player
	FloatRect getFeet(), getHead(), getLeft(), getRight();
	
	//send a copy of the sprite to main
	Sprite getSprite();
	
	//make the character stand firm
	void stopFalling(float position);
	void stopLeft(float position);
	void stopRight(float position);
	void stopJump();
	
	//where is the center of the characyer
	Vector2f getCenter();
	
	//call this function once every frame
	void update(float elapsedTime);
	
};
