#include "Bird.h"
#include<sstream>

Bird::Bird(SDL_Window* window, std::string bird_dir)
{
	renderer = SDL_GetRenderer(window);
	for (int i = 1; i < 6; i++)
	{
		std::string path = "asset/" + bird_dir + "/frame-" + common::int_to_str(i) + ".png";
		bird_tex.push_back(common::load_texture(path.c_str(), renderer));
	}
	if (bird_dir == "dragon")
	{
		bird_rect.w += 5;
		bird_rect.h += 5;
	}
	frame = 1;
	vel_y = 0;
	life = 3;
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
