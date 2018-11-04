/*
 * linklist.h
 *
 *  Created on: Nov 3, 2018
 *      Author: $$$$$$$$$$$$$$$$$$$$
 */


#include <stdio.h>
#include <iostream>
#include <string>
#ifndef LINKLIST_H_
#define LINKLIST_H_

using namespace std;

class Linklist
{
private:
	struct Node
		{
			Node* linknext;
			Node* linkprevious;
			int data;
			//node constructor a.k.a instance of the struct
			Node(int n)
			{
				data = n;
				linknext = NULL;
				linkprevious = NULL;
			}
		};
	Node* head;
	Node* tail;
	Node* iterator;
	int size;
public:
	Linklist();

	void insertStart(int ndata);
	void insertEnd(int ndata);
	void print();
};

Linklist::Linklist()
{
	head = tail = iterator = NULL;
	size = 0;
}
void Linklist::insertStart(int data)
{
	if(size == 0)
	{
		Node* N = new Node(data);
		head = tail = N;
		size++;
	}
	else
	{
		Node* N = new Node(data);
		N->linknext = head;		// point to next node
		head->linkprevious = N; //	point to previous node
		head = N;
		size++;
	}
}

void Linklist::insertEnd(int data)
{
	if(size == 0)
	{
		Node* N = new Node(data);
		head = tail = N;
		size++;
	}
	else
	{
		Node* N = new Node(data);
		N->linkprevious = tail;	//point back to previous node
		tail->linknext = N;		//point forward to last node
		tail = N;
		size++;
	}
}

void Linklist::print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data;
		temp = temp->linknext;
		cout << endl;
	}
	cout << endl;
}
#endif /* LINKLIST_H_ */
