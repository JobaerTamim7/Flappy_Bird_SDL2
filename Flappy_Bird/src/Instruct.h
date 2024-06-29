#pragma once
#include"CommonFunction.h"



class Instruct {
public:
	Instruct(SDL_Window*);
	~Instruct(){};
	void handle_event();
	void render();
	void free_memory();

	bool get_instruct_state() { return instruct_state; }
	bool get_main_menu_state() { return main_menu_state; }
private:
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> texture_map;

	bool instruct_state;
	bool main_menu_state;

	const SDL_Rect instruct_bg_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect instruct_1_rect = { 70,63,338,60 };
	const SDL_Rect instruct_2_rect = { 70,164,351,60 };
	const SDL_Rect instruct_3_rect = { 70,265,444,60 };
	const SDL_Rect instruct_4_rect = { 70,366,444,60 };
	const SDL_Rect back_button = { 509,572,60,60 };
};