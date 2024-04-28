#include "player.h"

extern SDL_Renderer* renderer;

Player::Player() {
	rect.h=64;
	rect.w = 64;
	x = 400;
	y = 320;
	rect.x = x - 32;
	rect.y = y - 32;
}
Player::~Player() {};

void Player::update() {

	rect.x = x-32;
	rect.y = y-32;

};

void Player::render() {
	SDL_SetRenderDrawColor(renderer,150,0,0,255);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);
};
