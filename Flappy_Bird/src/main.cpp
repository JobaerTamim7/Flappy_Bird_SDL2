
#include"CommonFunction.h"
#include"MainMenu.h"
#include"Instruct.h"
#include"Game.h"
#include"Pipe.h"
#include"State.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_OpenAudio(16000, MIX_DEFAULT_FORMAT, 2, 2048);

	// WINDOW SECTION
	SDL_Window* window = common::set_window("asset/texture/icon.png", "Flappy Bird");
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	game_state current_state = game_state::MAIN_MENU;
	bool run = true;
	std::string bird;

	while (run)
	{
		/*---------MAIN MENU------------*/
		if (current_state == game_state::MAIN_MENU) 
		{
			MainMenu menu(window);
			while (menu.get_main_menu_state()) {
				menu.render();
				menu.handle_event();
				SDL_Delay(16);
			}
			menu.free_memory();
			Uint32 type_start_time = SDL_GetTicks();
			ChoiceMenu choice(window,type_start_time);
			while (choice.quit == false && menu.get_game_run_state() == true)
			{
				choice.render();
				choice.handle_event();
				SDL_Delay(16);
			}
			bird = choice.get_bird();
			choice.free_memory();
			change_state_main_menu(current_state,menu,choice);
		}
		/*----------------TUTORIAL---------------------*/
		else if (current_state == game_state::TUTORIAL) 
		{
			Instruct tutorial(window);
			while (tutorial.get_instruct_state()) {
				tutorial.render();
				tutorial.handle_event();
				SDL_Delay(16);
			}
			tutorial.free_memory();
			change_state_tutorial(current_state, tutorial);
		}
		/*---------------GAME---------------------*/
		else if (current_state == game_state::GAME)
		{
			Game game(window,bird);
			while (game.t != 0)
			{
				game.start_count();
				game.t -= 1;
				SDL_Delay(1000);
			}
			while (game.get_game_state()== true && game.get_re_state() == false)
			{
				game.render();
				game.handle_event();
				SDL_Delay(16);
			}
			game.free_memory();
			change_state_game(current_state, game);
			std::cout << game.get_game_state() << game.get_main_menu_state() << game.get_quit_state() << std::endl;
		}
		else if (current_state == game_state::QUIT) {
			run = false;
		}
		SDL_Delay(16);

	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}