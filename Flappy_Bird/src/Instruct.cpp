#include"Instruct.h"

Instruct::Instruct(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	texture_map["instruct_bg"] = common::load_texture("asset/texture/instruct_bg.png", renderer);
	texture_map["instruct_1"] = common::load_font_texture("asset/font/roboto.ttf", common::file_reader("Game_Text/tutorial_1.txt"), renderer, BLACK, 40);
	texture_map["instruct_2"] = common::load_font_texture("asset/font/roboto.ttf", common::file_reader("Game_Text/tutorial_2.txt"), renderer, BLACK, 40);
	texture_map["instruct_3"] = common::load_font_texture("asset/font/roboto.ttf", common::file_reader("Game_Text/tutorial_3.txt"), renderer, RED, 40);
	texture_map["instruct_4"] = common::load_font_texture("asset/font/roboto.ttf", common::file_reader("Game_Text/tutorial_4.txt"), renderer, LGREEN, 40);
	texture_map["go_back"] = common::load_texture("asset/texture/back.png", renderer);
	texture_map["go_back_active"] = common::load_texture("asset/texture/back_active.png", renderer);
	instruct_state = true;
	main_menu_state = false;
}

void Instruct::handle_event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			instruct_state = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				instruct_state = false;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (common::mouse_collision_rect(back_button))
			{
				instruct_state = false;
				main_menu_state = true;
			}
		}
	}
}

void Instruct::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture_map["instruct_bg"], nullptr, &instruct_bg_rect);
	SDL_RenderCopy(renderer, texture_map["instruct_1"], nullptr, &instruct_1_rect);
	SDL_RenderCopy(renderer,texture_map["instruct_2"],nullptr,&instruct_2_rect);
	SDL_RenderCopy(renderer,texture_map["instruct_3"],nullptr,&instruct_3_rect);
	SDL_RenderCopy(renderer,texture_map["instruct_4"],nullptr,&instruct_4_rect);
	//common::display_setter(renderer, texture_map["instruct_3"]);
	if (common::mouse_collision_rect(back_button))
	{
		SDL_RenderCopy(renderer, texture_map["go_back_active"], nullptr, &back_button);
	}
	else
	{
		SDL_RenderCopy(renderer, texture_map["go_back"], nullptr, &back_button);
	}
	SDL_RenderPresent(renderer);
}

void Instruct::free_memory()
{
	for (auto& tex : texture_map) {
		if (tex.second) {
			SDL_DestroyTexture(tex.second);
		}
	}
}
