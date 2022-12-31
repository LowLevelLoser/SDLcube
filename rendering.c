#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include"./macros.h"
#include "./rendering.h" 

void render(SDL_Renderer *renderer, const cube_f *cube){
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[0][X_AXIS], cube->drawn_lines[0][Y_AXIS], 
					   cube->drawn_lines[1][X_AXIS], cube->drawn_lines[1][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[0][X_AXIS], cube->drawn_lines[0][Y_AXIS], 
					   cube->drawn_lines[2][X_AXIS], cube->drawn_lines[2][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[0][X_AXIS], cube->drawn_lines[0][Y_AXIS], 
					   cube->drawn_lines[4][X_AXIS], cube->drawn_lines[4][Y_AXIS]);
	
	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[7][X_AXIS], cube->drawn_lines[7][Y_AXIS], 
					   cube->drawn_lines[3][X_AXIS], cube->drawn_lines[3][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[7][X_AXIS], cube->drawn_lines[7][Y_AXIS], 
					   cube->drawn_lines[5][X_AXIS], cube->drawn_lines[5][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[7][X_AXIS], cube->drawn_lines[7][Y_AXIS], 
					   cube->drawn_lines[6][X_AXIS], cube->drawn_lines[6][Y_AXIS]);

	//================================================================================================
	
	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[1][X_AXIS], cube->drawn_lines[1][Y_AXIS], 
					   cube->drawn_lines[3][X_AXIS], cube->drawn_lines[3][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[1][X_AXIS], cube->drawn_lines[1][Y_AXIS], 
					   cube->drawn_lines[5][X_AXIS], cube->drawn_lines[5][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[2][X_AXIS], cube->drawn_lines[2][Y_AXIS], 
					   cube->drawn_lines[3][X_AXIS], cube->drawn_lines[3][Y_AXIS]);
	
	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[2][X_AXIS], cube->drawn_lines[2][Y_AXIS], 
					   cube->drawn_lines[6][X_AXIS], cube->drawn_lines[6][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[4][X_AXIS], cube->drawn_lines[4][Y_AXIS], 
					   cube->drawn_lines[5][X_AXIS], cube->drawn_lines[5][Y_AXIS]);

	SDL_RenderDrawLine(renderer, 
					   cube->drawn_lines[4][X_AXIS], cube->drawn_lines[4][Y_AXIS], 
					   cube->drawn_lines[6][X_AXIS], cube->drawn_lines[6][Y_AXIS]);
}
