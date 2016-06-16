// Point.h

#ifndef POINT_H  //include guard
#define POINT_H

#include <iostream>

class Point //class definition
{
	friend std::ostream& operator<<(std::ostream&, const Point&);  //overloaded stream insertion operator
	friend std::istream& operator>>(std::istream&, Point&);   //overloaded stream extraction operator
public:
	explicit Point();  //constructor
	~Point();  //destructor
private:
	int xCoordinate;  //x-coordinate for the point
	int yCoordinate;  //y-coordiante for the point
};

#endif
