#include "stdafx.h"
#include "Star.h"
#include "utils.h"
#include "base.h"

Star::Star()
{
	_positionX = RandomInt(POS_X_MIN, POS_X_MAX);
	_positionY = RandomInt(POS_Y_MIN, POS_Y_MAX);
	_duration=RandomInt(25,100);
	if (RandomDecision(50))
		_color = 4;
	else
		_color = 6;
}

Star::~Star()
{

}

void Star::Run()
{
	_duration--;
	if (_duration==0)
		ResetStar();
}

int Star::GetColor()
{
	return _color;
}

void Star::ResetStar()
{
	_positionX = RandomInt(POS_X_MIN, POS_X_MAX);
	_positionY = RandomInt(POS_Y_MIN, POS_Y_MAX);
	_duration = RandomInt(STAR_MIN_DURATION, STAR_MAX_DURATION);
	if (RandomDecision(50))
		_color = 4;
	else
		_color = 6;
}
