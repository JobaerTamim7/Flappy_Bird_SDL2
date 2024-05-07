#include "ChoiceMenu.h"

ChoiceMenu::ChoiceMenu(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);

	bird_vector.push_back( common::load_texture("asset/grumpy/frame-1.png", renderer));
	bird_vector.push_back ( common::load_texture("asset/dragon/frame-1.png",renderer));

	bg_vector.push_back(common::load_texture("asset/bg_game.png", renderer));

	arrow_tex = common::load_texture("asset/back.png", renderer);
	arrow_tex_actv = common::load_texture("asset/back_active.png", renderer);

	bird_mapping = {
		{0,"grumpy"},
		{1,"dragon"}
	};

	bird_no = bg_no = 0;
	quit = go_back = go_frwrd = false;


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
		SDL_RenderCopyEx(renderer, arrow_tex_actv, nullptr, &bird_up_rect, 270, nullptr, SDL_FLIP_NONE);
	}
	else
	{
		SDL_RenderCopyEx(renderer, arrow_tex, nullptr, &bird_up_rect, 270, nullptr, SDL_FLIP_NONE);
	}


	SDL_RenderPresent(renderer);
}

void ChoiceMenu::handle_event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (common::mouse_collision_rect(bird_up_rect))
			{
				bird_no++;
				if (bird_no > 1)
				{
					bird_no = 0;
				}
			}
			else if (common::mouse_collision_rect(bird_down_rect))
			{
				bird_no--;
				if (bird_no < 0)
				{
					bird_no = 0;
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
	bird_mapping.clear();
}
