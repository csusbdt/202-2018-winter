#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, double w, double h) 
: x(x), y(y), w(w), h(h) 
{
	xSpeed = 100;
	ySpeed = 50;
}

void Rectangle::update(double t, double dt) {
	x += xSpeed * dt;
	y += ySpeed * dt;
}

void Rectangle::draw(SDL_Renderer * renderer) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &rect);
}

