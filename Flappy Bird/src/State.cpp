#include "State.h"

void change_state_main_menu(game_state& state, MainMenu& obj,common::Transition& fade)
{
	fade.active = true;
	if (obj.get_instruct_state() == true)
	{
		state = game_state::TUTORIAL;
	}
	else if (obj.get_game_run_state() == true)
	{
		state = game_state::GAME;
	}
	else
	{
		state = game_state::QUIT;
	}
}

void change_state_game(game_state& state, Game& obj, common::Transition& fade)
{
	fade.active = true;
	if (obj.get_main_menu_state() == true)
	{
		state = game_state::MAIN_MENU;
	}
	else
	{
		state = game_state::QUIT;
	}
}

void change_state_tutorial(game_state& state, Instruct& obj, common::Transition& fade)
{
	fade.active = true;
	if (obj.get_main_menu_state() == true)
	{
		state = game_state::MAIN_MENU;
	}
	else
	{
		state = game_state::QUIT;
	}
}