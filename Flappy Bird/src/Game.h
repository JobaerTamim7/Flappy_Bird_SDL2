#pragma once
#include"CommonFunction.h"
#include<vector>
#include"Pipe.h"
#include"Bird.h"

class Pipe;
class Bird;

class Game {
public:
	Game(SDL_Window*);
	void render();
	void handle_event();
	void free_memory();
	void update();
	void pipe_generate(SDL_Window*);
	bool is_collide();
	int score_increment();

	bool get_game_over() { return game_over; }
	bool get_main_menu_state() { return main_menu_state; }


private:
	Bird* bird;
	std::vector<Pipe> pipes;
	std::map<std::string, SDL_Texture*> texture_map;
	SDL_Renderer* renderer;
	int score;

	SDL_Window* win;
	const SDL_Rect bg_rect = { 0,0,WINDOW_WIDTH,WINDOW_HEIGHT };
	const SDL_Rect test = { 100,100,100,100 };
	SDL_Rect base_rect = { 0,615,WINDOW_WIDTH,162 };
	SDL_Rect base_rect2 = { WINDOW_WIDTH,615,WINDOW_WIDTH,162 };


	bool game_over;
	bool main_menu_state;
};


