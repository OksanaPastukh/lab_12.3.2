#include "pch.h"
#include "CppUnitTest.h"
#include "../Project12.3.2/project12.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1232
{
	TEST_CLASS(UnitTest1232)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int const N = 10;
			int arr[N] = { 1,2,3,4,5,6,7,8,9,10};
			int result[N] = { 2,1,4,3,6,5,8,7,10,9};
			Elem* first = new Elem;
			first->info = arr[0];
			first->next = NULL;
			first->prev = NULL;
			Elem* last = first;
			for (int i = 1; i < N; i++)
			{
				Elem* elem = new Elem;
				elem->info = arr[i];
				elem->next = NULL;
				elem->prev = last;
				last->next = elem;
				last = elem;
			}
			Change(first);
			Elem* elem = first;
			for (int i = 0; i < N; i++)
			{
				Assert::AreEqual(elem->info, result[i]);
				elem = elem->next;
			}
		}
		TEST_METHOD(TestMethod2)
		{
			int const N = 5;
			int arr[N] = { 1,2,3,4,5 };
			int result[N] = { 2,1,4,3,5 };
			Elem* first = new Elem;
			first->info = arr[0];
			first->next = NULL;
			first->prev = NULL;
			Elem* last = first;
			for (int i = 1; i < N; i++)
			{
				Elem* elem = new Elem;
				elem->info = arr[i];
				elem->next = NULL;
				elem->prev = last;
				last->next = elem;
				last = elem;
			}
			Change(first);
			Elem* elem = first;
			for (int i = 0; i < N; i++)
			{
				Assert::AreEqual(elem->info, result[i]);
				elem = elem->next;
			}
		
		}
	};
}
