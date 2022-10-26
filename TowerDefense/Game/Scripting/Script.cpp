#include "Script.h"
//Return a list of pointers to actions
std::list<Action*> Script::getActions(std::string group)
{
	return this->script[group];
}
//Add an action pointer to the list
void Script::addAction(std::string group, Action* action)
{
	this->script[group].push_back(action);
}