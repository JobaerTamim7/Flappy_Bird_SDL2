#pragma once
#include"CommonFunction.h"
#include<vector>


class ChoiceMenu
{
public:
	ChoiceMenu(SDL_Window*);
	std::string get_bird();
	bool get_frwrd() { return go_frwrd; }
	bool get_back() { return go_back; }
	void render();
	void handle_event();
	void free_memory();
	bool quit;
private:
	SDL_Renderer* renderer;
	std::vector<SDL_Texture*> bird_vector;
	std::vector<SDL_Texture*> bg_vector;
	SDL_Texture* arrow_tex;
	SDL_Texture* arrow_tex_actv;

	std::map<int, std::string> bird_mapping;

	const SDL_Rect bird_rect = { 50,WINDOW_HEIGHT / 2,48,43 };
	const SDL_Rect bg_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect bird_up_rect = { 50,WINDOW_HEIGHT / 2 + 10,24,21 };
	const SDL_Rect bird_down_rect = { 50,WINDOW_HEIGHT / 2 - 10,24,21 };


	int bird_no,bg_no;

	bool go_back;
	bool go_frwrd;

};

