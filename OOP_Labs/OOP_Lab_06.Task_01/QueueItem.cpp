#include "QueueItem.h"

QueueItem::QueueItem(int item, QueueItem* next)
{
	printf("QueueItem::QueueItem(int %d, QueueItem* next)\n", item);

	this->item = item;
	this->next = next;
}

QueueItem::~QueueItem()
{
	cout << "QueueItem::~QueueItem() : " << this->item << endl;
}

const int QueueItem::GetItem() const
{
	return this->item;
}

QueueItem * QueueItem::GetNext() const
{
	return this->next;
}

void QueueItem::SetItem(const int item)
{
	this->item = item;
}

void QueueItem::SetNext(QueueItem * next)
{
	this->next = next;
}
