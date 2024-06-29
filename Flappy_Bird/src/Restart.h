#pragma once
#include"CommonFunction.h"


class Restart
{
public:
	Restart(SDL_Window*);
	~Restart(){};
	void render();

	SDL_Rect get_menu_button() { return menu_button_rect; }
	SDL_Rect get_re_button() { return re_button_rect; }
private:
	SDL_Renderer* renderer;
	std::map < std::string, SDL_Texture*>tex_map;
	const SDL_Rect h_score_rect = { 92,365,242,66 };
	const SDL_Rect score_rect = { 194,437,247,67 };
	const SDL_Rect re_button_rect = { 85,553,147,51 };
	const SDL_Rect menu_button_rect = {WINDOW_WIDTH-(20+240),553,147,51};
	const SDL_Rect re_rect = { 98,550,115,51};
	const SDL_Rect menu_rect = { 358,550,121,51 };
	const SDL_Rect game_over_rect = { 201,157,203,131 };
};  

