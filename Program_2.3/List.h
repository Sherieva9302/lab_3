#pragma once
#include "Iterator.h"


class LinkedList
{
private:


	class Node
	{
	public:
		Node(int data, Node* prev = nullptr, Node* next = nullptr)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		};
		~Node() {};

		int data;
		Node* prev;
		Node* next;
	};


	Node* head; 
	Node* tail; 
	

public:
	int size; 
	LinkedList();
	~LinkedList();

	void reset_list();
	void add_first(int newElem); //adding the first elem
	void push(int newElem);  //add in the beginning
	int pop();//delete first elem
	void clear(); //clears list
};
