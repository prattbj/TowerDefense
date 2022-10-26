#include "Cast.h"
//Return a list of pointers to actors based on a group key
std::list<Actor*> Cast::getActors(std::string group)
{
	return this->cast[group];
}
//Add an actor based on a group key
void Cast::addActor(std::string group, Actor* actor)
{

	this->cast[group].push_back(actor);

}

//Destroy an actor
void Cast::destroyActor(std::string group, Actor* actor)
{
	cast[group].remove(actor);
}