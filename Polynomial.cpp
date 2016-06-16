// Polynomial.cpp

#include "Polynomial.h"
using namespace std;

istream& operator>>(istream& input, Polynomial& p)  //overloaded stream extraction operator
{
	char stream[50];  //character array to hold entered polynomial
	input.getline(stream, 49);   //extract the polynomial from the stream

	p = Polynomial(stream);   //send the "string" to the constructor to figure out coefficients

	return input;
}

ostream& operator<<(ostream& output, const Polynomial& p)  //overloaded stream insertion operator
{
	char sign = '+';  //sign of the polynomial term
	unsigned int firstTerm;  //to mark the first term of the polynomial

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (p.coefficients[subscript] != 0)  //finding the first coefficient not 0
		{
			if (p.coefficients[subscript] < 0)   //checking if the coefficient is negative and update sign accordingly
				sign = '-';

			firstTerm = subscript;  //identifying the first term of the polynomial

			break;  //exit for loop
		}
	}

	//display the first term of the polynomial (slightly different format than other terms)
	output << p.coefficients[firstTerm] << 'x' << firstTerm << ' ';

	//display subsequent terms of the polynomial (in a slightly different format than the first term)
	for (int subscript = (firstTerm - 1); subscript >= 0; subscript--)
	{
		if (subscript == 0)  //checking for the constant term
		{
			if (p.coefficients[subscript] == 0)  //skip if constant is 0
				continue;
			else if (p.coefficients[subscript] < 0)  //check if coefficient is negative
			{
				sign = '-';
				output << sign << ' ' << p.coefficients[subscript] * -1;   //display constant
			}
			else if (p.coefficients[subscript] > 0)  //outwise, coefficient must be positive
			{
				sign = '+';
				output << sign << ' ' << p.coefficients[subscript];  //display constant
			}
		}
		else   //display all 'x' terms
		{

			if (p.coefficients[subscript] == 0)  //if a coefficient is 0, skip it
				continue;
			else if (p.coefficients[subscript] < 0)  //determine if coefficient is negative and update sign
			{
				sign = '-';
				output << sign << ' ' << p.coefficients[subscript] * -1 << 'x' << subscript << ' ';
			}
			else if (p.coefficients[subscript] > 0)  //determine if coefficient is positive and update sign
			{
				sign = '+';
				output << sign << ' ' << p.coefficients[subscript] << 'x' << subscript << ' ';
			}
		}
	}

	return output;
}

Polynomial::Polynomial()   //default constructor
	:coefficients{},  //intialize coefficients array as empty (all 0's)
	inputPoly{}
{}   //empty body

Polynomial::Polynomial(const char* ps)  //user defined constructor
	: coefficients{},  //initialize coefficients array as empty (all 0's)
	inputPoly{ ps }   //initialize inputPoly with entered string value
{
	size_t found;   //used to find the positions of 'x9', 'x8', etc.
	size_t findSpace;  //used to find a space within the string values, determines whether to erase the space
	string check;    //used for a substring of the coefficient and is used to check the size of the coefficient value
	string coeff;   //used for a substring of the whole coefficient, with appropriate sign
	int substrStart;   //used to set the start position for the creation of the substrings
	int substrLen;   //used to set length of characters to make the substrings

	for (int i = 9; i >= 0; i--)   //cycle through each term of the polynomial
	{
		if (i == 0)  //find the constant in the polynomial
		{
			findSpace = inputPoly.rfind(' ');  //find the first space from the end of the string
			inputPoly.erase(findSpace, 1);  //erase the space; ( e.g.  "  - 13"  =>  "  -13" )
			this->coefficients[i] = stoi(inputPoly);  //convert string to integer and set the value in the coefficients array
		}
		else   //for every term with an 'x'
		{
			found = inputPoly.find("x" + to_string(i));  //find the position of 'x9', 'x8', etc.
			if (found != string::npos)   //checking if the 'x' term is found
			{
				if (found < 2)   //if the 'x' term is at the beginning of the string
				{
					substrStart = 0;  //position to start creating substring
					substrLen = 1;   //length of characters to make the substring
				}
				else   //otherwise, 'x' term is not at the beginning
				{
					substrStart = found - 2;  //substring start position
					substrLen = 2;   //substring character length
				}
				check = inputPoly.substr(substrStart, substrLen);   //create substring of the coefficient, used to check the size of the value of the coefficient
				if (stoi(check) < 10)	//if coefficient value is less than 10
				{
					if (found < 3)   //if coefficient is at the beginning of the string
					{
						substrStart = 0;  //substring start position
						substrLen = 2;   //substring character length
					}
					else   //otherwise, coefficient is not at the beginning of the string
					{
						substrStart = found - 3;   //substring start position
						substrLen = 3;   //substring character length
					}

					coeff = inputPoly.substr(substrStart, substrLen);  //create substring of coefficient with appropriate sign
					inputPoly.erase(substrStart, coeff.length() + 2);  //erase the coefficient from the polynomial string, including the sign of the coefficient and 'x' term
					findSpace = coeff.find(' ');  //determine if there is a space between the sign and the coefficient value
					if (findSpace != string::npos)  //checking if a space character was found
						coeff.erase(1, 1);   //if space character is found, erase it from coefficient substring
					this->coefficients[i] = stoi(coeff);  //convert string to integer and set the value in the coefficients array
				}
				else   //otherwise, coefficient value is greater than or equal to 10
				{
					if (found < 4)  //if coefficient is at the beginning of the string
					{
						substrStart = 0;  //substring start position
						substrLen = 3;  //substring character length
					}
					else  //otherwise, coefficient is not at the beginning of the string
					{
						substrStart = found - 4;  //substring start position
						substrLen = 4;   //substring character length
					}

					coeff = inputPoly.substr(substrStart, substrLen);  //create substring of coefficient with appropriate sign
					inputPoly.erase(substrStart, coeff.length() + 2);   //erase the coefficient from the polynomial string, including the sign of the coefficient and 'x' term
					findSpace = coeff.find(' ');  //determine if there is a space between the sign and the coefficient value
					if (findSpace != string::npos)  //checking if a space character was found
						coeff.erase(1, 1);   //if space character is found, erase it from coefficient substring
					this->coefficients[i] = stoi(coeff);  //convert string to integer and set the value in the coefficients array
				}
			}
		}
	}
}

Polynomial::Polynomial(const Polynomial& polyToCopy)    //copy constructor
	:coefficients{}
{
	for (int subscript = 9; subscript >= 0; subscript--)
	{
		this->coefficients[subscript] = polyToCopy.coefficients[subscript];  //transfer contents of input polynomial to new polynomial
	}
}

Polynomial::~Polynomial()   //destructor
{}

Polynomial Polynomial::operator+(const Polynomial& polyToAdd)  //overloaded addition operator
{
	Polynomial resultUnderAdd;  //resultant polynomial

	for (int subscript = 9; subscript >= 0; subscript--) //cycle through the polynomials and add corresponding terms
	{
		resultUnderAdd.coefficients[subscript] = this->coefficients[subscript] + polyToAdd.coefficients[subscript];
	}

	return resultUnderAdd;
}

Polynomial Polynomial::operator-(const Polynomial& polyToSubtract)  //overloaded subtraction operator
{
	Polynomial resultUnderSubtract; //resultant polynomial

	for (int subscript = 9; subscript >= 0; subscript--)  //cycle through the polynomials and subtract corresponding terms
	{
		resultUnderSubtract.coefficients[subscript] = this->coefficients[subscript] - polyToSubtract.coefficients[subscript];
	}

	return resultUnderSubtract;
}

Polynomial Polynomial::operator*(const Polynomial& polyToMultiply)  //overloaded multiplication operator
{
	unsigned int leftPolyDegree;  //degree of left polynomial (i.e. term with highest exponent)
	unsigned int rightPolyDegree;  //degree of right polynomial (i.e. term with highest exponent)
	Polynomial resultUnderMultiply;  //resulting polynomial if multiplication is successful

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (this->coefficients[subscript] != 0)
		{
			leftPolyDegree = subscript;    //find and identify the degree of the left polynomial
			break;
		}
	}

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (polyToMultiply.coefficients[subscript] != 0)
		{
			rightPolyDegree = subscript;   //find and identify the degree of the right polynomial
			break;
		}
	}

	for (int i = leftPolyDegree; i >= 0; i--)
	{
		for (int j = rightPolyDegree; j >= 0; j--)
		{
			if ((i + j) <= 9)  //only evaluate terms up to the power 'x9'
			{
				resultUnderMultiply.coefficients[i + j] += this->coefficients[i] * polyToMultiply.coefficients[j];  //multiply the polynomials, adding the like terms
			}
		}
	}

		return resultUnderMultiply;
	
}

Polynomial Polynomial::operator+=(Polynomial& polyToAdd)  //overloaded add and assign operator
{
	for (int subscript = 9; subscript >= 0; subscript--)  //cycle through the polynomials and add corresponding terms, assigning new value
	{															//to the polynomial object that called the function
		this->coefficients[subscript] += polyToAdd.coefficients[subscript];
	}

	return *this;   //return the polynomial object
}

Polynomial Polynomial::operator-=(Polynomial& polyToSubtract)   //overloaded subtract and assign operator
{
	for (int subscript = 9; subscript >= 0; subscript--)   //cycle through the polynomials and subtract corresponding terms, assigning new
	{															//value to the polynomial object that called the function
		this->coefficients[subscript] -= polyToSubtract.coefficients[subscript];
	}

	return *this;   //return the polynomial object
}

Polynomial Polynomial::operator*=(Polynomial& polyToMultiply)   //overloaded multiply and assign operator
{
	unsigned int leftPolyDegree;  //degree of left polynomial (i.e. term with highest exponent)
	unsigned int rightPolyDegree;  //degree of right polynomial (i.e. term with highest exponent)
	Polynomial temp = *this;

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (this->coefficients[subscript] != 0)
		{
			leftPolyDegree = subscript;    //find and identify the degree of the left polynomial
			break;
		}
	}

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (polyToMultiply.coefficients[subscript] != 0)
		{
			rightPolyDegree = subscript;   //find and identify the degree of the right polynomial
			break;
		}
	}

	for (int i = leftPolyDegree; i >= 0; i--)
	{
		for (int j = rightPolyDegree; j >= 0; j--)
		{
			if ((i + j) <= 9)
			{
				this->coefficients[i + j] += temp.coefficients[i] * polyToMultiply.coefficients[j];  //multiply polynomials, add like terms; assign to this polynomial object
			}
		}
	}

		return *this;
}

int& Polynomial::operator[](int term) //set the polynomial coefficient
{
	if (term < 0 || term >= POLYNOMIAL_SIZE)
		throw out_of_range{ "Subscript out of range" };

	return coefficients[term];
}

int Polynomial::operator[](int term) const  //get the polynomial coefficient
{
	if (term < 0 || term >= POLYNOMIAL_SIZE)
		throw out_of_range{ "Subscript out of range" };

	return coefficients[term];
}

int Polynomial::operator()(const int& value)   //overloaded function call operator
{
	int total = 0;  //accumulator for polynomial evalution

	for (int subscript = 9; subscript >= 0; subscript--)
	{
		if (this->coefficients[subscript] == 0)  //skip the term if the coefficient is 0
			continue;
		else
			total += this->coefficients[subscript] * pow(value, subscript);  //evaluate each term at the value and add to the total
	}

	return total;  //return total value of polynomial evaluated at input value
}
