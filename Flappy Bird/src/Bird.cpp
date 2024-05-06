#include "Bird.h"
#include<sstream>

Bird::Bird(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	for (int i = 1; i < 6; i++)
	{
		std::stringstream p;
		p << "asset/grumpy_bird/frame-" << i << ".png";
		std::string path = p.str();
		bird_tex.push_back(common::load_texture(path.c_str(), renderer));
	}
	frame = 1;
	vel_y = 0;
}


void Bird::animate()
{
	SDL_RenderCopyEx(renderer, bird_tex[floor(frame)], NULL, &bird_rect,vel_y*2,nullptr,SDL_FLIP_NONE);
	frame += .4;
	if (frame > 4)
	{
		frame = 0;
	}
}

void Bird::update()
{
	bird_rect.y += vel_y;
	vel_y += GRAVITY;
	if (vel_y >= MAX_SPEED)
	{
		vel_y = MAX_SPEED;
	}
	if (fly == true)
	{
		vel_y -= 4.5;
		fly = false;
	}
}
