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

	bool IsEmpty() const { return pFirst == nullptr; }
	T Pop();
	void Push(T v);
	T PeekHead();
	T PeekTail();

	LQueue& operator =(const LQueue& q);
	bool operator ==(const LQueue& q) const;
	bool operator !=(const LQueue& q) const;
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
	if (IsEmpty()) pLast = nullptr;//если это не сделать то будет ситуацию pFirst = nullptr pLast = указатель на удаленную память
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



template<class T>
LQueue<T>& LQueue<T>::operator =(const LQueue<T>& q){
	if (this == &q) return *this;
	while (!IsEmpty()) Pop();
	if (!q.IsEmpty()) {
		Node<T>* tmp = q.pFirst;
		while (tmp != nullptr) {
			Push(tmp->val);
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
bool LQueue<T>::operator==(const LQueue& q) const
{
	Node<T>* tmp1 = pFirst, * tmp2 = q.pFirst;
	while ((tmp1 != nullptr || tmp2 != nullptr) && (tmp1->val == tmp2->val)) {
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	if (tmp1 == nullptr && tmp2 == nullptr) return true;
	return false;
}

template<class T>
bool LQueue<T>::operator!=(const LQueue& q) const
{
	return !(*this == q);
}

