#include "Restart.h"

Restart::Restart(SDL_Window* window)
{
	renderer = SDL_GetRenderer(window);
	tex_map["h_score"] = common::load_font_texture("asset/font/roboto.ttf", "High Score : ", renderer, WHITE, 500);
	tex_map["score"] = common::load_font_texture("asset/font/roboto.ttf", "Your Score : ", renderer, WHITE, 500);
	tex_map["button_bg"] = common::load_texture("asset/texture/btn.png", renderer);
	tex_map["button_bg_active"] = common::load_texture("asset/texture/btn_active.png", renderer);
	tex_map["restart"] = common::load_font_texture("asset/font/minecraft.ttf", "Restart", renderer, BROWN, 500);
	tex_map["main_menu"] = common::load_font_texture("asset/font/minecraft.ttf", "Main Menu", renderer, BROWN, 500);
	tex_map["restart_active"] = common::load_font_texture("asset/font/minecraft.ttf", "Restart", renderer, GREEN, 500);
	tex_map["main_menu_active"] = common::load_font_texture("asset/font/minecraft.ttf", "Main Menu", renderer, GREEN, 500);
}

void Restart::render()
{
	SDL_RenderCopy(renderer, tex_map["h_score"], nullptr, &h_score_rect);
	SDL_RenderCopy(renderer, tex_map["score"], nullptr, &score_rect);
	if (common::mouse_collision_rect(menu_button_rect))
	{
		SDL_RenderCopy(renderer, tex_map["button_bg_active"], nullptr, &menu_button_rect);
		SDL_RenderCopy(renderer, tex_map["main_menu_active"], nullptr, &menu_rect);
	}
	else
	{
		SDL_RenderCopy(renderer, tex_map["button_bg"], nullptr, &menu_button_rect);
		SDL_RenderCopy(renderer, tex_map["main_menu"], nullptr, &menu_rect);
	}
	if (common::mouse_collision_rect(re_button_rect))
	{
		SDL_RenderCopy(renderer, tex_map["button_bg_active"], nullptr, &re_button_rect);
		SDL_RenderCopy(renderer, tex_map["restart_active"], nullptr, &re_rect);
	}
	else
	{
		SDL_RenderCopy(renderer, tex_map["button_bg"], nullptr, &re_button_rect);
		SDL_RenderCopy(renderer, tex_map["restart"], nullptr, &re_rect);
	}
}
