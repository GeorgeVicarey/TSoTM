/*
 * Coin.h
 *
 *  Created on: 28 Apr 2014
 *      Author: George
 */

#ifndef COIN_H_
#define COIN_H_

class Coin
{
    private:
    //The X and Y offsets of the tony


    //The velocity of the tony
    int xVel, yVel;

    public:
    int x, y;
    //Initializes the variables
    Coin(int Px, int Py);
    Coin();

    //Shows the tony on the screen
    void show();

    void setPos(int px, int pY);

    void hide();

    int getX();

    int getY();
};

#endif /* COIN_H_ */


extern SDL_Surface *coin;
