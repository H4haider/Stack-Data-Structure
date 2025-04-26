#pragma once
#include "AbstractStack.h"
template <typename T>
class MyStack:public AbstractStack<T>
{
public:
	MyStack(int m) : AbstractStack<T>(m) {}

	void push(T value) {
		if (!isFull()) {
			AbstractStack<T>::arr[AbstractStack<T>::csize++] = value;
		}
	}
	T pop() {
		if (!isEmpty()) {
			return AbstractStack<T>::arr[AbstractStack<T>::csize--];
		}
	}
	T top() const {
		return AbstractStack<T>::arr[AbstractStack<T>::csize];
	}
	bool isEmpty() const {
		return AbstractStack<T>::csize == 0;
	}
	bool isFull() const {
		return AbstractStack<T>::csize == AbstractStack<T>::msize;
	}
	~MyStack() {}

	void display() const {
		cout << endl;
		for (int i = 0; i < AbstractStack<T>::csize; i++) {
			cout << AbstractStack<T>::arr[i] << " ";
		}
	}
};

