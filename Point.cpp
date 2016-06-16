// Point.cpp

#include "Point.h"

Point::Point()  //constructor
	:xCoordinate(0),  //initialize to origin point
	yCoordinate(0) {}

Point::~Point() {}  //destructor

std::ostream& operator<<(std::ostream& output, const Point& point)
{
	output << "(" << point.xCoordinate << ", " << point.yCoordinate << ")"; //print point

	return output;
}

std::istream& operator>>(std::istream& input, Point& point)
{
	input.ignore();  //skip left parentheses
	input >> point.xCoordinate;  //input xCoordinate
	input.ignore(2);  //skip comma and space
	input >> point.yCoordinate;   //input yCoordinate
	input.ignore();  //skip right parentheses

	return input;
}
