#pragma once

#include <iostream>

using namespace std;

class QueueItemInt
{
private:
	int item;
	QueueItemInt* next;
public:
	QueueItemInt(int item, QueueItemInt* next);
	~QueueItemInt();

	const int GetItem() const;
	QueueItemInt* GetNext() const;
	void SetItem(const int item);
	void SetNext(QueueItemInt* next);
};