#include "State.h"

void change_state_main_menu(game_state& state, MainMenu& obj,ChoiceMenu& obj2, common::Transition& fade)
{
	fade.active = true;
	if (obj.get_game_run_state() == true)
	{
		if (obj.get_instruct_state() == true)
		{
			state = game_state::TUTORIAL;
		}
		else if (obj2.get_frwrd() == true)
		{
			state = game_state::GAME;
		}
	}
	else if (obj2.get_back() == true)
	{
		state = game_state::MAIN_MENU;
	}
	else
	{
		state = game_state::QUIT;
	}
}

void change_state_game(game_state& state, Game& obj, common::Transition& fade)
{
	fade.active = true;
	if (obj.get_quit_state() == true)
	{
		state = game_state::QUIT;
	}
	else if (obj.get_main_menu_state() == true && obj.get_game_over() == true)
	{
		state = game_state::MAIN_MENU;
	}
	else if (obj.get_game_over() == false)
	{
		state = game_state::GAME;
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