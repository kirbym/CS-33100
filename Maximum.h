// Maximum.h
// Function template maximum header

template <typename T> //or template < class T >
T maximum(T value1, T value2, T value3)
{
	T maximumValue = value1;  //assume value 1 is maximum

	//detemine whether value2 is greater than maximumValue
	if (value2 > maximumValue)
		maximumValue = value2;

	//determine whether value3 is greater than maximumValue
	if (value3 > maximumValue)
		maximumValue = value3;

	return maximumValue;
} //end function template


//****** function template with multiple data types
template <typename T1, typename T2, typename T3> //three different data types
void minimum(T1 value1, T2 value2, T3 value3) //function declaration
{
	if (value1 < value2 && value1 < value3) //case 1: value1 is absolute minimum
		cout << value1;

	else if (value2 < value1 && value2 < value3) //case 2: value2 is absolute minimum
		cout << value2;

	else if (value3 < value1 && value3 < value2) //case 3: value3 is absolute minimum
		cout << value3;

	else if (value1 == value2)  //case 4: value1 = value2 and both are less than value3
		cout << value1;

	else if (value1 == value3) //case 5: value1 = value3 and both are less than value2
		cout << value1;

	else if (value2 == value3) //case 6: value2 = value3 and both are less than value1
		cout << value3;
}
