/*
 * Global.h
 *
 *  Created on: 28 Apr 2014
 *      Author: George
 */

#ifndef MadeIncludes
#define GLOBAL_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "tony.h"
#include "coin.h"
#include "timer.h"

#include <string>

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
SDL_Surface *load_image( std::string filename );
bool init();
bool load_files();
void clean_up();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 20;

#define MadeIncludes
#endif /* GLOBAL_H_ */

extern SDL_Event event;
extern SDL_Surface *screen;
extern SDL_Surface *white;
extern SDL_Surface *tony;
extern SDL_Surface *coin;
extern SDL_Surface *wall;
extern SDL_Surface *winMessage;
extern Coin aCoin1;
extern const char* Score;

