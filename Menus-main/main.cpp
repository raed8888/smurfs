#include <chrono>
#include <SDL_mixer.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include "game.h"
#include "pauseMenu.h"
#include "titleScreen.h"
#include <iostream>
Mix_Music* backgroundMusic;

typedef std::chrono::high_resolution_clock Clock;
int FPS;
int cnt;
bool gameRunning = false;


SDL_Window* window;
SDL_Renderer* renderer;
Game game;
pauseMenu pause;
titleScreen title;




int gameInit(const char* title, int w, int h, bool fullscreen) {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	return true;
};


int main(int argc, char* argv[]) {

	if (gameInit("Hello", 800, 640, 0)) {
		title.on = true;
		gameRunning = true;
	}
	else std::cout << "Initialization failed." << std::endl;
	// Initialize SDL Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "SDL Mixer initialization failed: " << Mix_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1; // Exit the program if SDL Mixer initialization fails
	}

	// Load background music
	backgroundMusic = Mix_LoadMUS("smuf_song.wav");
	if (!backgroundMusic) {
		std::cout << "Failed to load background music: " << Mix_GetError() << std::endl;
		Mix_CloseAudio();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1; // Exit the program if background music loading fails
	}

	// Start playing the background music
	if (Mix_PlayMusic(backgroundMusic, -1) == -1) {
		std::cout << "Failed to play background music: " << Mix_GetError() << std::endl;
		Mix_FreeMusic(backgroundMusic);
		Mix_CloseAudio();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1; // Exit the program if background music playing fails
	}

	while (gameRunning) {

		//auto t1 = Clock::now();


		if (game.on) {
			game.handleEvents();
			game.update();
			game.render();
		}

		if (title.on) {
			title.handleEvents();
			title.update();
			title.render();

		}

		if (pause.on) { //we could add game.update and/or game.render while in pause menu
			pause.handleEvents();
			pause.update();
			pause.render();

		}


		/*auto t2 = Clock::now();


		FPS = 1000000000 / std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		cnt++;
		if (cnt > 1000) {
			std::cout << FPS << " FPS" << std::endl;
			cnt = 0;
		}*/

	}

	Mix_FreeMusic(backgroundMusic);
	Mix_CloseAudio();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	/*bool confirm = false;
	char* input = new char[1];
	std::cout << "Type \"y\" to close this window." << std::endl;
	while (!confirm) {
		std::cin >> input;
		if (*input == *"y") { confirm = true;} //I don't even know what is going on there.
											   //I think both are pointers so they point to different memory.
											   // So we have to take the value at that adress
	}*/


	return 0;
}