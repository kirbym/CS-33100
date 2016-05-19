// GradeBook.cpp
// This is the GradeBook class' object code
// GradeBook member functions are accessed and executed

#include "stdafx.h"
#include "GradeBook.h" // needed for class definition
#include <iostream>
#include <string>
using namespace std;

GradeBook::GradeBook() // constructor creates GradeBook object
{
	// empty body
}

GradeBook::GradeBook(string name) // constructor initializes courseName with string supplied as argument
	//: courseName(name) // member initializer to initialize courseName
{
	setCourseName(name);
}// end GradeBook constructor

void GradeBook::setCourseName(string name) // function that sets the course name
{
	// validation for courseName
	if (name.size() <= 25)
		courseName = name; // store the course name in the object if
		// length is less than 25 characters
	else if (name.size() > 25)
	{
		courseName = name.substr(0, 25); // set course name to first 25 characters
		// string.substr(start pos, length)

		cerr << "Name \"" << name << "\" exceeds maximum character length (25).\n"
			<< "Limiting courseName to first 25 characters.\n" << endl;
	}
} // end function setCourseName

string GradeBook::getCourseName() // function that gets the course name
{
	return courseName; // return the object's courseName
} // end function getCourseName

void GradeBook::displayMessage() // function that displays a welcome message to the GradeBook user
{
	cout << "Welcome to the Grade Book for \n" << getCourseName() << "." << endl;
} // end function displayMessage
