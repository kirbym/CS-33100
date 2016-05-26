// GradeBook.cpp
// This is the GradeBook class' object code
// GradeBook member functions are accessed and executed

#include "GradeBook.h" // needed for class definition
#include <iostream>
#include <iomanip>
using namespace std;

GradeBook::GradeBook(const string &name, const array<int, students> &gradesArray)
: courseName(name), grades(gradesArray)// constructor initializes courseName and grades array
{	// empty body
}

void GradeBook::setCourseName(const string &name) // function that sets the course name
{
	courseName = name;
} // end function setCourseName

string GradeBook::getCourseName() const // function that gets the course name
{
	return courseName; // return the object's courseName
} // end function getCourseName

void GradeBook::displayMessage() const // function that displays a welcome message to the GradeBook user
{
	cout << "Welcome to the Grade Book for \n" << getCourseName() << "." << endl;
} // end function displayMessage

void GradeBook::processGrades() const //function to perform operations on the data
{
	outputGrades(); //display the grades array

	cout << setprecision(2) << fixed;
	cout << "\nClass average is " << getAverage() << endl; //find the average grade

	cout << "Lowest grade is " << getMinimum()  //find the minimum grade
		<< "\nHighest grades is " << getMaximum() << endl; //find the maximum grade

	outputBarChart();  //display bar chart of grade data
}

int GradeBook::getMinimum() const //function to find minimum grade
{
	int lowGrade = 100; //assume lowest grade is 100

	for (int grade : grades) //range-based-for loop to access grades
	{                       //'grade' in declaration accesses the element of the array
		if (grade < lowGrade) //without requiring the index number
			lowGrade = grade; 
	} //determine and return lowest grade

	return lowGrade;
}

int GradeBook::getMaximum() const  //function to find the highest grade
{
	int highGrade = 0; //assume highest grade is 0

	for (int grade : grades)  //range-based-for loop to access grades
	{                        //'grade' in declaration accesses the element of the array
		if (grade > highGrade) //without requiring the index number
			highGrade = grade;
	} //determine and return highest grade

	return highGrade;
}

double GradeBook::getAverage() const //function to find average grade
{
	int total = 0;  //accumulator

	for (int grade : grades) //range-based-for loop
		total += grade;  //add all grades together

	return static_cast<double>(total) / grades.size(); //return average grade
}

void GradeBook::outputBarChart() const  //display bar chart of grade distribution
{
	cout << "\nGrade Distribution:" << endl;

	//stores frequency of grades in each range of 10 grades
	const size_t frequencySize = 11;
	array<unsigned int, frequencySize > frequency = {};

	for (int grade : grades)
		++frequency[grade / 10]; //for each grade, increment corresponding frequency

	//for each grade frequency, print bar in chart
	for (size_t count = 0; count < frequencySize; ++count)
	{
		if (0 == count)
			cout << "  0-9: ";
		else if (10 == count)
			cout << "  100: ";
		else
			cout << count * 10 << "-" << (count * 10) + 9 << ": ";

		//print a bar of asterisks
		for (unsigned int stars = 0; stars < frequency[count]; ++stars)
			cout << '*';

		cout << endl;
	}
} //end function outputBarChart

void GradeBook::outputGrades() const //function to show all the grades
{
	cout << "\nThe grades are:\n\n";

	//access correct element of array and display grade
	for (size_t student = 0; student < grades.size(); ++student)
	{
		cout << "Student " << setw(2) << student + 1 << ": " << setw(3)
			<< grades[student] << endl;
	}
} //end function outputGrades
