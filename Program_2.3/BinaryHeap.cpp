#include "BinaryHeap.h"


BinaryHeap::BinaryHeap()
{
	current_size = -1; // current_size = max index in heap
	max_size = 100;
	pointer_heap = new int[max_size];
}

BinaryHeap::~BinaryHeap()
{
	delete[] pointer_heap;
}

bool BinaryHeap::ChecKBinaryHeap()
{
	int i = 0;
	while ((2 * i + 1) <= current_size)
	{
		if (((2 * i + 2) > current_size) && ((2 * i + 1) == current_size))
		{
			if (pointer_heap[i] <= pointer_heap[2 * i + 1]) return 0;
			
		}
		else
			if ((pointer_heap[i] <= pointer_heap[2 * i + 1]) || (pointer_heap[i] <= pointer_heap[2 * i + 2])) return 0;

		i++;
	}
	
	return 1;
}

bool BinaryHeap::contains(int key)
{
	for (int i = 0; i <= current_size; i++)
		if (pointer_heap[i] == key) return 1;
	return 0;
}

void BinaryHeap::swap(int i, int j)
{
	int temp_elem;
	temp_elem = pointer_heap[i];
	pointer_heap[i] = pointer_heap[j];
	pointer_heap[j] = temp_elem;

}



void BinaryHeap::siftUp(int index)
{
	int parent_index = index;
	if (parent_index % 2 == 1) parent_index--;
	else parent_index -= 2;
	parent_index /= 2;
	if (index>0)
		if (pointer_heap[parent_index] < pointer_heap[index])
		{
			swap(parent_index, index);
			siftUp(parent_index);
		}
		else
			siftDown(index);
}

void BinaryHeap::siftDown(int index)
{
	int left_children_index, right_children_index;
	left_children_index = index * 2 + 1;
	right_children_index = left_children_index + 1;

	if (index < current_size)
		if (left_children_index <= current_size)
		{
			if (pointer_heap[index] < pointer_heap[left_children_index])
			{
				swap(index, left_children_index);
				siftDown(left_children_index);
			}
			else
				if (right_children_index <= current_size)
					if (pointer_heap[index] < pointer_heap[right_children_index])
					{
						swap(index, right_children_index);
						siftDown(right_children_index);
					}
		}
}

void BinaryHeap::heapify(int index)
{
	if (index > 0)
		siftUp(index);
	else 
		if (index < current_size)
			siftDown(index);
}


void BinaryHeap::insert(int elem)
{
	int i;
	if (current_size + 1 == max_size)
	{
		int* temp_array = new int [max_size+100];
		for (i = 0; i <= current_size; i++)
			temp_array[i] = pointer_heap[i];
		delete[] pointer_heap;
		pointer_heap = temp_array;
		max_size += 100;
	}
	current_size++;
	pointer_heap[current_size] = elem;

	heapify(current_size);

}


void BinaryHeap::remove(int elem)
{
	int index=0;
	if (!contains(elem))
	{
		throw out_of_range("Elem not found");
	}
	else
	{
		while (pointer_heap[index] != elem)
			index++;

		swap(index, current_size);
		current_size--;
		heapify(index);

	}


}


BinaryHeap::bft_iterator::bft_iterator(int* pointer_heap, int current_size, int index)
{
	this->pointer_heap = pointer_heap;
	this->current_size = current_size;
	this->index = index;
}

BinaryHeap::bft_iterator::~bft_iterator()
{
	delete pointer_heap;
}

int BinaryHeap::bft_iterator::next()
{
	int temp;
	if (!has_next()) {
		throw out_of_range("No more elements");
	}
	temp = pointer_heap[index];
	index++;
	return temp;
}

bool BinaryHeap::bft_iterator::has_next()
{
	if (index == current_size) return 0;

	return 1;
}

Iterator* BinaryHeap::create_bft_iterator()
{
	return new bft_iterator(pointer_heap, current_size, 0);
}


BinaryHeap::dft_iterator::dft_iterator(int* pointer_heap, int current_size, int index)
{
	this->pointer_heap = pointer_heap;
	this->current_size = current_size;
	this->index = index;
}

BinaryHeap::dft_iterator::~dft_iterator()
{
	delete pointer_heap;
}

int BinaryHeap::dft_iterator::next()
{
	int temp, left_children_index, right_children_index;;
	if (!has_next()) {
		throw out_of_range("No more elements");
	}
	left_children_index = index * 2 + 1;
	right_children_index = left_children_index + 1;
	temp = pointer_heap[index];
	if (index == 0)
	{
		stack.size--; // because default stack.size = 1
		stack.push(0);
	}
	if (left_children_index <= current_size)
	{
		index = left_children_index;
		if (right_children_index <= current_size)
			stack.push(right_children_index);


	}
	else
	{
		index = stack.pop();
		
	}
	return temp;
}

bool BinaryHeap::dft_iterator::has_next()
{
	if (stack.size == 0) return 0;

	return 1;
}

Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(pointer_heap, current_size, 0);
}
