#pragma once
#ifndef ACTOR_H
#define ACTOR_H
#include "raylib.h"
/*
* Contains attributes all actors will have.
*/
class Actor
{
public:
	Actor()
	{
		point = Vector2(0, 0);
		file = "Actor png";
	}
	//Return the position of the actor
	Vector2 getPoint() const
	{
		return point;
	}
	//Get the filename of the actor
	const char* getFile() const
	{
		return file;
	}
	//Set the positio of the actor
	void setPoint(Vector2 point)
	{
		this->point = point;
	}
	
protected:
	Vector2 point;
	const char* file;
	
};
#endif