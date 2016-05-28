// Zipcode.h

class Zipcode //class definition
{
public:
	Zipcode();  //constructor
	//destructor?

	void readZipcode(); //read 5 zipcodes and store in 'zipcode' array
	void correctionDigitOf(int index); //compute correction digit and store in corresponding
	//location of 'correctionDigit' array

	int extract(int index, int location); //extract individual digits of the zipcode
	//'index' represents the zipcode in the zipcode array; 'location' represents
	//the individual digit of a zipcode

	void printBarcode(); //display zipcodes, correction digits, and barcodes
	void displayBarcode(int index); //display entire barcode line
	void displayCode(int digit); //display single digit encoded in barcode format; 0 --> "||:::"

private:
	int numZipcode;   //total number of zip codes
	int *zipcode;   //pointer pointing to an array holding zip codes
	int *correctionDigit;  //pointer pointing to an array holding correction digits
};
