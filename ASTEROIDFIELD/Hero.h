#ifndef _HERO_H_
#define _HERO_H_

#include "Entity.h"

class Hero : public Entity
{
	public:
		Hero();
		~Hero();
		void Run();
		void Run(const char moveDirection);
		void Shot();

	private:
		int _life;
		int _speed;
		bool ValidateMovement(const char direction);
		void MoveHero(const char direction);
};

#endif