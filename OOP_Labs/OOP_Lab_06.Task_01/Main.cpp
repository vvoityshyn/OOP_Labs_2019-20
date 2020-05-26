#include <iostream>
#include "Queue.hpp"
#include "QueueInt.h"
#include "QueueIterator.hpp"

using namespace std;

template <typename T> void TestQueue(const int n, const T* items);
void TestQueueChar();
void TestQueueInt();
void TestQueueIterator();

int main()
{
	cout << "OOP_Lab_06.Task_01" << endl;

	double items[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
	//TestQueue(6, items);

	//TestQueueChar();
	//TestQueueInt();

	TestQueueIterator();

	system("pause");
	return 0;
}

template <typename T> void TestQueue(const int n, const T* items)
{
	Queue<T>* q = new Queue<T>();

	for (int i = 0; i < n; i++)
	{
		q->Push(items[i]);
	}

	char item;

	while (!q->IsEmpty())
	{
		item = q->Pop();
		cout << "Pop: item - " << item << " | size - " << q->GetSize() << endl;
	}

	delete q;
}

void TestQueueChar()
{
	Queue<char>* q = new Queue<char>();

	q->Push('a');
	q->Push('b');
	q->Push('c');
	q->Push('d');
	q->Push('e');

	char item;

	while (!q->IsEmpty())
	{
		item = q->Pop();
		cout << "Pop: item - " << item << " | size - " << q->GetSize() << endl;
	}

	delete q;
}

void TestQueueInt()
{
	QueueInt* q = new QueueInt();

	q->Push(1);
	q->Push(2);
	q->Push(3);
	q->Push(4);
	q->Push(5);

	int item;

	item = q->Pop();
	printf("Pop: item - %d | size - %d\n", item, q->GetSize());
	item = q->Pop();
	printf("Pop: item - %d | size - %d\n", item, q->GetSize());
	item = q->Pop();
	printf("Pop: item - %d | size - %d\n", item, q->GetSize());
	item = q->Pop();
	printf("Pop: item - %d | size - %d\n", item, q->GetSize());
	item = q->Pop();
	printf("Pop: item - %d | size - %d\n", item, q->GetSize());

	delete q;
}

void TestQueueIterator()
{
	Queue<char>* q = new Queue<char>();

	q->Push('a');
	q->Push('b');
	q->Push('c');
	q->Push('d');
	q->Push('e');

	QueueIterator<char> iter = q->Iterator();

	cout << "Iterator: " << endl;
	while (iter.HasNext())
	{
		iter.Next();
		cout << iter.Item() << endl;
	}

	delete q;
}