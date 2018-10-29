#pragma once

#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	//a constructor specific to thomas
	Thomas();
	
	//the overidden input handler
	bool virtual handleInput();
};
