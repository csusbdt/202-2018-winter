#include <iostream>
#include "SDL.h"
#include "global.h"
#include "Rectangle.h"

// Game objects:
Rectangle rectangle1(100, 50, 100, 150);
Rectangle rectangle2(25, 200, 75, 50);

void initGameObjects();
void updateGameObjects(double t, double dt);
void drawGameObjects(SDL_Renderer * renderer);

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
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, flags);
	if (renderer == nullptr) fatal(SDL_GetError());

	initGameObjects();

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
			drawGameObjects(renderer);

			// Render canvas.
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}
	return 0;
}

void initGameObjects() {
}

void updateGameObjects(double t, double dt) {
	rectangle1.update(t, dt);
	rectangle2.update(t, dt);
}

void drawGameObjects(SDL_Renderer * renderer) {
	rectangle1.draw(renderer);
	rectangle2.draw(renderer);
}

