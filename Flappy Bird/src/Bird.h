#pragma once
#include"CommonFunction.h"
#include<vector>

class Bird
{
public:
	Bird(SDL_Window*);
	void animate();
	void update();
	SDL_Rect get_bird_rect(){ return bird_rect; }
	bool fly = false;
private:
	SDL_Renderer* renderer;
	std::vector<SDL_Texture*> bird_tex;
	float frame;
	float vel_y;
	SDL_Rect bird_rect = { 50,WINDOW_HEIGHT / 2,45,40 };
};

