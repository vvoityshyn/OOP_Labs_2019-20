#include <iostream>
#include "QueueInt.h"

using namespace std;

void TestQueueInt();

int main()
{
	cout << "OOP_Lab_06.Task_01" << endl;

	TestQueueInt();

	system("pause");
	return 0;
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