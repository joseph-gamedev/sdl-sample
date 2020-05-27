/* #include <iostream>

int main()
{
	std::cout << "hello world";
	std::cin.get();
} */

//tinyxml2::XMLDocument doc;
//tinyxml2::XMLNode* node = doc.NewElement("foo");
//doc.InsertEndChild(node);
//doc.SaveFile("dream.xml");


#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h> 
#include <tinyxml2.h>
#include "spdlog/spdlog.h"
//#include <sdl2/SDL_image.h> 
//#include <sdl2/SDL_timer.h> 
  
#include <stdio.h>

int main(int argc, char* argv[]) {

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    SDL_Window* window;                    // Declare a pointer

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

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
