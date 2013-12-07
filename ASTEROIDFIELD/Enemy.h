#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Entity.h"

class Enemy : public Entity
{
	public:
		Enemy();
		~Enemy();
		void Run();
	private:
		int _life;
};

#endif