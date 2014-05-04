/*
 * Coin.cpp
 *
 *  Created on: 28 Apr 2014
 *      Author: George
 */

#include "global.h"

//Coin::Coin(int Px, int Py)
//{
//    //Initialize the offsets
//    x = Px;
//    y = Py;
//
//    //Initialize the velocity
//    xVel = 0;
//    yVel = 0;
//}

Coin::Coin()
{
	x = 0;
	y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;
}

void Coin::show()
{
    //Show the coin
    apply_surface( x, y, coin, screen, NULL);
}

void Coin::setPos(int pX, int pY)
{
	x = pX;
	y = pY;
}

void Coin::hide()
{
	apply_surface(x, y, white, screen, NULL);
}

int Coin::getX()
{
	return x;
}

int Coin::getY()
{
	return y;
}
