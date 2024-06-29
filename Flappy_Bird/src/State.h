#pragma once

#include"MainMenu.h"
#include"Game.h"
#include"Instruct.h"
#include"ChoiceMenu.h"
#include"CommonFunction.h"

enum game_state
{
	MAIN_MENU,
	TUTORIAL,
	GAME,
	QUIT
};

void change_state_main_menu(game_state& , MainMenu&, ChoiceMenu&);
void change_state_game(game_state&, Game&);
void change_state_tutorial(game_state&, Instruct&);

