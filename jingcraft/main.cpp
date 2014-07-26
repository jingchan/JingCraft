#include <iostream>
#include "renderer/render.h"
#include "world/world.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

using namespace std;

void CreateSDL();

int main(){
	cout << "Hello World" << endl;
	testPrint("asdf");
	testPrint2("asdf");
	Render rend;
	Render rend2 = rend;
	std::cout << std::endl;

	World world;
	world.print();

 //    SDL_Window *window;                    // Declare a pointer

 //    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

 //    SDL_Surface * surface = SDL_CreateSurface(
 //    	)
 //    // Create an application window with the following settings:
 //    window = SDL_CreateWindow(
 //        "An SDL2 window",                  // window title
 //        SDL_WINDOWPOS_UNDEFINED,           // initial x position
 //        SDL_WINDOWPOS_UNDEFINED,           // initial y position
 //        640,                               // width, in pixels
 //        480,                               // height, in pixels
 //        SDL_WINDOW_OPENGL                  // flags - see below
 //    );

 //    // Check that the window was successfully made
 //    if (window == NULL) {
 //        // In the event that the window could not be made...
 //        printf("Could not create window: %s\n", SDL_GetError());
 //        return 1;
 //    }

 //    // The window is open: enter program loop (see SDL_PollEvent)

 //    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

 //    // Close and destroy the window
 //    SDL_DestroyWindow(window);

	// SDL_Quit();
	CreateSDL();

	return 0;
}

void CreateSDL(){
	    SDL_Surface *screen;

	    /* Information about the current video settings. */
    // const SDL_VideoInfo* info = NULL;
    /* Dimensions of our window. */
    int width = 0;
    int height = 0;
    /* Color depth in bits of our window. */
    int bpp = 0;
    /* Flags we will pass into SDL_SetVideoMode. */
    int flags = 0;

    /* First, initialize SDL's video subsystem. */
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		SDL_Quit();
    }

    /* Request opengl 3.2 context.
     * SDL doesn't have the ability to choose which profile at this time of writing,
     * but it should default to the core profile */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    /* Let's get some video information. */
    // info = SDL_GetVideoInfo( );

    // if( !info ) {
    //     /* This should probably never happen. */
    //     fprintf( stderr, "Video query failed: %s\n",
    //          SDL_GetError( ) );
    //     SDL_Quit( );
    // }

    /*
     * Now, we want to setup our requested
     * window attributes for our OpenGL window.
     * We want *at least* 5 bits of red, green
     * and blue. We also want at least a 16-bit
     * depth buffer.
     *
     * The last thing we do is request a double
     * buffered window. '1' turns on double
     * buffering, '0' turns it off.
     *
     * Note that we do not use SDL_DOUBLEBUF in
     * the flags to SDL_SetVideoMode. That does
     * not affect the GL attribute state, only
     * the standard 2D blitting setup.
     */
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );

    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /*
     * Set our width/height to 640/480 (you would
     * of course let the user decide this in a normal
     * app). We get the bpp we will request from
     * the display. On X11, VidMode can't change
     * resolution, so this is probably being overly
     * safe. Under Win32, ChangeDisplaySettings
     * can change the bpp.
     */
    width = 640;
    height = 480;
    bpp = 32;
    // bpp = info->vfmt->BitsPerPixel;
    
    screen = SDL_SetVideoMode( width, height, bpp, SDL_OPENGL ); // *changed*
    if ( !screen ) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
    }

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

#ifndef __EMSCRIPTEN__
    // Wait for 3 seconds to give us a chance to see the image
    SDL_Delay(3000);
#endif
    printf("success");

    // SDL_Quit();
    /*
     * We want to request that SDL provide us
     * with an OpenGL window, in a fullscreen
     * video mode.
     *
     * EXERCISE:
     * Make starting windowed an option, and
     * handle the resize events properly with
     * glViewport.
     */
    // flags = SDL_OPENGL | SDL_FULLSCREEN;

/* Create our window centered at 512x512 resolution */
  //   SDL_Window *mainwindow = SDL_CreateWindow("PROGRAM_NAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
  //       512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  //   if(mainwindow == 0){
		// fprintf( stderr, "Create Window failed: %s\n", SDL_GetError( ) );
  //   } else {
  //       printf("Success");	
  //   }

    // /*
    //  * Set the video mode
    //  */
    // if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 ) {
         
    //      * This could happen for a variety of reasons,
    //      * including DISPLAY not being set, the specified
    //      * resolution not being available, etc.
         
    //     fprintf( stderr, "Video mode set failed: %s\n",
    //          SDL_GetError( ) );

    //     SDL_Quit();
        
    // }


}