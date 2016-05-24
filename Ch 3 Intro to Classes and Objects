// Ch 3 Intro to Classes and Objects.cpp
// This is an introduction to defining a class, creating objects, and using member functions.
// Intended for use with "GradeBook.h" and "GradeBook.cpp"

#include "GradeBook.h" // needed for GradeBook class definition
#include <iostream>
#include <string>
using namespace std;


int main()
{
	GradeBook myGradeBook("Intro to C++ & Oop"); // create a GradeBook object named myGradeBook
	string nameOfCourse; // string to store course name

						 // display initial value for 'courseName'
	cout << "Initial value for course is: " << myGradeBook.getCourseName() << endl;

	cout << "Enter the name of the course: " << endl;
	getline(cin, nameOfCourse); // read in course name with spaces
	myGradeBook.setCourseName(nameOfCourse); // set the course name within the class
	cout << endl;

	myGradeBook.displayMessage(); // call object's dislayMessage function passing course name as argument

	system("pause");

	GradeBook gradebook1("Foundations of Abstract Mathematics"); // create object with initialized name
	GradeBook gradebook2;  // create object without initialized name
	string name2;  // name of course given to gradebook2 chosen by user

				   // using GradeBook class member functions
	cout << "gradebook1's name is " << gradebook1.getCourseName() << endl;
	gradebook1.displayMessage();

	cout << "Enter the name for gradebook2: ";
	getline(cin, name2);
	gradebook2.setCourseName(name2);
	cout << "gradebook2's name is " << gradebook2.getCourseName() << endl;
	gradebook2.displayMessage();

	system("pause");
	return 0;
}
