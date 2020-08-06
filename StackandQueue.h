//#pragma once
//#include <iostream>
//using namespace std;
//// class Node
//template <class T>
//class Node {
//private:
//	T data;
//	Node <T>* pNext;
//public:
//	Node() {
//		this->pNext = NULL;
//	}
//	Node(T x) {
//		this->data = x;
//		this->pNext = NULL;
//	}
//	~Node() {
//		if (this->pNext != NULL)
//			delete this->pNext;
//	}
//	void setData(T x) {
//		this->data = x;
//	}
//	void setpNext(Node <T>* pNext) {
//		this->pNext = pNext;
//	}
//	T getData()const {
//		return this->data;
//	}
//	Node <T>* getpNext()const {
//		return this->pNext;
//	}
//};
//
//// class Stack
//template <class T>
//class Stack {
//private:
//	Node<T>* pHead;
//	Node<T>* pTail;
//public:
//	Stack() {}
//	~Stack() {}
//	void push(T x) {
//		Node<T>* p = new Node<T>(x);
//		if (p != NULL) {
//			if (this->pHead == NULL)
//				this->pHead = this->pTail = p;
//			else {
//				p->setpNext(this->pHead);
//				this->pHead = p;
//			}
//		}
//	}
//	void pop() {
//		if (this->pHead != NULL) {
//			Node <T>* p = NULL;
//			if (this->pHead == this->pTail) {
//				p = this->pHead;
//				this->pHead = this->pTail = NULL;
//			}
//			else {
//				p = this->pHead;
//				this->pHead = this->pHead->getpNext();
//				p->setpNext(NULL);
//			}
//			delete p;
//		}
//	}
//	T top()const {
//		if (this->pHead != NULL) {
//			return this->pHead->getData();
//		}
//	}
//	void sort() {
//		for (Node<T>* i = this->pHead; i != NULL; i = i->getpNext())
//			for (Node<T>* j = i->getpNext(); j != NULL; j = j->getpNext())
//				if (i->getData() > j->getData()) {
//					T temp = i->getData();
//					i->setData(j->getData());
//					j->setData(temp);
//				}
//	}
//	void print()const {
//		for (Node<T>* i = this->pHead; i != NULL; i = i->getpNext())
//			cout << i->getData() << '\t';
//	}
//};
//
//// class Queue
//template <class T>
//class Queue {
//private:
//	Node <T>* pHead;
//	Node <T>* pTail;
//public:
//	Queue() {}
//	~Queue() {}
//	void enqueue(T x) {
//		Node<T>* p = new Node<T>(x);
//		if (p != NULL) {
//			if (this->pHead == NULL)
//				this->pHead = this->pTail = p;
//			else {
//				this->pTail->setpNext(p);
//				this->pTail = p;
//			}
//		}
//	}
//	void dequeue() {
//		if (this->pHead != NULL) {
//			Node <T>* p = NULL;
//			if (this->pHead == this->pTail) {
//				p = this->pHead;
//				this->pHead = this->pTail = NULL;
//			}
//			else {
//				p = this->pHead;
//				this->pHead = this->pHead->getpNext();
//				p->setpNext(NULL);
//			}
//			delete p;
//		}
//	}
//	T front()const {
//		if (this->pHead != NULL) {
//			return this->pHead->getData();
//		}
//	}
//	T rear()const {
//		if (this->pTail != NULL) {
//			return this->pTail->getData();
//		}
//	}
//	void sort() {
//		for (Node<T>* i = this->pHead; i != NULL; i = i->getpNext())
//			for (Node<T>* j = i->getpNext(); j != NULL; j = j->getpNext())
//				if (i->getData() > j->getData()) {
//					T temp = i->getData();
//					i->setData(j->getData());
//					j->setData(temp);
//				}
//	}
//	void print()const {
//		for (Node<T>* i = this->pHead; i != NULL; i = i->getpNext())
//			cout << i->getData() << '\t';
//	}
//};