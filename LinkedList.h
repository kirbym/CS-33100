/*
CS331 HW4Project
LinkedList.h
Do not change this header file.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename Type>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void insert(const Type &item, int);
	void remove();
	Type retrieve() const;
	int  gotoPrior();
	int  gotoNext();
	int  gotoBeginning();
	void clear();
	int  empty() const;

	LinkedList(const LinkedList &src);

protected:
	class ListElement
	{
	public:
		ListElement(const Type &item, ListElement* nextP) :
			element(item), next(nextP) {}
		Type element;
		ListElement* next;
	};
	ListElement *head;
	ListElement *cursor;
};

#endif
