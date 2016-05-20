// GradeBook.cpp
// This is the GradeBook class' object code
// GradeBook member functions are accessed and executed

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

 // constructor initializes GradeBook with grade counts
GradeBook::GradeBook(unsigned int aCnt, unsigned int bCnt, unsigned int cCnt, unsigned int dCnt, unsigned int fCnt)
{
	aCount = aCnt;
	bCount = bCnt;
	cCount = cCnt;
	dCount = dCnt;
	fCount = fCnt;
}

void GradeBook::inputGrades()
{
	char grade; // grade entered by user

	cout << "Enter the letter grades below. Enter the EOF character to end input." << endl;

	while ((grade = cin.get()) != EOF)
	{
		switch (grade)
		{
		case 'A':
		case 'a':
			aCount += 1; // increment As by 1
			break;
		case 'B':
		case 'b':
			bCount += 1; // increment Bs by 1
			break;
		case 'C':
		case 'c':
			cCount += 1; // increment Cs by 1
			break;
		case 'D':
		case 'd':
			dCount += 1; // increment Ds by 1
			break;
		case 'F':
		case 'f':
			fCount += 1; // increment Fs by 1
			break;
		case '\n':
		case '\t': // ignore newline, tab, and space characters
		case ' ':
			break;
		default: // catch all other characters
			cout << "Incorrect grade entered. Enter a new grade." << endl;
		}
	}
}

void GradeBook::displayGradeReport() // display grade summary
{
	cout << "Number of students who received each grade:" << endl;
	cout << "A: " << aCount << endl;
	cout << "B: " << bCount << endl;
	cout << "C: " << cCount << endl;
	cout << "D: " << dCount << endl;
	cout << "F: " << fCount << endl;
}

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

void GradeBook::determineClassAverage() // function to calculate the total score and average score of 10 students' quiz scores
{
	int totalScore = 0; // total scores of 10 students
	int quizScore = 0; // individual score of a student
	int gradeCount = 1; // student number

	while (gradeCount <= 10)
	{
		cout << "Enter quiz score: ";
		cin >> quizScore;
		totalScore += quizScore; // accumulate total score with each additional quiz score
		gradeCount += 1;  // increment grade count by 1
	}

	int averageScore = totalScore / gradeCount; // average score of 10 students

	// display results
	cout << "Total score = " << totalScore << endl;
	cout << "Average score = " << averageScore << endl;
}
