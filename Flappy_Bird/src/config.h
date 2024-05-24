#pragma once

#include "CommonFunction.h"


//GAME VARIABLE
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 700;
const float GRAVITY = 0.3f;
const float MAX_SPEED = 4.0f;
const int SCROLL_SPEED = 4;

// COLOR SECTION
const SDL_Color BLACK = { 0,0,0,255 };
const SDL_Color WHITE = { 255,255,255,255 };
const SDL_Color TEST = { 255, 170, 80,0 };
const SDL_Color GREY = { 211,211,211,0 };
const SDL_Color GREEN = { 153,255,204,255 };
const SDL_Color BROWN = { 245, 245, 220,0 };

// MESSEGE SECTION
void msg();
void success();
void fail();
void resetColor();
