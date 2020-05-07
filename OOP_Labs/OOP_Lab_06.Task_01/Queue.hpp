#pragma once

#include <iostream>
#include "QueueItem.hpp"

using namespace std;

template <typename T> class Queue
{
private:
	int size;

	QueueItem<T>* head;
	QueueItem<T>* tail;

	void DoCleanUp();
public:
	Queue();
	~Queue();

	void Push(T item);
	T Pop();
	T Peek() const;
	int GetSize() const;
	void Clear();
	bool IsEmpty() const;
};

template <typename T> void Queue<T>::DoCleanUp()
{
	QueueItem<T>* item = this->head;
	QueueItem<T>* itemToDelete;
	while (item != nullptr)
	{
		itemToDelete = item;
		item = item->GetNext();
		delete itemToDelete;
	}
}

template <typename T> Queue<T>::Queue()
{
	cout << "Queue<T>::Queue()" << endl;

	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}


template <typename T> Queue<T>::~Queue()
{
	DoCleanUp();
	cout << "Queue<T>::~Queue()" << endl;
}

template <typename T> void Queue<T>::Push(T item)
{
	if (0 == this->size)
	{
		// adding the 1st item
		this->head = new QueueItem<T>(item, nullptr);
		this->tail = head;
		this->size = 1;
	}
	else
	{
		// adding the 2nd, 3rd, ... elements
		QueueItem<T>* newItem = new QueueItem<T>(item, nullptr);
		this->tail->SetNext(newItem);
		this->tail = newItem;
		this->size += 1;
	}
}

template <typename T> T Queue<T>::Pop()
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	if (1 == this->size)
	{
		QueueItem<T>* item = this->head;
		this->head = nullptr;
		this->tail = nullptr;
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
	else
	{
		QueueItem<T>* item = this->head;
		this->head = item->GetNext();
		int itemValue = item->GetItem();
		delete item;
		this->size -= 1;
		return itemValue;
	}
}

template <typename T> T Queue<T>::Peek() const
{
	if (this->size <= 0)
	{
		throw "No elements in the queue";
	}

	QueueItem<T>* item = this->head;
	int itemValue = item->GetItem();
	return itemValue;
}

template <typename T> int Queue<T>::GetSize() const
{
	return this->size;
}

template <typename T> void Queue<T>::Clear()
{
	DoCleanUp();
}

template <typename T> bool Queue<T>::IsEmpty() const
{
	return (0 == this->size);
}
