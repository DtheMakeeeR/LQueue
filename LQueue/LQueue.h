#pragma once
template<class T>
struct Node {
	T val;
	Node<T>* pNext;
	Node() : val(T()), pNext(nullptr) {}
};
template<class T>
class LQueue {
	Node<T>* pFirst, * pLast;
public:
	LQueue() : pFirst(nullptr), pLast(nullptr) {}
	LQueue(const LQueue& q);
	~LQueue();

	bool IsEmpty() { return pFirst == nullptr; }
	T Pop();
	void Push(T v);
	T PeekHead();
	T PeekTail();

	LQueue& operator =(const LQueue& q) const;
	LQueue& operator ==(const LQueue& q) const;
	LQueue& operator !=(const LQueue& q) const;
};

template<class T>
LQueue<T>::LQueue(const LQueue<T>& q) 
{
	Node<T>* tmp = q.pFirst;
	if (tmp == nullptr) pFirst = pLast = nullptr;
	else {
		Node<T>* previous = new Node<T>();
		previous->val = tmp->val;
		pFirst = pLast = previous;
		tmp = tmp->pNext;
		while (tmp != nullptr) {
			Node<T>* append = new Node<T>();
			append->val = tmp->val;
			pLast = append;
			previous->pNext = pLast;
			previous = previous->pNext;
			tmp = tmp->pNext;
		}
	}
}

template <class T>
LQueue<T>::~LQueue() {
	while (pFirst != nullptr) Pop();
}

template <class T>
T LQueue<T>::Pop() {
	if (IsEmpty()) throw - 1;
	Node<T>* tmp = pFirst;
	T res = tmp->val;
	pFirst = pFirst->pNext;
	delete tmp;
	return res;
}

template <class T>
void LQueue<T>::Push(T v) {
	Node<T>* res = new Node<T>();
	res->val = v;
	if (IsEmpty()) {
		pLast = pFirst = res;
	}
	else {
		pLast->pNext = res;
		pLast = res;
	}
}

template<class T>
T LQueue<T>::PeekHead()
{
	if (IsEmpty()) throw - 1;
	return pFirst->val;
}

template<class T>
T LQueue<T>::PeekTail()
{	
	if (IsEmpty()) throw - 1;
	return pLast->val;
}
