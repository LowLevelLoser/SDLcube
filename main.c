#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_mouse.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "./macros.h"
#include "./spin.h"
#include "./rendering.h"

int main(int arc, char *argv[]){

	//Initializes SDL returns an error if it cant
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
	fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	//initializes a window
    SDL_Window *window = SDL_CreateWindow("cube",
										 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //position
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
	// return error if it cannot create window
	if (window == NULL) {
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	//abstract object that does rendereing in the window black magic
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
			                                    SDL_RENDERER_ACCELERATED |
												SDL_RENDERER_PRESENTVSYNC);
	//error
	if(renderer == NULL) {
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	cube_f cube = {
		.threeD_lines =  {{1,1,1},
						 {1,1,-1},
						 {1,-1,1},
						 {1,-1,-1},
						 {-1,1,1},
						 {-1,1,-1},
						 {-1,-1,1},
						 {-1,-1,-1}},//*/ 
		.threeD_lines_rep = {{0,0,0},
							{0,0,0},
							{0,0,0},
							{0,0,0},
							{0,0,0},
							{0,0,0},
							{0,0,0},
							{0,0,0}},
		.theta_b = 0,
		.theta_d = PI_M/36
	};

	
	int quit = 1;
	SDL_Event e; // this has the events
	while(quit){
		while (SDL_PollEvent(&e)){
			switch (e.type){
			case SDL_QUIT:
					quit = 0;
					break;
			case SDL_KEYDOWN:
				if(e.key.keysym.sym == SDLK_UP){
					spinY(&cube);
				}
				else if(e.key.keysym.sym == SDLK_SPACE){
					spinZ(&cube);
				}
				else{
					spinX(&cube);
				}
				break;

				default: {}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0/*R*/, 0/*G*/, 0/*B*/, 255); //makes the background black
		SDL_RenderClear(renderer); //makes rendereing visible double buffering
								   //
		render(renderer, &cube);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
