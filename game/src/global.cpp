#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "global.h"

void fatal(const char * fmt, ...) {
	va_list v;
	char buf[1024];

	va_start(v, fmt);
	vsnprintf(buf, 1024, fmt, v);
	va_end(v);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, APP_TITLE, buf, NULL);
	exit(1);
}

