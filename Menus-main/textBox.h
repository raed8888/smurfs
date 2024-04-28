#pragma once
#include <SDL_ttf.h>

struct textBox {

	int x;
	int y;
	SDL_Color c;
	const char* message;
	int size;
	SDL_Texture* backgroundTexture; // Declare backgroundTexture as SDL_Texture*
	textBox();
	~textBox();

	void renderText();

};