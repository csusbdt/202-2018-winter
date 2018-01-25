#include <iostream>
#include "SDL.h"
#include "global.h"

void updateGameObjects(double t, double dt);
void drawGameObjects();

int main(int argc, char * argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) fatal(SDL_GetError());

	SDL_Window * window = SDL_CreateWindow(
		APP_TITLE, 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WIDTH, 
		HEIGHT, 
		0);
	if (window == nullptr) fatal(SDL_GetError());

	int flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(window, -1, flags);
	if (renderer == nullptr) fatal(SDL_GetError());

	Uint32 previous_millis = SDL_GetTicks();
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
		Uint32 millis  = SDL_GetTicks();
		double t       = millis / 1000.0;
		double dt      =  (millis - previous_millis) / 1000.0;
		if (dt > 1.0 / 60) { // fps is 60 frames per second
			// Clear canvas.
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
			SDL_RenderClear(renderer);

			// Update game objects.
			updateGameObjects(t, dt);

			// Draw game objects to the canvas.
			drawGameObjects();

			// Render canvas.
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}
	return 0;
}

void updateGameObjects(double t, double dt) {
}

void drawGameObjects() {
	SDL_Rect rect;
	rect.w = 100;
	rect.h = 50;
	rect.x = 100;
	rect.y = 100;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // r, g, b, alpha
	SDL_RenderFillRect(renderer, &rect);
}

