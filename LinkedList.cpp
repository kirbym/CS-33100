// LinkedList.cpp

#include "LinkedList.h"
using namespace std;

template <typename Type>
LinkedList<Type>::LinkedList()  //constructor
	:head(nullptr), cursor(nullptr)
{}

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList &src)   //copy constructor
{
	if (!src.empty())
	{
		head = cursor = new ListElement(src.head->element, nullptr);
		ListElement* temp = new ListElement(src.head->element, src.head->next);

		while (temp->next != nullptr)
		{
			temp = temp->next;
			cursor->next = new ListElement(temp->element, temp->next);
			cursor = cursor->next;
		}
	}
	else
	{
		head = NULL;
		cursor = NULL;
	}
}

template <typename Type>
LinkedList<Type>::~LinkedList()  //destructor
{
	clear();
	delete(head);
	delete(cursor);
}

/*
template <typename Type>
void LinkedList<Type>::insert(const Type &item, int i)
{
	if (empty() != 0)  //if list is empty, make new element
	{
		head = cursor = new ListElement(item, nullptr);
	}
	else if (empty() == 0 && i == 0)  //insert element after current cursor
	{
		ListElement* temp = cursor->next;
		ListElement* listelement = new ListElement(item, temp);
		cursor->next = listelement;
	}
	else if (empty() == 0 && i == -1)   //insert element before current cursor
	{
		ListElement* temp = cursor;
		gotoPrior();
		ListElement* listelement = new ListElement(item, temp);
		cursor->next = listelement;
	}
}
*/
template <typename Type>
void LinkedList<Type>::insert(const Type &item, int i)
{
	ListElement* temp;
	if (head == NULL)
	{
		head = new ListElement(item, NULL);
		cursor = head;
	}
	else
	{
		if (i == 0)
		{
			if (cursor->next == NULL)
			{
				cursor->next = new ListElement(item, NULL);
			}
			else
			{
				temp = cursor->next;
				cursor->next = new ListElement(item, NULL);
			}
			cursor = cursor->next;
		}
		else if (i == -1)
		{
			ListElement newItem(item, cursor);
			gotoPrior();
			cursor->next = &newItem;
		}
	}
}

template <typename Type>
void LinkedList<Type>::remove()
{
	ListElement* del = nullptr;

	if (empty() == 0)
	{
		if (cursor == head) //deleting head element
		{
			del = head;
			head = cursor = del->next;
			delete (del);
		}
		else if (cursor->next == nullptr)  //deleting last element
		{
			del = cursor;
			gotoPrior();
			cursor->next = nullptr;
			delete (del);
			cursor = head;
		}
		else   //deleting current element
		{
			ListElement* temp = cursor->next;
			del = cursor;
			delete (del);
			gotoPrior();
			cursor->next = temp;
		}
	}
}

template <typename Type>
Type LinkedList<Type>::retrieve() const
{
	if (empty() == 0)
	{
		return cursor->element;
	}
	return NULL;
}

template <typename Type>
int LinkedList<Type>::gotoPrior()
{
	if (empty() == 0 && cursor != head)
	{
		ListElement* tempPtr = cursor;
		cursor = head;
		while (cursor->next != tempPtr)   //while (cursor != NULL && cursor->next != tempPtr)
		{
			gotoNext();
		}
		return 1;
	}
	else
		return 0;
}

template <typename Type>
int LinkedList<Type>::gotoNext()
{
	if (cursor->next != nullptr)
	{
		cursor = cursor->next;
		return 1;
	}
	else
		return 0;
}

template <typename Type>
int LinkedList<Type>::gotoBeginning()
{
	if (empty() == 0)
	{
		cursor = head;
		return 1;
	}
	else
		return 0;
}
/*
template <typename Type>
void LinkedList<Type>::clear()
{
	if (empty() == 0)
	{
		ListElement* currentPtr = cursor;
		ListElement* tempPtr = nullptr;

		while (currentPtr != nullptr)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
}
*/
template <typename Type>
void LinkedList<Type>::clear()
{
	if (empty() == 0)
	{
		cursor = head;
		ListElement* temp;
		temp = cursor;
		while (cursor != NULL)
		{
			temp = cursor;
			cursor = cursor->next;
			delete(temp);
		}
	}
	head = NULL;
	cursor = NULL;
}

template <typename Type>
int LinkedList<Type>::empty() const
{
	if (head == NULL) //list is empty
		return 1;
	else
		return 0;
}
