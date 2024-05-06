#include"CommonFunction.h"

SDL_Window* common::set_window(const char* path, const char* title)
{
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		fail();
		fprintf(stderr, "Failed to create window. SDL Error : %s", SDL_GetError());
		resetColor();
		return nullptr;
	}
	else
	{
		success();
		fprintf(stdout, "Successfully created window.");
		resetColor();
		if (path == nullptr)
		{
			fail();
			fprintf(stderr, "Path %s for icon is invalid.", path);
			resetColor();
			return nullptr;
		}
		else
		{
			SDL_Surface* icon_surface = IMG_Load(path);
			SDL_SetWindowIcon(window, icon_surface);
			SDL_FreeSurface(icon_surface);
			success();
			fprintf(stdout, "Successfully created icon.");
			resetColor();
		}
	}
	return window;
}

SDL_Texture* common::load_texture(const char* tex_path, SDL_Renderer* renderer)
{
	if (tex_path == nullptr)
	{
		fail();
		fprintf(stderr, "%s image path is inavlid.", tex_path);
		resetColor();
		return nullptr;
	}
	if (renderer == nullptr)
	{
		fail();
		fprintf(stderr, "Renderer for path %s is invalid.", tex_path);
		resetColor();
		return nullptr;
	}
	SDL_Surface* img_surface = IMG_Load(tex_path);
	if (img_surface == NULL)
	{
		fail();
		fprintf(stderr, "Failed to load %s image. SDL Error : %s", tex_path, IMG_GetError());
		resetColor();
		return nullptr;
	}
	else
	{
		success();
		fprintf(stdout, "Successfully loaded %s image.", tex_path);
		resetColor();
		SDL_Texture* img_texture = SDL_CreateTextureFromSurface(renderer, img_surface);
		SDL_FreeSurface(img_surface);
		if (img_texture == NULL)
		{
			fail();
			fprintf(stderr, "Failed to create texture of image %s. SDL Error : %s", tex_path, SDL_GetError());
			resetColor();
			return nullptr;
		}
		else
		{
			success();
			fprintf(stdout, "Successfully created texture of image %s.", tex_path);
			resetColor();
			return img_texture;
		}
	}
}

SDL_Texture* common::load_font_texture(const char* font_path, std::string content, SDL_Renderer* renderer, SDL_Color color, int size)
{
	TTF_Font* font = TTF_OpenFont(font_path, size);
	if (font == nullptr)
	{
		fail();
		fprintf(stderr, "Failed to open font %s.SDL Error : %s", font_path, TTF_GetError());
		resetColor();
		TTF_CloseFont(font);
		return nullptr;
	}
	else
	{
		success();
		fprintf(stdout, "Sucessfully opened the font %s.", font_path);
		resetColor();
		SDL_Surface* text_surface = TTF_RenderText_Solid(font, content.c_str(), color);
		if (text_surface == nullptr)
		{
			fail();
			fprintf(stderr, "Failed to create image surface from %s. SDL Error : %s", font_path, TTF_GetError());
			resetColor();
			TTF_CloseFont(font);
			return nullptr;
		}
		else
		{
			success();
			fprintf(stdout, "Sucessfully created surface from %s.", font_path);
			resetColor();
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text_surface);
			SDL_FreeSurface(text_surface);
			TTF_CloseFont(font);
			if (texture == NULL)
			{
				fail();
				fprintf(stderr, "Failed to create texture from %s. SDL Error : %s", font_path, SDL_GetError());
				resetColor();
				return nullptr;
			}
			else
			{
				success();
				fprintf(stdout, "Successfully created texture from %s.", font_path);
				resetColor();
				return texture;
			}
		}
	}

}

void common::display_setter(SDL_Renderer* renderer, SDL_Texture* texture)
{
	static int wi = 60, hi = 60;
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect rect = { x,y,wi,hi };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_UP]) {
		hi ++;
	}
	if (keyboardState[SDL_SCANCODE_DOWN])
	{
		hi--;
	}
	if (keyboardState[SDL_SCANCODE_LEFT])
	{
		wi++;
	}
	if (keyboardState[SDL_SCANCODE_RIGHT])
	{
		wi--;
	}
	std::ofstream file("test_result.txt");
	file << "Rect { " << x << "," << y << "," << wi << "," << hi << " }";
	file.close();
}

bool common::mouse_collision_rect(SDL_Rect rect)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return (x >= rect.x && x <= (rect.x + rect.w) &&
		y >= rect.y && y <= (rect.y + rect.h));
}

void common::transition(SDL_Renderer* renderer, Transition& transition)
{
	if (transition.active)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, transition.alpha_channel);
		SDL_RenderFillRect(renderer, NULL);
		SDL_RenderPresent(renderer);
		transition.alpha_channel -= 5;
		if (transition.alpha_channel < 0)
		{
			transition.alpha_channel = 255;
			transition.alpha_channel = false;
		}
	}
}

std::string common::int_to_str(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str(); 
}

common::Transition::Transition()
{
	active = false;
	alpha_channel = 255;
}
