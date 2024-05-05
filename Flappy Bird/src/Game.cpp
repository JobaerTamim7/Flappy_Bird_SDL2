#include "Game.h"
#include<sstream>


Game::Game(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	texture_map["bg"] = common::load_texture("asset/bg_game.png", renderer);
	texture_map["base"] = common::load_texture("asset/base.png", renderer);
	game_over = false;
	main_menu_state = false;
	win = window;

	bird = new Bird(win);
	score = 0;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture_map["bg"], nullptr, &bg_rect);
	for (Pipe& pipe : pipes)
	{
		pipe.draw();
		pipe.update();
	}

	SDL_RenderCopy(renderer, texture_map["base"], nullptr, &base_rect);
	SDL_RenderCopy(renderer, texture_map["base"], nullptr, &base_rect2);
	update();
	
	bird->animate();
	bird->update();

	//common::display_setter(renderer, texture_map["test1"]);
	SDL_RenderPresent(renderer);
	pipe_generate(win);
	score_increment();
}

void Game::handle_event()
{
	static bool fly_shut = false;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			game_over = true;
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				game_over = true;
			}
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				if (!fly_shut)
				{
					bird->fly = true;
					fly_shut = true;
				}
			}
		}
		if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				fly_shut = false;
			}
		}
		
	}
}

void Game::free_memory()
{
	for (auto& tex : texture_map) {
		if (tex.second) {
			SDL_DestroyTexture(tex.second);
		}
	}
	pipes.clear();
	delete bird;

}

void Game::update()
{
	base_rect.x -= SCROLL_SPEED;
	base_rect2.x -= SCROLL_SPEED;

	if (base_rect.x + WINDOW_WIDTH < 0)
	{
		base_rect.x = -4 + WINDOW_WIDTH;
	}
	if (base_rect2.x + WINDOW_WIDTH < 0)
	{
		base_rect2.x = -4 + WINDOW_WIDTH;
	}
	if (is_collide() == true)
	{
		game_over = true;
		main_menu_state = true;
	}

}

void Game::pipe_generate(SDL_Window* window)
{
	static Uint32 current_time = 0;
	Uint32 last_time = SDL_GetTicks();
	if (last_time - current_time > 2000)
	{
		Pipe new_pipe(window);
		pipes.push_back(new_pipe);
		current_time = last_time;
	}
	//std::cout << current_time << " " << last_time << std::endl;
	for (auto i = pipes.begin(); i != pipes.end();)
	{
		if (i->get_pipe_rect_up().x + i->get_pipe_rect_up().w < 0)
		{
			i = pipes.erase(i); 
		}
		else
		{
			++i; 
		}
	}
	
}

bool Game::is_collide()
{
	SDL_Rect bird_rect = bird->get_bird_rect();
	for (Pipe& pipe : pipes)
	{
		SDL_Rect pipe_rect_up = pipe.get_pipe_rect_up();
		SDL_Rect pipe_rect_down = pipe.get_pipe_rect_down();
		if (SDL_HasIntersection(&pipe_rect_up, &bird_rect) || SDL_HasIntersection(&pipe_rect_down,&bird_rect))
		{
			return true;
		}
	}
	if (bird_rect.y <= 0 || bird_rect.y + bird_rect.h >= 615)
	{
		return true;
	}
	return false;
}

int Game::score_increment()
{
	SDL_Rect bird_rect = bird->get_bird_rect();
	for (Pipe& pipe : pipes)
	{
		SDL_Rect pipe_rect_up = pipe.get_pipe_rect_up();
		SDL_Rect pipe_rect_down = pipe.get_pipe_rect_down();
		if (bird_rect.x>pipe_rect_up.x+pipe_rect_up.w)
		{
			score++;
			std::cout << score << std::endl;
		}
	}
	return score;
}

