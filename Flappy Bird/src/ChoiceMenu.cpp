#include "ChoiceMenu.h"

ChoiceMenu::ChoiceMenu(SDL_Window* window, Uint32 type_start)
{
	renderer = SDL_GetRenderer(window);

	bird_vector.push_back( common::load_texture("asset/grumpy/frame-1.png", renderer));
	bird_vector.push_back ( common::load_texture("asset/dragon/frame-1.png",renderer));
	bird_vector.push_back(common::load_texture("asset/winter/frame-1.png", renderer));
	bird_vector.push_back(common::load_texture("asset/bee/frame-1.png", renderer));

	bg_vector.push_back(common::load_texture("asset/texture/bg_game.png", renderer));
	base = common::load_texture("asset/texture/base.png", renderer);

	arrow_tex = common::load_texture("asset/texture/back.png", renderer);
	arrow_tex_actv = common::load_texture("asset/texture/back_active.png", renderer);

	bird_mapping = {
		{0,"grumpy"},
		{1,"dragon"},
		{2,"winter"},
		{3,"bee"}
	};

	bird_no = bg_no = 0;
	quit = go_back = go_frwrd = false;

	time = type_start;
}

std::string ChoiceMenu::get_bird()
{
	return bird_mapping[bird_no];
}

void ChoiceMenu::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, bg_vector[bg_no], nullptr, &bg_rect);
	SDL_RenderCopy(renderer, bird_vector[bird_no], nullptr, &bird_rect);
	SDL_RenderCopy(renderer, base, nullptr, &base_rect);
	if (common::mouse_collision_rect(bird_up_rect))
	{
		SDL_RenderCopyEx(renderer, arrow_tex_actv, nullptr, &bird_up_rect, 90, nullptr, SDL_FLIP_NONE);
	}
	else
	{
		SDL_RenderCopyEx(renderer, arrow_tex, nullptr, &bird_up_rect, 90, nullptr, SDL_FLIP_NONE);
	}
	if (common::mouse_collision_rect(bird_down_rect))
	{
		SDL_RenderCopyEx(renderer, arrow_tex_actv, nullptr, &bird_down_rect, 270, nullptr, SDL_FLIP_NONE);
	}
	else
	{
		SDL_RenderCopyEx(renderer, arrow_tex, nullptr, &bird_down_rect, 270, nullptr, SDL_FLIP_NONE);
	}

	if (!common::typer(renderer, common::file_reader("Game_text/choice_menu_tutorial.txt"), time))
	{
		time = SDL_GetTicks();
	}

	SDL_RenderPresent(renderer);
}

void ChoiceMenu::handle_event()
{
	int t_bird = bird_mapping.rbegin()->first;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (common::mouse_collision_rect(bird_up_rect))
			{
				bird_no++;
				if (bird_no > t_bird)
				{
					bird_no = 0;
				}
			}
			else if (common::mouse_collision_rect(bird_down_rect))
			{
				bird_no--;
				if (bird_no < 0)
				{
					bird_no = t_bird;
				}
			}
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = go_back = true;
			
			}
			if (event.key.keysym.sym == SDLK_RETURN)
			{
				quit = go_frwrd = true;
			}
		}
	}
}

void ChoiceMenu::free_memory()
{
	for (SDL_Texture* bird_texture : bird_vector) {
		SDL_DestroyTexture(bird_texture);
	}
	bird_vector.clear();
	for (SDL_Texture* bg_texture : bg_vector) {
		SDL_DestroyTexture(bg_texture);
	}
	bg_vector.clear();
	SDL_DestroyTexture(arrow_tex);
	SDL_DestroyTexture(arrow_tex_actv);
	SDL_DestroyTexture(base);
	bird_mapping.clear();
}
