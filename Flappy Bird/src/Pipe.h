#pragma once
#include"CommonFunction.h"
#include<stdlib.h>

class Pipe {
public:
	Pipe(SDL_Window*);
	~Pipe() {};
	void draw();
	void update();

	SDL_Rect get_pipe_rect_down() { return pipe_rect_down; }
	SDL_Rect get_pipe_rect_up() { return pipe_rect_up; }

private:
	int PIPE_GAP = 300;
	int RAND;
	int f;
	SDL_Renderer* renderer;
	SDL_Rect pipe_rect_down;
	SDL_Rect pipe_rect_up;
	SDL_Texture* pipe_tex;

	int PIPE_FREQUENCY = 300;
	

};