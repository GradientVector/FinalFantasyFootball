#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "SDL.h"

#include "stopif.h"

#define TITLE "FinalFantasyFootball"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define UPDATE_TICKS 10

int main(int argc, char *argv[]) {

    // SDL_Init must be called before most other SDL functions
    // Event Handling, File IO, and Threading are initialized by default.
    int error_SDL_Init = SDL_Init(SDL_INIT_VIDEO < 0);
    Stopif(error_SDL_Init, return 1, "Unable to init SDL: %s\n", SDL_GetError());

    // Must be called before an SDL application exits to safely shut down all subsystems.
    atexit(SDL_Quit);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, 
                                SCREEN_HEIGHT, 
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, 
                                &window, 
                                &renderer);
    SDL_SetWindowTitle(window, TITLE);

    // make the scaled rendering look smoother
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Enter game loop
    bool done = false;
    uint32_t last = 0;
    while (!done) {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // check for messages
            switch (event.type) {
                case SDL_QUIT: // exit if the window is closed  
                    done = true;
                    break;
                case SDL_KEYDOWN:
                    // handle key presses
                    // TODO
                    break;
                default:
                    // Log unhandled event
                    Stopif(true, /* Do nothing */, "Unhandled SDL event type %i", event.type);
                    break;
            }
        }

        // Do game update
        uint32_t now = SDL_GetTicks();
        // check if overflow occurred on the time
        if (now > last + UPDATE_TICKS || (now < last && (now + UINT32_MAX - last > UPDATE_TICKS))) {
            // Update game objects
            // TODO
            last = now;
        }
        
        // Update graphics
        // clear screen to black
	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);

        // Draw game objects
        // TODO

        // update the window
        SDL_RenderPresent(renderer);
    }

    // Do exit cleanup
    // TODO

    return EXIT_SUCCESS;
}
