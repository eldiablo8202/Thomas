#pragma once

#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	//constructor
	Bob();
	
	//override input handler
	bool virtual handleInput();
};
