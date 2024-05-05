#pragma once
#include"CommonFunction.h"

class MainMenu
{
public:
	MainMenu(SDL_Window*);
	void handle_event();
	void render();
	void free_memory();
	bool get_main_menu_state() { return main_menu_state; }
	bool get_instruct_state() { return instruct_state; }
	bool get_game_run_state() { return game_state; }
private:
	SDL_Renderer* renderer;
	std::map <std::string, SDL_Texture*> texture_map;

	// STATE SECTION
	bool main_menu_state;
	bool instruct_state;
	bool game_state;

	// RECT SECTION
	const SDL_Rect main_menu_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect start_font_rect = { 200,174,200,70 };
	const SDL_Rect instruct_font_rect = { 227,346,132,80 };
	const SDL_Rect start_button_rect = { 180,169,240,90 };
	const SDL_Rect instruct_button_rect = { 180,346,240,90 };
};



