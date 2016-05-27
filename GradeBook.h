// GradeBook.h
// Header file serves to define the class "GradeBook"
// This file also defines the constructor(s) as well as the member functions with function prototypes

#include <string>
#include <array>

class GradeBook // class definition
{
public:
	static const size_t students = 10; //constant -- number of students who took the test, public data member
		
	GradeBook(const std::string &, const std::array<int, students > &); //constructor initializes course name and array of grades
	
	void setCourseName(const std::string &); //function that sets the course name
	std::string getCourseName() const; //function that gets the course name
	void displayMessage() const; //function that displays a welcome message to the GradeBook user
	void processGrades() const; //perform operations on the grades data
	int getMinimum() const; //find minimum grade
	int getMaximum() const;  //find maximum grade
	double getAverage() const;  //determine average of the grades
	void outputBarChart() const;  //display bar chart for grade data
	void outputGrades() const;  //display grades

private:
	std::string courseName; // course name for this GradeBook
	std::array<int, students> grades;  //array to store student grades
}; // end class GradeBook
