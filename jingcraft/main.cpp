#include <iostream>
#include "renderer/render.h"
#include "world/world.h"
#include "SDL.h"

using namespace std;

int main(){
	cout << "Hello World" << endl;
	testPrint("asdf");
	testPrint2("asdf");
	Render rend;
	Render rend2 = rend;
	std::cout << std::endl;

	World world;
	world.print();
    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully made
    if (window == NULL) {
        // In the event that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: enter program loop (see SDL_PollEvent)

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

	SDL_Quit();


	return 0;
}
