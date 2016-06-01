// Zipcode.cpp

#include "Zipcode.h"
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

Zipcode::Zipcode(int number, int zipArray[], int corArray[]) //constructor
	:numZipcode{ number },  //initialize numZipcode
	zipcode{ zipArray },   //initialize zipcode array; contain the input zipcodes
	correctionDigit{ corArray }  //initialize correctionDigit array; contain correction digits of corresponding zipcode
{	
}

Zipcode::~Zipcode()  //destructor
{
}

void Zipcode::readZipcode() //read in a number of zipcodes
{
	int inputZipcode = 0;  //zipcode input by user

	cout << "Input " << numZipcode << " zipcodes to create barcodes." << endl; //prompt user to input zipcodes

	for (size_t count = 0; count < numZipcode; count++)
	{
		cout << "Zipcode: ";
		cin >> inputZipcode;  //have user enter a zipcode
		while (inputZipcode < 0 || inputZipcode > 99999)  //validate that the zipcode is within range
		{
			cout << "Invalid zipcode. Enter a different zipcode." << endl;
			cout << "Zipcode: ";
			cin >> inputZipcode;
		}
		zipcode[count] = inputZipcode;  //assign each input zipcode a spot in the array
	}
}

void Zipcode::correctionDigitOf(int index)
{
	unsigned accumulator = 0;  //accumulator to sum up all digits of the zipcode

	for (size_t digitSelection = 1; digitSelection <= numZipcode; digitSelection++)
	{ //use extract member function to select the digit of the chosen zipcode and add digit to accumulator
		accumulator += extract(index, digitSelection);   //sum of all digits in the zipcode
	}
	
	if (accumulator % 10 == 0) //if accumulator is a multiple of 10, correction digit is 0
		correctionDigit[index] = 0;
	else
		correctionDigit[index] = (((accumulator / 10) + 1) * 10) - accumulator; //formula to find correction digit of corresponding zipcode
							//integer division ^
}

int Zipcode::extract(int index, int location)
{
	int fiveDigit = zipcode[index];  //pick a zipcode to break down with 'index' argument
	int fourDigit = fiveDigit % 10000;  //break down to four digits
	int threeDigit = fourDigit % 1000;  //break down to three digits
	int twoDigit = threeDigit % 100;  //break down to two digits
	int oneDigit = twoDigit % 10;   //break down to last digit; digit in ones place (right-most)

	int ten_thousands = fiveDigit / 10000;  //digit in ten thousands place (left-most)
	int thousands = fourDigit / 1000;  //digit in thousands place
	int hundreds = threeDigit / 100; //digit in hundreds place
	int tens = twoDigit / 10;   //digit in tens place

	switch (location)  //choosing which digit to return
	{
	case 1:  //location 1 corresponds to left-most digit
		return ten_thousands;
		break;
	case 2:  //second digit of zipcode
		return thousands;
		break;
	case 3:  //third digit of zipcode
		return hundreds;
		break;
	case 4:  //fourth digit of zipcode
		return tens;
		break;
	case 5:  //location 5 corresponds to right-most digit
		return oneDigit;
	}
}

void Zipcode::printBarcode()
{
	for (size_t zipSelection = 0; zipSelection < numZipcode; zipSelection++)
	{
		correctionDigitOf(zipSelection);  //find each correction digit of the zipcodes
	}
	
	//display zipcodes, correction digits, and encoded barcodes
	cout << endl << endl;
	cout << "Zipcode" << setw(15) << "Correction" << setw(12) << "Barcode" << endl;
	cout << setw(20) << "Digit" << endl;
	
	for (size_t count = 0; count < numZipcode; count++)
	{
		cout << setw(6) << zipcode[count] << setw(12) << correctionDigit[count] << setw(10);
		displayBarcode(count);
		cout << endl;
	}
}

void Zipcode::displayBarcode(int index)
{
	unsigned digitDisplay;  //digit to be encoded into barcode

	cout << "|";  //full-height bar on left side

	for (size_t digitSelection = 1; digitSelection <= 5; digitSelection++)
	{
		digitDisplay = extract(index, digitSelection); //extract individual digits from zipcode
		displayCode(digitDisplay); //display the barcode corresponding to the digit
	}

	cout << "|";  //full-height bar on right side
}

void Zipcode::displayCode(int digit)
{ //display digit encoded as full-height bars and half-height bars
	switch (digit)
	{
	case 0:
		cout << "||:::";  //0
		break;
	case 1:
		cout << ":::||";  //1
		break;
	case 2:
		cout << "::|:|";  //2
		break;
	case 3:
		cout << "::||:";  //3
		break;
	case 4:
		cout << ":|::|";  //4
		break;
	case 5:
		cout << ":|:|:";  //5
		break;
	case 6:
		cout << ":||::";  //6
		break;
	case 7:
		cout << "|:::|";  //7
		break;
	case 8:
		cout << "|::|:";  //8
		break;
	case 9:
		cout << "|:|::";  //9
	}
}
