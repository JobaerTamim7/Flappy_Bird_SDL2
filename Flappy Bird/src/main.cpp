
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

	// WINDOW SECTION
	SDL_Window* window = common::set_window("asset/icon.png", "Flappy Bird");
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	common::Transition fade;
	game_state current_state = game_state::MAIN_MENU;
	bool run = true;

	while (run)
	{
		common::transition(renderer, fade);
		/**********---MAIN MENU---*************/
		if (current_state == game_state::MAIN_MENU) 
		{
			MainMenu menu(window);
			while (menu.get_main_menu_state()) {
				menu.render();
				menu.handle_event();
				SDL_Delay(16);
			}
			menu.free_memory();
			change_state_main_menu(current_state,menu,fade);

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
			change_state_tutorial(current_state, tutorial,fade);
		}
		/*---------------GAME---------------------*/
		else if (current_state == game_state::GAME)
		{
			Game game(window);
			while (game.t != 0)
			{
				game.start_count();
				game.t -= 1;
				SDL_Delay(1000);
			}
			while (game.get_main_menu_state() == false)
			{
				game.render();
				game.handle_event();
				SDL_Delay(16);
			}
			game.free_memory();
			change_state_game(current_state, game,fade);
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
	SDL_Quit();
	return 0;
}