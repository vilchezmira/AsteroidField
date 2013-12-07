#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Hero.h"
#include "Star.h"
#include "World.h"
#include "InputManager.h"
#include "utils.h"
#include "base.h"

/*Aux Functions Declatarion*/
void WorldAndManagerInicialization();
void WorldAndManagerDestruction();
void GameIntroScreen();
void GameLoop();

/*Game Objects*/
World* gameWorld = NULL;
InputManager* userInputManager = NULL;

/*Main Function*/
int _tmain(int argc, _TCHAR* argv[])
{
	HideCursor();
	WorldAndManagerInicialization();
	GameLoop();
	WorldAndManagerDestruction();
	return 0;
}

/*Aux Functions Definition*/
void WorldAndManagerInicialization()
{
	gameWorld = new World();
	userInputManager = new InputManager(gameWorld);
	gameWorld->InitializeWorld();
	gameWorld->SwitchActivation();
}

void WorldAndManagerDestruction()
{
	delete gameWorld;
	delete userInputManager;
}

void GameIntroScreen()
{
	system("cls");
	while (!userInputManager->GetAnyKey())
		gameWorld->PrintWelcomeScreen();
}

void PlayAgain(char& aux, bool& wantPlay)
{
	aux = CHAR_NOT_VALID;
	while (aux == CHAR_NOT_VALID)
	{
		aux = userInputManager->GetUserYesNo();
		if (aux == 'y')
		{
			WorldAndManagerDestruction();
			WorldAndManagerInicialization();
		}
		else if (aux == 'n')
			wantPlay = false;
	}
}

void GameLoop()
{
	char aux = CHAR_NOT_VALID;
	bool wantPlay = true;

	while (wantPlay)
	{
		GameIntroScreen();
		/* Game Playing */
		while (gameWorld->IsActive())
			userInputManager->Run();
		/* Game Over */
		gameWorld->PrintGameOverAnimation();
		gameWorld->PrintGameOverScreen();
		/* Play Again ? */
		PlayAgain(aux, wantPlay);
	}
}

