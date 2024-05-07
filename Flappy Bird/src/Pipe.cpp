#include "Pipe.h"

Pipe::Pipe(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	pipe_tex = common::load_texture("asset/pipe.png", renderer);
	RAND = rand() % (150 + 150 + 1) - 150;
	pipe_rect_down = { WINDOW_WIDTH - 5,WINDOW_HEIGHT / 2 + (PIPE_GAP / 2) + RAND,70,WINDOW_HEIGHT};
	pipe_rect_up = { WINDOW_WIDTH - 5,-WINDOW_HEIGHT/2 - (PIPE_GAP/2) + RAND,70,WINDOW_HEIGHT};
	f = 0;
}


void Pipe::draw()
{
	SDL_RenderCopy(renderer, pipe_tex, nullptr, &pipe_rect_down);
	SDL_RenderCopyEx(renderer, pipe_tex, nullptr, &pipe_rect_up, 0, nullptr, SDL_FLIP_VERTICAL);

}

void Pipe::update()
{
	float dt = .1;
	pipe_rect_down.x -= SCROLL_SPEED;
	pipe_rect_up.x -= SCROLL_SPEED;
	if (f < 72.5)
	{
		pipe_rect_down.y -= f*dt;
		pipe_rect_up.y += f*dt;
		f += 2;
	}
	else
	{
		f = -72.5;
	}
}


