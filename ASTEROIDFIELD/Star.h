#ifndef _STAR_H_
#define _STAR_H_

#include "Entity.h"

class Star : public Entity
{
	public:
		Star();
		~Star();
		void Run();
		int GetColor();
	private:
		int _duration;
		int _color;
		void ResetStar();
};

#endif