#include "LQueue.h"
#include <iostream>
using namespace std;

void main() {
	int n = 5;
	LQueue<int> q1;
	for (size_t i = 0; i < n; i++)
	{
		q1.Push(i);
	}
	LQueue<int> q2(q1);
	q1.Push(10);
	q2.Push(20);
	for (size_t i = 0; i < n+1; i++)
	{
		cout << q1.Pop() << " "<< q2.Pop() << endl;

	}
}