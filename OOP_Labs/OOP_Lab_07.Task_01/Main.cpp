#include <iostream>
#include <queue>
//#include <algorithm>

using namespace std;

void TestQueue();
void TestVector();

int main()
{
	cout << "OOP_Lab_07.Task_01" << endl;

	// TestQueue();
	TestVector();

	system("pause");
	return 0;
}

void TestQueue()
{
	queue<char>* q = new queue<char>();

	q->push('a');
	q->push('b');
	q->push('c');
	q->push('d');
	q->push('e');

	cout << "Queue size: " << q->size() << endl;

	while (!q->empty())
	{
		cout << "Item : " << q->front() << endl;
		q->pop();
	}

	cout << "Queue size: " << q->size() << endl;

	delete q;
}

void TestVector()
{
	vector<int> v;

	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(11);

	cout << "Indexing: " << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << "[" << i << "] = " << v[i] << endl;
	}

	vector<int>::iterator iter;

	cout << "Iterators: " << endl;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		int item = (*iter);
		cout << item << endl;
	}

	for (iter = v.begin(); iter != v.end(); iter++)
	{
		int item = (*iter);
		*iter = item * 2;
	}

	cout << "Iterators (after * 2): " << endl;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		int item = (*iter);
		cout << item << endl;
	}

	bool isSorted = is_sorted(v.begin(), v.end());
	cout << "Sorted: " << isSorted << endl;

	vector<int>::iterator minIter = min_element(v.begin(), v.end());
	cout << "Min: " << (*minIter) << endl;

	cout << "Removing items from vector (size = " << v.size() << "): " << endl;
	while (!v.empty())
	{
		int item = v.back();
		cout << item << endl;
		v.pop_back();
	}
	cout << "Size: " << v.size() << endl;

}