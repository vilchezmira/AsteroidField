#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"

class Bullet: public Entity
{
	public:
		Bullet(int x, int y);
		~Bullet();
		void Run();
};

#endif