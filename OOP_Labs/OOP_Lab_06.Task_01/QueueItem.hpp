#pragma once

#include <iostream>

using namespace std;

template <typename T> class QueueItem
{
private:
	T item;
	QueueItem<T>* next;
public:
	QueueItem(T item, QueueItem<T>* next);
	~QueueItem();

	const T GetItem() const;
	QueueItem<T>* GetNext() const;
	void SetItem(const T item);
	void SetNext(QueueItem<T>* next);
};

template <typename T> QueueItem<T>::QueueItem(T item, QueueItem<T>* next)
{
	printf("QueueItem<T>::QueueItem(T, QueueItem<T>* next)\n");

	this->item = item;
	this->next = next;
}

template <typename T> QueueItem<T>::~QueueItem()
{
	cout << "QueueItem::~QueueItem() : " << this->item << endl;
}

template <typename T> const T QueueItem<T>::GetItem() const
{
	return this->item;
}

template <typename T> QueueItem<T>* QueueItem<T>::GetNext() const
{
	return this->next;
}

template <typename T> void QueueItem<T>::SetItem(const T item)
{
	this->item = item;
}

template <typename T> void QueueItem<T>::SetNext(QueueItem<T>* next)
{
	this->next = next;
}
