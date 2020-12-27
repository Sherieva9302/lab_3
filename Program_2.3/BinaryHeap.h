#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class BinaryHeap {

	private:
		int* pointer_heap;
		int current_size;
		int max_size;

	public:
		BinaryHeap();
		~BinaryHeap();

		bool ChecKBinaryHeap();
		bool contains(int); // search for an element in the tree by key
		void insert(int);
		void swap(int i, int j);
		void siftUp(int index);
		void siftDown(int index);
		void heapify(int);  // binary heap ordering
		void remove(int); // deleting a heap element by key
		Iterator* create_dft_iterator(); // depth-first traverse
		Iterator* create_bft_iterator(); // breadth-first traverse

		class dft_iterator : public Iterator
		{
		private:
			int* pointer_heap;
			int current_size;
			int index;
			LinkedList stack;
		public:
			dft_iterator(int*, int, int);
			~dft_iterator();
			int next() override;
			bool has_next() override;
		};
		class bft_iterator : public Iterator
		{
		private:
			int* pointer_heap;
			int current_size;
			int index;
		public:
			bft_iterator(int*, int, int);
			~bft_iterator();
			int next() override;
			bool has_next() override;
		};


};




