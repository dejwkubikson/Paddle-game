/*
=================
cRocket.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cRocket.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cRocket::cRocket() : cSprite()
{
	this->rocketVelocity = 0;
}
/*
=================================================================
Update the sprite position
=================================================================
*/

SDL_Event event;

void cRocket::update(double deltaTime)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_A] || theController.movingLeft() == true)
	{
		move = -1;
		stopRocket = false;
	}
	else
		if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_D] || theController.movingRight() == true)
		{
			move = 1;
			stopRocket = false;
		}
		else
			stopRocket = true;

	SDL_Rect currentSpritePos = this->getSpritePos();

	if (stopRocket == false)
	{
		// if the rocket doesnt move we want to give it a small boost to acceleration at start
		if (rocketVelocity < 400)
			rocketVelocity = 400;
		else
		rocketVelocity += rocketAcceleration;

		if (rocketMaxSpeed < rocketVelocity)
			rocketVelocity = rocketMaxSpeed;
	}
	else
	{
		rocketVelocity -= rocketDecceleration;

		if (rocketVelocity <= 0)
			rocketVelocity = 0;
	}

	currentSpritePos.x += (int)(this->rocketVelocity * this->move * deltaTime);
	
	if (currentSpritePos.x < 0 + wallWidth)
		currentSpritePos.x = 0 + wallWidth;

	if (currentSpritePos.x > 1280 - getSpriteDimensions().w - wallWidth)
		currentSpritePos.x = 1280 - getSpriteDimensions().w - wallWidth;

	this->setSpritePos({ currentSpritePos.x , currentSpritePos.y  });
	this->setBoundingRect(this->getSpritePos());
}
/*
=================================================================
Sets the velocity for the rocket
=================================================================
*/
void cRocket::setRocketVelocity(int rocketVel)
{
	rocketVelocity = rocketVel;
}
/*
=================================================================
Gets the rocket velocity
=================================================================
*/
int cRocket::getRocketVelocity()
{
	return rocketVelocity;
}
/*
=================================================================
Sets the move value for the rocket
=================================================================
*/
void cRocket::setRocketMove(int rocketMove)
{
	move = rocketMove;
}
/*
=================================================================
Gets the rocket move value
=================================================================
*/
int cRocket::getRocketMove()
{
	return move;
}
/*
=================================================================
Sets the rocket's max speed
=================================================================
*/
void cRocket::setRocketMaxSpeed(int rocketMax)
{
	rocketMaxSpeed = rocketMax;
}
/*
=================================================================
Gets the rocket's max speed
=================================================================
*/
int cRocket::getRocketMaxSpeed()
{
	return rocketMaxSpeed;
}
/*
================================================================ =
Sets the wall's width
================================================================ =
*/
void cRocket::setMovingWidth(int wallSizeW)
{
	wallWidth = wallSizeW;
}
/*
================================================================ =
Sets the paddle size
================================================================ =
*/
void cRocket::setPaddleSize(int toSet)
{
	paddleSize = toSet;
}
/*
================================================================ =
Gets the paddle size
================================================================ =
*/
int cRocket::getPaddleSize()
{
	return paddleSize;
}

