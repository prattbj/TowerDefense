#pragma once
#ifndef SCRIPT_H
#define SCRIPT_H
#include <map>
#include <list>
#include <string>
#include "Action.h"
/*
* The script holds a list of pointers to all the actions that need to be run.
*/
class Script
{
public:
	std::list<Action*> getActions(std::string group);
	void addAction(std::string group, Action* action);
private:
	std::map<std::string, std::list<Action*>> script;
};
#endif
