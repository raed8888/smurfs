#pragma once

#include <SDL.h>
#include "textBox.h"
#include "pauseMenu.h"
#include "game.h"
#include <iostream>



struct titleScreen {
	int pos = 0;
	int n = 3;
	textBox textBoxes[3];
	SDL_Texture* backgroundTexture; // Declare backgroundTexture as SDL_Texture*


	bool on = false;
	

	titleScreen();
	~titleScreen();

	void update();
	void render();
	void handleEvents();


};