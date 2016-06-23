// LinkedList.cpp

#include "LinkedList.h"
using namespace std;

template <typename Type>
LinkedList<Type>::LinkedList()  //constructor
	:head(nullptr), cursor(nullptr)  //initialize pointers to null
{}

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList &src)   //copy constructor
{
	if (!src.empty())
	{
		head = cursor = new ListElement(src.head->element, nullptr);  //copy head element
		ListElement* temp = new ListElement(src.head->element, src.head->next);

		while (temp->next != nullptr)
		{
			temp = temp->next; //temp becomes next element in the chain
			cursor->next = new ListElement(temp->element, temp->next);   //copy the element
			cursor = cursor->next;   //advance cursor
		}
	}
	else  //otherwise, linked list is empty
	{
		head = nullptr;
		cursor = nullptr;
	}
}

template <typename Type>
LinkedList<Type>::~LinkedList()  //destructor
{
	clear();  //erase all elements
	delete(head);     //deallocate head and cursor from memory
	delete(cursor);
}

template <typename Type>
void LinkedList<Type>::insert(const Type &item, int i)   //insert a ListElement
{
	ListElement* temp;

	if (head == nullptr)   //if list is empty, create new element
	{
		head = new ListElement(item, nullptr);   //head and cursor have new element
		cursor = head;
	}
	else   //otherwise, list already has elements in it
	{
		if (i == 0)   //inserting element after the cursor
		{
			if (cursor->next == nullptr)
			{
				cursor->next = new ListElement(item, nullptr);  //create new element at end of the list
				cursor = cursor->next;    //current cursor then points to new element
			}
			else
			{
				temp = cursor->next;   //store the next pointer at current cursor position
				cursor->next = new ListElement(item, nullptr);   //create new element, which becomes next element
				cursor = cursor->next;  //point current cursor to new element
				cursor->next = temp;   //point the new element back to element(s) after it
			}
		}
		else if (i == -1)   //inserting element before the cursor
		{
			temp = cursor;   //current position
			cursor = new ListElement (item, nullptr);   //create new element
			cursor->next = temp;   //point new element to previous cursor element
		}
	}
}

template <typename Type>
void LinkedList<Type>::remove()    //remove the currently selected ListElement
{
	ListElement* del = nullptr;

	if (empty() == 0)   //if the list is not empty
	{
		if (cursor == head) //deleting head element
		{
			del = head;  //select element to be deleted
			head = cursor = del->next;   //change the head of the LinkedList with the lists next element
			delete (del);   //deallocate the memory for the head element
		}
		else if (cursor->next == nullptr)  //deleting last element
		{
			del = cursor;   //select element to be deleted
			gotoPrior();    //move cursor to previous element
			cursor->next = nullptr;    //set next element to null signaling the end of the list
			delete (del);   //deallocate the last element
			cursor = head;  //move the cursor to the head of the list
		}
		else   //deleting current element
		{
			ListElement* temp = cursor->next;  //store the elements after the cursor position
			del = cursor;   //select the element to be deleted
			delete (del);   //deallocate the element
			gotoPrior();   //move the cursor backwards
			cursor->next = temp;   //point the next pointer back to the stored elements
		}
	}
}

template <typename Type>
Type LinkedList<Type>::retrieve() const    //retrieves the element that the cursor currently points to
{
	if (empty() == 0)  //check if the list is empty
	{
		return cursor->element;   //get the element the cursor points to
	}
	return NULL;   //otherwise return nothing is list is empty
}

template <typename Type>
int LinkedList<Type>::gotoPrior()   //move the cursor to the previous element
{
	if (empty() == 0 && cursor != head)   //checking if the list is empty and that the head and cursor are not the same element
	{
		ListElement* tempPtr = cursor;   //store cursor's current position
		cursor = head;    //return cursor the beginning of the list
		while (cursor->next != tempPtr)
		{
			gotoNext();   //move the cursor through the list until 'next' reaches the stored cursor position
		}						//cursor is not positioned before the original cursor
		return 1;
	}
	else
		return 0;
}

template <typename Type>
int LinkedList<Type>::gotoNext()    //move cursor to the next list element
{
	if (cursor->next != nullptr)   //checking that cursor is not at the end of the list
	{
		cursor = cursor->next;  //advance the cursor to the next element
		return 1;
	}
	else
		return 0;
}

template <typename Type>
int LinkedList<Type>::gotoBeginning()    //move cursor to the very beginning of the Linked List
{
	if (empty() == 0)  //check that the list is not empty
	{
		cursor = head;  //move cursor to the head position
		return 1;
	}
	else
		return 0;
}

template <typename Type>
void LinkedList<Type>::clear()   //erase all elements from the list
{
	if (empty() == 0)  //check if the list is empty
	{
		cursor = head;   //move cursor to the head element
		ListElement* temp;

		while (cursor != nullptr)  //traverse the list
		{
			temp = cursor;   //select element to be erased
			cursor = cursor->next;    //advance the cursor to the next element
			delete(temp);   //delete the element
		}
	}
	head = nullptr;   //set head and cursor to null
	cursor = nullptr;
}

template <typename Type>
int LinkedList<Type>::empty() const     //check if the list is empty
{
	if (head == nullptr) //check if there is an element in the first position
		return 1;
	else
		return 0;
}
