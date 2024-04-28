#include "pauseMenu.h"
#include <SDL_image.h>

extern SDL_Renderer* renderer;
extern SDL_Window* window;

extern bool gameRunning;

extern Game game;
extern titleScreen title;
extern Player player;









pauseMenu::pauseMenu() : backgroundTexture(nullptr) {
	for (int i = 0;i < 4;i++) {
		textBoxes[i].x = 800 / 2;
		textBoxes[i].y = (640 - ((n - 1) * 100)) / 2 + i * 100;  //neatly centered :)  Some of it is done in textbox.cpp because i need the surface size
		//and I can't be bothered to change all the code to have it here
		textBoxes[0].message = "Continue";
		textBoxes[1].message = "Options";
		textBoxes[2].message = "Restart";
		textBoxes[3].message = "Quit";
	}
};
	pauseMenu::~pauseMenu() {};

	




void pauseMenu::handleEvents() {
	//std::cout << "hi" << std::endl;
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {

	case SDL_QUIT:
		gameRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			pos -= 1;
			break;
		case SDLK_DOWN:
			pos += 1;
			break;

		case SDLK_RETURN:
			if (pos == 0) { /*(title.)*/on = false;game.on = true; }
			if (pos == 1) std::cout << "options" << std::endl;
			if (pos == 2) { 
				on = false; 
				title.on = true; 
				player.x=400;
				player.y =320;
	
			}

			if (pos == 3) gameRunning = false;
			break;

		default:
			break;
		}
		if (pos == n) pos = 0;
		if (pos < 0) pos = n - 1;

		break;


	default:
		break;
	}
	
};

void pauseMenu::update() {
	for (int i = 0;i < n;i++) { //reset all to default
		textBoxes[i].c = { 255,255,255 };
		textBoxes[i].size = 24;
	}

	textBoxes[pos].c = { 255,255,0 }; //put yellow for the one selected
	textBoxes[pos].size = 42;
	SDL_Surface* bgSurface = IMG_Load("snfr.png");
	backgroundTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_FreeSurface(bgSurface);
};
void pauseMenu::render() {
	// Set the draw color to a dark background color
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

	// Clear the renderer
	SDL_RenderClear(renderer);

	// Render the background texture
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

	// Set the draw color to white for rendering text
	SDL_Color White = { 255, 255, 255 };

	// Render the text boxes
	for (int i = 0; i < n; i++) {
		textBoxes[i].renderText();
	}

	// Present the renderer
	SDL_RenderPresent(renderer);
}
