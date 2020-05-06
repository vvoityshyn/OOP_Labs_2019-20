#include "QueueItemInt.h"

QueueItemInt::QueueItemInt(int item, QueueItemInt* next)
{
	printf("QueueItem::QueueItem(int %d, QueueItem* next)\n", item);

	this->item = item;
	this->next = next;
}

QueueItemInt::~QueueItemInt()
{
	cout << "QueueItem::~QueueItem() : " << this->item << endl;
}

const int QueueItemInt::GetItem() const
{
	return this->item;
}

QueueItemInt * QueueItemInt::GetNext() const
{
	return this->next;
}

void QueueItemInt::SetItem(const int item)
{
	this->item = item;
}

void QueueItemInt::SetNext(QueueItemInt * next)
{
	this->next = next;
}
