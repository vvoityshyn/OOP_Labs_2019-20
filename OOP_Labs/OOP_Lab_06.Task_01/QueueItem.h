#pragma once

#include <iostream>

using namespace std;

class QueueItem
{
private:
	int item;
	QueueItem* next;
public:
	QueueItem(int item, QueueItem* next);
	~QueueItem();

	const int GetItem() const;
	QueueItem* GetNext() const;
	void SetItem(const int item);
	void SetNext(QueueItem* next);
};