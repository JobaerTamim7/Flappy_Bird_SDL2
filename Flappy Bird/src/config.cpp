#include"config.h"


void success() {
	int ca = 1;
	int fg = 32;
	printf("\033[%d;%dm", ca, fg);
}

void fail()
{
	int ca = 1;
	int fg = 31;

	printf("\033[%d;%dm", ca, fg);
}

void msg(){
	int ca = 1;
	int fg = 33;
	printf("\033[%d;%dm", ca, fg);
}

void resetColor() {
	printf("\033[0m\n\n");
}


