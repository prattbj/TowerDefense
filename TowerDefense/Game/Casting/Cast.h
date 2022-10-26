#ifndef CAST_H
#define CAST_H
#include <map>
#include "Actor.h"
#include <list>
#include <string>
/*
* Cast holds a list of actor pointers so that we can
* hold multiple different actors in the same list.
*/
class Cast {
public:
	//Returns a list of actor*s
	std::list<Actor*> getActors(std::string group);
	//Add an actor to the actor list
	void addActor(std::string group, Actor* actor);
	std::map<std::string, std::list<Actor*>> getCast()
	{
		return this->cast;
	};
	void destroyActor(std::string group, Actor* actor);
private:
	std::map<std::string, std::list<Actor*>> cast;

};

#endif