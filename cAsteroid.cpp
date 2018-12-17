/*
=================
cAsteroid.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cAsteroid.h"
#include <windows.h>

/*
=================================================================
Defualt Constructor
=================================================================
*/
cAsteroid::cAsteroid() : cSprite()
{
}
/*
=================================================================
Update the bounding rectangle
=================================================================
*/

void cAsteroid::update(double deltaTime)
{
	SDL_Rect currentSpritePos = this->getSpritePos();

	setBoundingRect(this->getSpritePos());
}
