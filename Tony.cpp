/*
 * Tony.cpp
 *
 *  Created on: 58 Apr 5014
 *      Author: George
 */

#include "global.h"

//The tony that will move around on the screen
//The event structure
SDL_Event event;

const int TONY_WIDTH = 26;
const int TONY_HEIGHT = 80;

Coin aCoin1;

const char* Score = "0";

Tony::Tony()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;
}

void Tony::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        if(event.key.keysym.sym == SDLK_UP)
        {
        	yVel -= TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_DOWN)
        {
        	yVel += TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_LEFT)
        {
         	xVel -= TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_RIGHT)
        {
        	xVel += TONY_HEIGHT / 5;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
   {
	//Adjust the velocity

        if(event.key.keysym.sym == SDLK_UP)
        {
        	yVel += TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_DOWN)
        {
        	yVel -= TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_LEFT)
        {
         	xVel += TONY_HEIGHT / 5;
        }
        else if(event.key.keysym.sym == SDLK_RIGHT)
        {
        	xVel -= TONY_HEIGHT / 5;
        }
    }
}

void Tony::move()
{
    //Move the tony left or right
    x += xVel;

    //If the tony went too far to the left or right
    if( ( x < 0 ) || ( x + TONY_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= xVel;
    }

    //Move the tony up or down
    y += yVel;

    //If the tony went too far up or down
    if( ( y < 0 ) || ( y + TONY_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= yVel;
    }

   	if( ((x + TONY_WIDTH) > 200 && x < (200 + 32))
    		&& ((y + TONY_HEIGHT) > 300 && y < (300 + 32)))
    {
    	coin = load_image("50.png");

    	winMessage = load_image("win.png");
    }

   	if( ((x + TONY_WIDTH) > 0 && x < (400))
   	    && ((y + TONY_HEIGHT) > 100 && y < (100 + 32)))
   	{
   	    x -= xVel;
   	    y -= yVel;
   	}

   	if( ((x + TONY_WIDTH) > 500 && x < (640))
   	   	&& ((y + TONY_HEIGHT) > 100 && y < (100 + 32)))
   	{
   	   	x -= xVel;
   	   	y -= yVel;
   	}
}

void Tony::show()
{
    //Show the tony
    apply_surface( x, y, tony, screen, NULL );
}
