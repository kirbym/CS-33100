// Polynomial.h

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <string>

class Polynomial
{
	friend std::istream& operator>>(std::istream&, Polynomial&);  //overloaded stream extraction operator
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);  //overloaded stream insertion operator
	friend void show(Polynomial*);  //friend show function

public:
	explicit Polynomial();   //default constructor
	Polynomial(const char*);   //user defined constructor
	Polynomial(const Polynomial&);   //copy constructor
	~Polynomial();   //destructor
	Polynomial operator+(const Polynomial&);  //overloaded addition operator; add two polynomials
	Polynomial operator-(const Polynomial&);  //overloaded subtraction operator; subtract two polynomials
	Polynomial operator*(const Polynomial&);  //overloaded multiplication operator; multiply two polynomials
	Polynomial operator+=(Polynomial&);  //overloaded add and assign operator
	Polynomial operator-=(Polynomial&);  //overloaded subtract and assign operator
	Polynomial operator*=(Polynomial&);  //overloaded multiply and assign operator
	int& operator[](int);  //overloaded subscript operator to set a coefficient of a polynomial
	int operator[](int) const;  //overloaded subscript operator to get the coefficient of a polynomial
	int operator()(const int&);  //overload function call operator to evaluate a polynomial

	static const unsigned int POLYNOMIAL_SIZE = 10;  //polynomials with terms up to x^9

private:
	std::array<int, POLYNOMIAL_SIZE> coefficients;  //coefficients of the polynomial
	std::string inputPoly;   //polynomial entered as a string
};

#endif
