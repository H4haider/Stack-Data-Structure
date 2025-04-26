#pragma once
#include "AbstractStack.h"
template <typename T>
class MyStack :public AbstractStack<T>
{
	T* MinStack;
public:
	MyStack(int m) : AbstractStack<T>(m) {
		MinStack = new T[m];
	}

	void push(T value) override {
		if (!isFull()) {
			AbstractStack<T>::arr[AbstractStack<T>::csize] = value;

			if (AbstractStack<T>::csize == 0)
				MinStack[0] = value;
			else {
				if (value < MinStack[AbstractStack<T>::csize - 1])
					MinStack[AbstractStack<T>::csize] = value;
				else
					MinStack[AbstractStack<T>::csize] = MinStack[AbstractStack<T>::csize - 1];
			}

			AbstractStack<T>::csize++;
		}
		else {
			cerr << "Stack is Full!" << endl;
		}
	}
	T pop() {
		if (!isEmpty()) {
			return AbstractStack<T>::arr[AbstractStack<T>::csize--];
		}
	}
	T top() const {
		return AbstractStack<T>::arr[AbstractStack<T>::csize-1];
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

	T getMin() const {
		if (!isEmpty())
			return MinStack[AbstractStack<T>::csize - 1];

		cerr << "Stack is Empty!" << endl;
		return T();
	}
};

