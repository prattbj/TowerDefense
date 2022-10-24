//Holds the X and Y values of an object
class Point {
public:
	//Default constructor
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	//X and Y value constructor
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	//Copy constructor
	Point(const Point * point)
	{
		this->x = point->getX();
		this->y = point->getY();
	}
	Point getPoint() const
	{
		return Point(this->x, this->y);
	}

	int getX() const
	{
		return this->x;
	}

	int getY() const
	{
		return this->y;
	}


private:
	int x;
	int y;
};