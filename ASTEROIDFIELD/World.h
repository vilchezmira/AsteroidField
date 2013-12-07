#ifndef _WORLD_H_
#define _WORLD_H_

#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Star.h"
#include <vector>

class World
{
	public:
		/***************************** Public functions */
		World();
		~World();
		void Run(const char input);
		bool IsActive();
		void SwitchActivation();
		void InitializeWorld();

		/*********************** Public Print functions */
		void PrintWelcomeScreen();
		void PrintGameOverScreen();
		void PrintGameOverAnimation();
	
	private:
		/************************************ Atributes */
		Hero* _myHero;
		std::vector<Enemy*> _myEnemies;
		std::vector<Bullet*> _myBullets;
		std::vector<Star*> _myStars;
		int _difficulty;
		int _enemiesLeft;
		int _bulletsLeft;
		int _starsLeft;
		int _score;
		int _difficultyCounter;
		bool _isActive;
	
		/**************************** Generate functions */
		void GenerateEnemies();
		void GenerateStars();
		void GenerateBullets(const char input);
	
		/********************************* Run functions */
		void RunHero(const char input);
		void RunEnemies();
		void RunBullets();
		void RunStars();
		void UpdateScoreAndDifficulty();
	
		/******************************* Print functions */
		void Print();
		void PrintTitle();
		void PrintStars();
		void PrintBullets();
		void PrintEnemies();
		void PrintHero();
		void PrintGameInfo();
		void PrintBlack();
	
		/*************************** Collition functions */
		void Collitions();
		void HeroCollitions();
};

#endif