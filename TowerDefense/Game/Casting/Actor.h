#pragma once
#ifndef ACTOR_H
#define ACTOR_H
#include "../Point.h"
/*
* Contains attributes all actors will have.
*/
class Actor
{
public:
	Point getPoint()
	{
		return this->point;
	}

protected:
	Point point;
};
#endif