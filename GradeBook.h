// GradeBook.h
// Header file serves to define the class "GradeBook"
// This file also defines the constructors as well as the member functions with function prototypes

#include "stdafx.h"
#include <iostream>
#include <string>
// using namespace std; (not supposed to include this)
// thereby write std::cout, std::string, std::endl, etc.

class GradeBook // class definition
{
public:
	// constructor initializes GradeBook object without courseName
	explicit GradeBook();

	// constructor initializes courseName with string supplied as argument
	explicit GradeBook(std::string name);

	// function that sets the course name
	void setCourseName(std::string name);

	// function that gets the course name
	std::string getCourseName();

	// function that displays a welcome message to the GradeBook user
	void displayMessage();
private:
	std::string courseName; // course name for this GradeBook
}; // end class GradeBook
