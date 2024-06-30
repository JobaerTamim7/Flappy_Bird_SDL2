#include "MainMenu.h"

MainMenu::MainMenu(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	texture_map["main_menu_bg"] = common::load_texture("asset/texture/main_menu_bg.png", renderer);
	texture_map["button_bg"] = common::load_texture("asset/texture/btn.png", renderer);
	texture_map["button_bg_active"] = common::load_texture("asset/texture/btn_active.png", renderer);
	texture_map["start_font"] = common::load_font_texture("asset/font/minecraft.ttf", "Play Game", renderer, BROWN, 500);
	texture_map["start_font_active"] = common::load_font_texture("asset/font/minecraft.ttf", "Play Game", renderer, GREEN, 800);
	texture_map["instruct_font"] = common::load_font_texture("asset/font/minecraft.ttf", "Tutorial", renderer, BROWN, 500);
	texture_map["instruct_font_active"] = common::load_font_texture("asset/font/minecraft.ttf", "Tutorial", renderer, GREEN, 500);	
	texture_map["title"] = common::load_texture("asset/texture/title.png",renderer);
	texture_map["sound"] = common::load_texture("asset/texture/sound.png",renderer);
	//texture_map["meteor"] = common::load_texture("asset/texture/meteor.png", renderer);

	music_map["bg_music"] = Mix_LoadMUS("asset/sound/open.mp3");

	main_menu_state = true;
	instruct_state = false;
	game_state = false;
	sound_state = true;
}

void MainMenu::free_memory()
{
	for (auto& tex : texture_map) {
		if (tex.second) {
			SDL_DestroyTexture(tex.second);
		}
	}
	for (auto& msc : music_map) {
		if (msc.second) {
			Mix_FreeMusic(msc.second);
		}
	}
}

void MainMenu::sound()
{
	if(sound_state == true){
		if(Mix_PlayingMusic() == false)
		{
			Mix_PlayMusic(music_map["bg_music"], -1);
		}
		else
		{
			Mix_ResumeMusic();
		}
	}
	else{
		Mix_HaltMusic();
	}
}


void MainMenu::handle_event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			main_menu_state = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				main_menu_state = false;
			}
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (common::mouse_collision_rect(instruct_button_rect)) {
				main_menu_state = false;
				instruct_state = true;

			}
			else if (common::mouse_collision_rect(start_button_rect)) {
				main_menu_state = false;
				game_state = true;
			}
			else if(common::mouse_collision_rect(sound_rect)){
				if (sound_state == false)
				{
					sound_state = true;
				}
				else
				{
					sound_state = false;
				}
			}
		}

	}
}

void MainMenu::render()
{
	sound();
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture_map["main_menu_bg"],nullptr,&main_menu_rect);

	//common::display_setter(renderer,texture_map["sound"]);
	SDL_RenderCopy(renderer,texture_map["title"],nullptr,&title_rect);
	if(sound_state == true)
	{
		SDL_RenderCopy(renderer,texture_map["sound"],&sound_src_rect_on,&sound_rect);
	}
	else
	{
		SDL_RenderCopy(renderer,texture_map["sound"],&sound_src_rect_off,&sound_rect);
	}
	if (common::mouse_collision_rect(start_button_rect))
	{
		SDL_RenderCopy(renderer, texture_map["button_bg_active"], nullptr, &start_button_rect);
		SDL_RenderCopy(renderer, texture_map["start_font_active"], nullptr, &start_font_rect);
	}
	else
	{
		SDL_RenderCopy(renderer, texture_map["button_bg"], nullptr, &start_button_rect);
		SDL_RenderCopy(renderer, texture_map["start_font"], nullptr, &start_font_rect);
	}
	if (common::mouse_collision_rect(instruct_button_rect))
	{
		SDL_RenderCopy(renderer, texture_map["button_bg_active"], nullptr, &instruct_button_rect);
		SDL_RenderCopy(renderer, texture_map["instruct_font_active"], nullptr, &instruct_font_rect);
	}
	else
	{
		SDL_RenderCopy(renderer, texture_map["button_bg"], nullptr, &instruct_button_rect);
		SDL_RenderCopy(renderer, texture_map["instruct_font"], nullptr, &instruct_font_rect);
	}

	SDL_RenderPresent(renderer);
}

