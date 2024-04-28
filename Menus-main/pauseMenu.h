#pragma once
#include <SDL.h>
#include "textBox.h"
#include <iostream>
#include "game.h"
#include "titleScreen.h"
#include "player.h"


struct pauseMenu {
	int pos = 0;
	bool on = false;

	int n = 4;
	textBox textBoxes[4];
	SDL_Texture* backgroundTexture; // Declare backgroundTexture as SDL_Texture*

	pauseMenu();
	~pauseMenu();

	void update();
	void render();
	void handleEvents();


};