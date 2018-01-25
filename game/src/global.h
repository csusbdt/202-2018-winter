#pragma once

#include "SDL.h"

#define APP_TITLE  "Game"
#define WIDTH      1280
#define HEIGHT     960

extern SDL_Renderer * renderer;

void fatal(const char * fmt, ...);

