#pragma once
#include"CommonFunction.h"

class MainMenu
{
public:
	MainMenu(SDL_Window*);
	~MainMenu() {};
	void handle_event();
	void render();
	void free_memory();
	void sound();
	bool get_main_menu_state() { return main_menu_state; }
	bool get_instruct_state() { return instruct_state; }
	bool get_game_run_state() { return game_state; }
private:
	SDL_Renderer* renderer;
	std::map <std::string, SDL_Texture*> texture_map;
	std::map <std::string, Mix_Music*> music_map;
	

	// STATE SECTION
	bool main_menu_state;
	bool instruct_state;
	bool game_state;

	// RECT SECTION
	const SDL_Rect main_menu_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect start_font_rect = { 220, 219, 169, 54 };
	const SDL_Rect instruct_font_rect = { 233, 327, 136, 60 };
	const SDL_Rect start_button_rect = { 196,214,212,70 };
	const SDL_Rect instruct_button_rect = { 196,325,212,70 };

};



