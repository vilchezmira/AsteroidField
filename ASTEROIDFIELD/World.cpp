#include <stdio.h>
#include "stdafx.h"
#include "World.h"
#include "utils.h"
#include "base.h"

/***************************** Public functions */
World::World()
{
	_isActive = false;
	_myHero = new Hero;
	_bulletsLeft = NUMBER_OF_BULLETS;
	_enemiesLeft = NEW_ENEMY_NUMBER;
	_starsLeft = NUMBER_OF_STARS;
	_difficulty = INITIAL_DIFFICULTY;
	_difficultyCounter = 0;
	_score = 0;
}

World::~World()
{
	delete _myHero;
	_myEnemies.clear();
	_myBullets.clear();
	_myStars.clear();
}

void World::Run(const char input)
{
	RunStars();
	GenerateEnemies();
	GenerateBullets(input);
	RunHero(input);
	HeroCollitions();
	RunBullets();
	Collitions();
	RunEnemies();
	Collitions();
	HeroCollitions();
	Print();
	UpdateScoreAndDifficulty();
	Sleep(SLEEP_VALUE_IN_MS);
}

bool World::IsActive()
{
	return _isActive;
}

void World::SwitchActivation()
{
	_isActive = !_isActive;
	if (_isActive == false)
		_bulletsLeft = 0;
}

void World::InitializeWorld()
{
	GenerateStars();
}

/*********************** Public Print functions */
void World::PrintWelcomeScreen()
{
	WelcomeScreenFrame1();
}

void World::PrintGameOverScreen()
{
	PrintTitle();
	PrintGameInfo();
	GoToXY(26, 11);
	printf("GAME OVER: PLAY AGAIN? (Y/N)");
}

void World::PrintGameOverAnimation()
{
	bool aux = true;
	if ((_myHero->_positionX > POS_X_MIN) && /*If Hero position = game borders*/
		(_myHero->_positionX < POS_X_MAX) && /*do not print the animation*/
		(_myHero->_positionY > POS_Y_MIN) && 
		(_myHero->_positionY < POS_Y_MAX))
	{
		for (int i = 0; i < 8; i++) /*GameOverFrameX at base.h*/
		{
			if (aux)
				GameOverFrame1(_myHero->_positionX, _myHero->_positionY);
			else
				GameOverFrame2(_myHero->_positionX, _myHero->_positionY);
			Sleep(100);
			aux = !aux;
		}
		GameOverFrame3(_myHero->_positionX, _myHero->_positionY);
	}
	else /*If Hero position just delete Hero*/
		GameOverFrame4(_myHero->_positionX, _myHero->_positionY);
}

/**************************** Generate functions */
void World::GenerateEnemies()
{
	if (_myEnemies.size()<MAX_OF_ENEMIES)
		if (RandomDecision(_difficulty))
			for (int i = 0; i < NEW_ENEMY_NUMBER; i++)
				_myEnemies.push_back(new Enemy);
}

void World::GenerateStars()
{
	for (int i = 0; i<_starsLeft; i++)
		_myStars.push_back(new Star);
}

void World::GenerateBullets(const char input)
{
	if (input == CHAR_SHOT_BULLET)
	if (_bulletsLeft > 0)
	{
		_myBullets.push_back(new Bullet(_myHero->_positionX+1, 
			_myHero->_positionY));
		_bulletsLeft--;
	}
}

/********************************* Run functions */
void World::RunHero(const char input)
{
	if (input!=CHAR_NOT_VALID)
		_myHero->Run(input);
}

void World::RunEnemies()
{
	for (unsigned int i = 0; i < _myEnemies.size(); i++) //Run all the Enemies
		_myEnemies[i]->Run();
	for (unsigned int i = 0; i < _myEnemies.size(); i++) //Delete out of limit Enemies
	{
		if (_myEnemies[i]->_positionX == (POS_X_MIN-1))
		{
			delete _myEnemies[i];
			_myEnemies.erase(_myEnemies.begin() + i);
		}
	}
}

void World::RunBullets()
{
	for (unsigned int i = 0; i < _myBullets.size(); i++) //Run all the Bullets
		_myBullets[i]->Run();
	for (unsigned int i = 0; i < _myBullets.size(); i++) //Delete out of limit Bullets
		if (_myBullets[i]->_positionX>= 79)
		{
			delete _myBullets[i];
			_myBullets.erase(_myBullets.begin() + i);
		}
}

void World::RunStars()
{
	for (unsigned int i = 0; i<_myStars.size(); i++) //Run all the Stars
		_myStars[i]->Run();
}

void World::UpdateScoreAndDifficulty()
{
	_score++;				/*score*/
	if (maxScore<_score)
		maxScore = _score;
							/*difficulty*/
	_difficultyCounter++;
	if ((_difficultyCounter / DIFFICULTY_UP_TIMER) == 1)
	{
		_difficultyCounter = 0;
		_difficulty++;
		if (_enemiesLeft<MAX_OF_ENEMIES)
			_enemiesLeft++;
	}
}

/******************************* Print functions */
void World::Print()
{
	PrintBlack();
	PrintTitle();
	for (int i = 0; i < 3; i++) /*trying to reduce the image blinking*/
	{							/*without develop a char buffer*/
		PrintStars();
		PrintHero();
		PrintBullets();
		PrintEnemies();
		PrintHero();
	}
	PrintGameInfo();
}

void World::PrintTitle()
{
	GoToXY(0, 0);
	Color(162);
	for(int i=0; i<(POS_Y_MIN - 2); i++)
		printf("                                                                                ");
	GoToXY(0, POS_Y_MIN - 2);
	printf("                A  S  T  E  R  O  I  D          F  I  E  L  D                   ");
	GoToXY(0, POS_Y_MIN - 1);
	Color(162);
	printf("________________________________________________________________________________");
	Color(7);
}

void World::PrintStars()
{
	for (unsigned int i = 0; i < _myStars.size(); i++)
	{
		GoToXY(_myStars[i]->_positionX,
			_myStars[i]->_positionY);
		Color(_myStars[i]->GetColor());
		printf("%c",STAR_MODEL);
		Color(7);
	}
	Color(7);
}

void World::PrintBullets()
{
	Color(10);
	for (unsigned int i = 0; i < _myBullets.size(); i++)
	{
		GoToXY(_myBullets[i]->_positionX,
			_myBullets[i]->_positionY);
		printf("%c",BULLET_MODEL);
	}
	Color(7);
}

void World::PrintEnemies()
{
	for (unsigned int i = 0; i < _myEnemies.size(); i++)
	{
		GoToXY(_myEnemies[i]->_positionX,
			_myEnemies[i]->_positionY);
		{
			Color(14);
			printf("%c",ENEMY_MODEL);
			Color(12); 
			printf("I=-");
		}
	}
	Color(7);
}

void World::PrintHero()
{
	Color(12);
	if (_myHero->_positionX > POS_X_MIN)
	{
		GoToXY(_myHero->_positionX - 2, _myHero->_positionY);
		printf("-=");
	}
	Color(10);
	GoToXY(_myHero->_positionX, _myHero->_positionY);
	printf("%c",HERO_MODEL);
	GoToXY(_myHero->_positionX+1, _myHero->_positionY);
	printf("=");
	Color(7);
}

void World::PrintGameInfo()
{
	GoToXY(0, COUNTER_POSITION-1);
	Color(172);
	printf("                                                                                ");
	Color(162);
	GoToXY(0, COUNTER_POSITION);
	Color(160);
	printf("  AMMO ");
	Color(172);
	for (int i = 0; i < _bulletsLeft; i++)
	{
		printf(" ");
		Color(204);
		printf(" ");
		Color(172);
	}
	for (unsigned int i = 0; i < (NUMBER_OF_BULLETS - _bulletsLeft); i++)
	{
		printf(" ");
		Color(34);
		printf(" ");
		Color(172);
	}
	for (int i=0; i<(33-NUMBER_OF_BULLETS);i++)
	{
		Color(162);
		printf(" ");
	}
	Color(160);
	printf(" RECORD ");
	Color(32);
	printf("%6i ", maxScore);
	Color(162);
	GoToXY(64, COUNTER_POSITION);
	Color(160);
	printf(" SCORE ");
	Color(32);
	printf("%6i ", _score);
	Color(162);
	printf("  ");
	GoToXY(0, COUNTER_POSITION+1);
	Color(172);
	printf("                                                                                ");
	GoToXY(0, COUNTER_POSITION+2);
	printf("                                                                                ");
	Color(7);
}

void World::PrintBlack()
{
	GoToXY(POS_X_MIN-1, POS_Y_MIN);
	for (int y = POS_Y_MIN; y <= POS_Y_MAX; y++)
	{
		printf("                                                                                ");
	}
}

/*************************** Collition functions */
void World::Collitions()
{
	bool flag = false;
	for (unsigned int b = 0; b < _myBullets.size(); b++) /*For each Bullet*/
	{
		flag = false;
		for (unsigned int e = 0; e < _myEnemies.size(); e++) /*If pos = an enemy*/
		{
			if ((_myEnemies[e]->_positionX == _myBullets[b]->_positionX)
				&& (_myEnemies[e]->_positionY == _myBullets[b]->_positionY))
			{
				delete _myEnemies[e]; /*Delete that enemy*/
				_myEnemies.erase(_myEnemies.begin() + e);
				//_enemiesLeft++;
				flag = true;
			}
		}
		if (flag) /*And delete that bullet*/
		{
			delete _myBullets[b];
			_myBullets.erase(_myBullets.begin() + b);
		}
	}
}

void World::HeroCollitions()
{
	for (unsigned int e = 0; e < _myEnemies.size(); e++)
	{
		if ((_myEnemies[e]->_positionX == _myHero->_positionX)
			&& (_myEnemies[e]->_positionY == _myHero->_positionY))
		{
			SwitchActivation();
		}
	}
}