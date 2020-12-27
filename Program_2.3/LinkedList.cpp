#include <stdexcept>
#include "List.h"

using namespace std;



void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 1;
}

void LinkedList::add_first(int newElem)
{
	head = new Node(newElem);
	tail = head;
}


void LinkedList::push(int newElem) // add at the beginning
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head->prev = new Node(newElem, nullptr, head);
		head = head->prev;

	}
	size++;

}



int LinkedList::pop() // delete first elem
{
	int temp;
	if (size == 0) {
		throw out_of_range("First elem not found");
	}

	temp = head->data;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		
		head = head->next;
		delete head->prev;
		size--;
	}
	return temp;
}


void LinkedList::clear()
{
	while (size > 0)
	{
		pop();
	}
}



LinkedList::~LinkedList()
{
	clear();
}
