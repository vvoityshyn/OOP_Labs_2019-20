#include "Queue.h"

void Queue::DoCleanUp()
{
	QueueItem* item = this->head;
	QueueItem* itemToDelete;
	while (item != nullptr)
	{
		itemToDelete = item;
		item = item->GetNext();
		delete itemToDelete;
	}
}

Queue::Queue()
{
	cout << "Queue::Queue()" << endl;

	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}


Queue::~Queue()
{	
	DoCleanUp();
	cout << "Queue::~Queue()" << endl;
}

void Queue::Push(int item)
{
	if (0 == this->size)
	{
		// adding the 1st item
		this->head = new QueueItem(item, nullptr);
		this->tail = head;
		this->size = 1;
	}
	else
	{
		// adding the 2nd, 3rd, ... elements
		QueueItem* newItem = new QueueItem(item, nullptr);
		this->tail->SetNext(newItem);
		this->tail = newItem;
		this->size += 1;
	}
}

int Queue::Pop()
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	if (1 == this->size)
	{
		QueueItem* item = this->head;
		this->head = nullptr;
		this->tail = nullptr;
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
	else
	{
		QueueItem* item = this->head;
		this->head = item->GetNext();
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
}

int Queue::Peek() const
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	QueueItem* item = this->head;
	int itemValue = item->GetItem();
	return itemValue;
}

int Queue::GetSize() const
{
	return this->size;
}

void Queue::Clear()
{
	DoCleanUp();
}
