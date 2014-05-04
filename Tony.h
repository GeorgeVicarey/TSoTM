/*
 * Tony.h
 *
 *  Created on: 28 Apr 2014
 *      Author: George
 */

#ifndef TONY_H_
#define TONY_H_

class Tony
{
    private:
    //The X and Y offsets of the tony
    int x, y;

    //The velocity of the tony
    int xVel, yVel;

    public:
    //Initializes the variables
    Tony();

    //Takes key presses and adjusts the tony's velocity
    void handle_input();

    //Moves the tony
    void move();

    //Shows the tony on the screen
    void show();
};

#endif /* TONY_H_ */



extern SDL_Surface *tony;
