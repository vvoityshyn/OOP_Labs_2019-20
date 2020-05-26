#pragma once

#include <iostream>
#include "Queue.hpp"

using namespace std;

template <typename T> class QueueIterator
{
private:
	Queue<T>* queue;
	QueueItem<T>* queueItem;

public:
	QueueIterator(Queue<T>* queue);
	QueueIterator(const QueueIterator<T>& queueIterator);
	~QueueIterator();

	bool HasNext() const;
	void Next();
	const T Item() const;

	QueueIterator<T>& operator=(const QueueIterator<T>& v);
};

template <typename T> QueueIterator<T>::QueueIterator(Queue<T>* queue)
{
	cout << "QueueIterator<T>::QueueIterator(Queue<T>* queue)" << endl;
	this->queue = queue;
	this->queueItem = nullptr;
}

template <typename T> QueueIterator<T>::QueueIterator(const QueueIterator<T>& queueIterator)
{
	cout << "QueueIterator<T>::QueueIterator(const QueueIterator<T>& queueIterator)" << endl;
	this->queue = queueIterator.queue;
	this->queueItem = queueIterator.queueItem;
}

template <typename T> QueueIterator<T>::~QueueIterator()
{
	cout << "QueueIterator<T>::~QueueIterator()" << endl;
}

template <typename T> QueueIterator<T>& QueueIterator<T>::operator=(const QueueIterator<T>& iter)
{
	cout << "QueueIterator<T>& QueueIterator<T>::operator=(const QueueIterator<T>& iter)" << endl;
	this->queue = iter.queue;	
	this->queueItem = iter.item;
	return *this;
}

template <typename T> bool QueueIterator<T>::HasNext() const
{
	if (nullptr == this->queueItem && this->queue->GetSize() > 0)
	{
		return true;	
	}
	else if (nullptr != this->queueItem && nullptr != this->queueItem->GetNext())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T> void QueueIterator<T>::Next()
{
	if (!this->HasNext())
	{
		throw "There is not next element";
	}

	if (nullptr == this->queueItem)
	{
		this->queueItem = this->queue->head;
	}
	else
	{
		this->queueItem = this->queueItem->GetNext();
	}
}

template <typename T> const T QueueIterator<T>::Item() const
{
	if (nullptr == this->queueItem)
	{
		throw "No element";
	}

	return this->queueItem->GetItem();
}