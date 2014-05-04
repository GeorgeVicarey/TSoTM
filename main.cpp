//The headers
#include "global.h"

SDL_Surface *tony = NULL;
SDL_Surface *coin = NULL;
SDL_Surface *white = NULL;
SDL_Surface *wall = NULL;
SDL_Surface *winMessage = NULL;

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //The tony that will be used

    Tony myTony;
    Coin aCoin1;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    tony = load_image( "tony.png" );
    coin = load_image( "coin32.png" );
    wall = load_image( "wall.png" );

    //While the user hasn't quit
    while( quit == false )
    {
        //Start the frame timer
        fps.start();

        //While there's events to hasndle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for tony
            myTony.handle_input();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
        //Move tony
        myTony.move();


        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );


        apply_surface(0, 100, wall, screen, NULL);
        apply_surface(500, 100, wall, screen, NULL);

        white = load_image("white32.png");

        aCoin1.setPos(200, 300);

        aCoin1.show();

        //Show tony on the screen
        myTony.show();

        apply_surface(0, 0, winMessage, screen, NULL);

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            quit = true;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    //Clean up
    clean_up();

    return 0;
}
