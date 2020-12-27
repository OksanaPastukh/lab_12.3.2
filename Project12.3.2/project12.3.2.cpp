#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

struct Elem
{
	Elem* next,
		* prev;
	int info;
};
void enqueue(Elem*& first, Elem*& last, int size, int min_value, int max_value, int i)
{
		int ElemInfo = min_value + rand() % (max_value - min_value + 1);
		Elem* tmp = new Elem;
		tmp->info = ElemInfo;
		tmp->next = NULL;
		if (last != NULL)
		{
			last->next = tmp;
		}
		tmp->prev = last;
		last = tmp;
		if (first == NULL)
		{
			first = tmp;
		}
		if (i < size - 1)
		{
			enqueue(first, last, size, min_value, max_value, i + 1);
		}

}
void Print(Elem* current)
{
	if (current == NULL)
	{
		return;
	}
	cout << current->info << " ";
	if (current->next != NULL)
	{
		Print(current->next);
	}
	else
	{
		cout << endl;
	}
}
void Change(Elem* &start)
{

	if (start == NULL || start->next == NULL)
	{
		return;
	}
	Elem* current = start;
	Elem* next = current->next;
	Elem* tmp = current->prev;
     //change
		if (current->prev != NULL)
		{
			current->prev->next = next;
		}
		if (next->next != NULL)
		{
			next->next->prev = current;
		}
		current->prev = current->next;
		current->next = next->next;
		next->next = next->prev;
		next->prev = tmp;
		// цикл
		Change(current->next);
		// для першої ітерації 
		if (next->prev == NULL)
		{
			start = next;
	    }
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* first = NULL,
		* last = NULL;
	int size;
	cout << "Розмір черги : "; cin >> size;
	int min_value = 0;
	int max_value = 10;
	enqueue(first, last, size, min_value, max_value, 0);// create
	Print(first);
	Change(first);
	Print(first);
	return 0;
}