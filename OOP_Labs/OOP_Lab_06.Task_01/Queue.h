#pragma once

#include <iostream>
#include "QueueItem.h"

using namespace std;

class Queue
{
private:
	int size;

	QueueItem* head;
	QueueItem* tail;

	void DoCleanUp();
public:
	Queue();
	~Queue();

	void Push(int item);
	int Pop();
	int Peek() const;
	int GetSize() const;
	void Clear();
};

