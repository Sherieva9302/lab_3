#include "CppUnitTest.h"
#include "../Program_2.3/BinaryHeap.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:
		BinaryHeap *heap;

		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			heap = new BinaryHeap();
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete heap;
		}

		TEST_METHOD(CheckBinaryHeap_True)
		{
			heap->insert(3);
			heap->insert(2);
			heap->insert(1);
			Assert::IsTrue(heap->ChecKBinaryHeap());
		}
		TEST_METHOD(BinaryHeap_insert)
		{
			heap->insert(1);
			heap->insert(2);
			heap->insert(3);	
			Assert::IsTrue(heap->ChecKBinaryHeap());
		}
		TEST_METHOD(BinaryHeap_insert_overflow)
		{
			for(int i=0; i<101; i++)
				heap->insert(i);
		
			Assert::IsTrue(heap->contains(100));
		}

		TEST_METHOD(BinaryHeap_remove_error)
		{
			try
			{
				heap->insert(1);
				heap->insert(2);
				heap->remove(7);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Elem not found", e.what());
			}
		}

		TEST_METHOD(BinaryHeap_insert_remove_check)
		{
			for (int i = 10; i >= 0; i--)
				heap->insert(i);
			heap->remove(8);
			Assert::IsTrue(heap->ChecKBinaryHeap());
		}

		TEST_METHOD(BinaryHeap_insert_remove_elem)
		{
			for (int i = 10; i >= 0; i--)
				heap->insert(i);
			heap->remove(8);
			Assert::IsFalse(heap->contains(8));
		}


		TEST_METHOD(Iterator_bft_error)
		{
			try
			{
				heap->insert(1);
				Iterator* bft_iterator = heap->create_bft_iterator();
				bft_iterator->next(); 
				bft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}
			
			
		}

		TEST_METHOD(Iterator_bft)
		{
			int temp;
			for (int i = 5; i >=0; i--)
				heap->insert(i);

			Iterator* bft_iterator = heap->create_bft_iterator();
			for (int i = 0; i < 3; i++)
				temp = bft_iterator->next();
			
			Assert::AreEqual(temp, 3);

		}

		TEST_METHOD(Iterator_dft_error)
		{
			try
			{
				heap->insert(1);
				Iterator* dft_iterator = heap->create_dft_iterator();
				dft_iterator->next();
				dft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}


		}


		TEST_METHOD(Iterator_dft_left)
		{
			int temp;
			for (int i = 7; i >= 0; i--)
				heap->insert(i);

			Iterator* dft_iterator = heap->create_dft_iterator();
			for (int i = 0; i < 3; i++)
				temp = dft_iterator->next();

			Assert::AreEqual(temp, 4);

		}

		TEST_METHOD(Iterator_dft_right)
		{
			int temp;
			for (int i = 7; i >= 0; i--)
				heap->insert(i);

			Iterator* dft_iterator = heap->create_dft_iterator();
			for (int i = 0; i < 8; i++)
				temp = dft_iterator->next();

			Assert::AreEqual(temp, 1);

		}

	};
}