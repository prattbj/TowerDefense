#include "Shock.h"
#include <iostream>
//Something the user can press
class Button : public Actor
{
public:
	//Construct it with a filename of what png will be used
	Button(std::string file, Vector2 point)
	{
		this->file = file.c_str();
		this->point = point;
	}
	//Return the rectangle of the button
	Rectangle getBox()
	{
		return Rectangle(point.x, point.y, 40, 40);
	}
};