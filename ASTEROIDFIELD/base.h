#ifndef _BASE_
#define _BASE_

#include "utils.h"

//SLEEP
unsigned const int SLEEP_VALUE_IN_MS = 10;		//Default: 10

//MODELS
const char BULLET_MODEL = '-';
const char HERO_MODEL = 'D';
const char ENEMY_MODEL = '@';
const char STAR_MODEL = '.';

//DIFICULTY
unsigned const int INITIAL_DIFFICULTY = 1;		//Default: 1
unsigned const int DIFFICULTY_UP_TIMER = 100;	//Default: 100

//NUMBER OF ENTITIES
unsigned const int NUMBER_OF_BULLETS = 10;		//Default: 10
unsigned const int NEW_ENEMY_NUMBER = 1;		//Default 1
unsigned const int MAX_OF_ENEMIES = 50;			//Default 50
unsigned const int NUMBER_OF_STARS = 30;		//Default: 30

//HERO STARTING ATRIBUTES
unsigned const int HERO_STARTING_X = 10;		//Default: 10
unsigned const int HERO_STARTING_Y = 10;		//Default: 10
unsigned const int HERO_SPEED = 1;				//Default: 1

//STAR STARTING ATRIBUTES
unsigned const int STAR_MIN_DURATION = 60;		//Default: 60
unsigned const int STAR_MAX_DURATION = 100;		//Default: 100

//GAME VALID POSITIONS 
unsigned const int POS_X_MIN = 1;				//Default: 1
unsigned const int POS_X_MAX = 78;				//Default: 78 
unsigned const int POS_Y_MIN = 4;				//Default: 4
unsigned const int POS_Y_MAX = 19;				//Default: 19

//KEY BINDINGS
const char CHAR_NOT_VALID = '!';
const char CHAR_MOVE_LEFT = 'a';	
const char CHAR_MOVE_RIGHT = 'd';
const char CHAR_MOVE_UP = 'w';
const char CHAR_MOVE_DOWN = 's';
const char CHAR_SHOT_BULLET = 'p';

//BORDER
unsigned const int BORDER_SIZE_X = 79;			//Default: 79
unsigned const int BORDER_SIZE_Y = 21;			//Default: 21
unsigned const int COUNTER_POSITION = 21;		//Default: 21

//ANIMATION FRAMES
static void GameOverFrame1(int x, int y)
{
	Color(4);
	GoToXY(x - 2, y - 1);
	printf(" *   *");
	GoToXY(x - 2, y);
	printf("   * ");
	GoToXY(x - 1, y + 1);
	printf("*   *");
}

static void GameOverFrame2(int x, int y)
{
	Color(6);
	GoToXY(x - 2, y - 1);
	printf("   *   ");
	GoToXY(x - 2, y);
	printf(" *   * ");
	GoToXY(x - 2, y + 1);
	printf("   *   ");
}

static void GameOverFrame3(int x, int y)
{
	Color(0);
	GoToXY(x - 2, y - 1);
	printf("       ");
	GoToXY(x - 2, y);
	printf("       ");
	GoToXY(x - 1, y + 1);
	printf("       ");
}

static void GameOverFrame4(int x, int y)
{
	Color(0);
	GoToXY(x - 2, y);
	printf("      ");
}

static void WelcomeScreenFrame1()
{
	Color(RandomInt(1, 14));
	GoToXY(0, POS_Y_MIN - 1);
	printf("                            You are entering the...\n");
	printf("\n");
	printf("\n");
	printf("       .d8b.  .d8888. d888888b d88888b d8888b.  .d88b.  d888888b d8888b.	\r");
	printf("       d8' `8b 88'  YP `~~88~~' 88'     88  `8D .8P  Y8.   `88'   88  `8D	\r");
	printf("       88ooo88 `8bo.      88    88ooooo 88oobY' 88    88    88    88   88	\r");
	printf("       88~~~88   `Y8b.    88    88~~~~~ 88`8b   88    88    88    88   88	\r");
	printf("       88   88 db   8D    88    88.     88 `88. `8b  d8'   .88.   88  .8D	\r");
	printf("       YP   YP `8888Y'    YP    Y88888P 88   YD  `Y88P'  Y888888P Y8888D'	\r");
	printf("\n");
	printf("                   d88888b d888888b d88888b db      d8888b.					\r");
	printf("                   88'       `88'   88'     88      88  `8D					\r");
	printf("                   88ooo      88    88ooooo 88      88   88					\r");
	printf("                   88~~~      88    88~~~~~ 88      88   88					\r");
	printf("                   88        .88.   88.     88booo. 88  .8D					\r");
	printf("                   YP      Y888888P Y88888P Y88888P Y8888D'					\r");
	printf("\n");
	printf("\n");
	printf("                            ...press any key to scape!");

}
//!ANIMATION FRAMES

//GLOBAL VARIABLE (Max Score File Saving not implemented)
static int maxScore = 0;

#endif