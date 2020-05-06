#include "QueueInt.h"

void QueueInt::DoCleanUp()
{
	QueueItemInt* item = this->head;
	QueueItemInt* itemToDelete;
	while (item != nullptr)
	{
		itemToDelete = item;
		item = item->GetNext();
		delete itemToDelete;
	}
}

QueueInt::QueueInt()
{
	cout << "Queue::Queue()" << endl;

	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}


QueueInt::~QueueInt()
{	
	DoCleanUp();
	cout << "Queue::~Queue()" << endl;
}

void QueueInt::Push(int item)
{
	if (0 == this->size)
	{
		// adding the 1st item
		this->head = new QueueItemInt(item, nullptr);
		this->tail = head;
		this->size = 1;
	}
	else
	{
		// adding the 2nd, 3rd, ... elements
		QueueItemInt* newItem = new QueueItemInt(item, nullptr);
		this->tail->SetNext(newItem);
		this->tail = newItem;
		this->size += 1;
	}
}

int QueueInt::Pop()
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	if (1 == this->size)
	{
		QueueItemInt* item = this->head;
		this->head = nullptr;
		this->tail = nullptr;
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
	else
	{
		QueueItemInt* item = this->head;
		this->head = item->GetNext();
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
}

int QueueInt::Peek() const
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	QueueItemInt* item = this->head;
	int itemValue = item->GetItem();
	return itemValue;
}

int QueueInt::GetSize() const
{
	return this->size;
}

void QueueInt::Clear()
{
	DoCleanUp();
}
