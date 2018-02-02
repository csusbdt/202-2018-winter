#pragma once

#include "SDL.h"

class Rectangle {
public:
	Rectangle(double x, double y, double w, double h); 
	void update(double t, double dt);
	void draw(SDL_Renderer * renderer);

private:
	double x;
	double y;
	double w;
	double h;
	double xSpeed;
	double ySpeed;

};

