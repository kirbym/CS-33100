//CS331 HW4Project
//LinkedTest.cpp


/*	NOTE for using the LinkedList Test Program

This program allows users testing their implementation interactively.
To properly use this code, you should add the following logics to your
LinkedList implementation.

Testing Insert Method:
The test program will check the functionality of insert method without the second parameter.
By defualt, insert the element after the cursor pointing element.
If you want to insert an element at different location (before or replace), you should properly
provide the second argument, then activate the insert method.
*/


#include <iostream>
#include "LinkedList.cpp"
using namespace std;

// Outputs the elements in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

template <typename Type>
void outList(LinkedList<Type> list)
{
	char tmp;

	if (list.empty())
		cout << "Empty list" << endl;
	else
	{
		list.gotoBeginning();
		do
		{
			tmp = list.retrieve();
			cout << tmp << " -> ";

		} while (list.gotoNext());
		cout << endl;
	}
}


void main()
{
	LinkedList<char> testList;		// Test list
	char testElement;			// List element
	char cmd;					// Input command

	cout << endl << "Commands:" << endl;
	cout << "  +   : Insert x after the current element" << endl;
	cout << "  -   : Remove the current element" << endl;
	cout << "  @   : Display the current element" << endl;
	cout << "  <   : Go to the beginning of the list" << endl;
	cout << "  N   : Go to the next element" << endl;
	cout << "  P   : Go to the prior element" << endl;
	cout << "  C   : Clear the list" << endl;
	cout << "  E   : Empty list?" << endl;
	cout << "  Q   : Quit the program" << endl;
	cout << endl;

	do
	{
		outList(testList);							// Output list
		cout << endl << "Command: ";				// Read command
		cin >> cmd;
		if ((cmd == '+'))// || (cmd == '-') || (cmd == '@'))
			cin >> testElement;

		switch (cmd)
		{
		case '+':
			cout << "Insert " << testElement << endl;
			testList.insert(testElement, 0);
			break;

		case '-':
			cout << "Remove the current element" << endl;
			testList.remove();
			break;

		case '@':
			cout << "Current element is "
				<< testList.retrieve() << endl;
			break;

		case '<':
			if (testList.gotoBeginning())
				cout << "Go to the beginning of the list" << endl;
			else
				cout << "Failed -- list is empty" << endl;
			break;

		case 'N': case 'n':
			if (testList.gotoNext())
				cout << "Go to the next element" << endl;
			else
				cout << "Failed -- either at the end of the list "
				<< "or the list is empty" << endl;
			break;

		case 'P': case 'p':
			if (testList.gotoPrior())
				cout << "Go to the prior element" << endl;
			else
				cout << "Failed -- either at the beginning of the "
				<< "list or the list is empty" << endl;
			break;

		case 'C': case 'c':
			cout << "Clear the list" << endl;
			testList.clear();
			break;

		case 'E': case 'e':
			if (testList.empty())
				cout << "List is empty" << endl;
			else
				cout << "List is NOT empty" << endl;
			break;

		case 'Q': case 'q':
			break;

		default:
			cout << "Inactive or invalid command" << endl;
		}
	} while ((cmd != 'Q') && (cmd != 'q'));
}
