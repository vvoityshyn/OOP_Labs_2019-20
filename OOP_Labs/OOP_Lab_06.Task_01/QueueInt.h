#pragma once

#include <iostream>
#include "QueueItemInt.h"

using namespace std;

class QueueInt
{
private:
	int size;

	QueueItemInt* head;
	QueueItemInt* tail;

	void DoCleanUp();
public:
	QueueInt();
	~QueueInt();

	void Push(int item);
	int Pop();
	int Peek() const;
	int GetSize() const;
	void Clear();
};

