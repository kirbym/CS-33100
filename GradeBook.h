// GradeBook.h
// Header file serves to define the class "GradeBook"
// This file also defines the constructors as well as the member functions with function prototypes

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

	// constructor initializes gradebook with grade counts
	explicit GradeBook(unsigned int aCnt, unsigned int bCnt, unsigned int cCnt, unsigned int dCnt, unsigned int fCnt);

	// function that sets the course name
	void setCourseName(std::string name);

	// function that gets the course name
	std::string getCourseName();

	// function that displays a welcome message to the GradeBook user
	void displayMessage();

	// function to calculate the total score and average score of 10 students' quiz scores
	void determineClassAverage();

	// function to input the grades
	void inputGrades();

	// function to dispay grade report
	void displayGradeReport();
private:
	std::string courseName; // course name for this GradeBook
	unsigned int aCount; // count of A grades
	unsigned int bCount; // count of B grades
	unsigned int cCount; // count of C grades
	unsigned int dCount; // count of D grades
	unsigned int fCount; // count of F grades
}; // end class GradeBook
