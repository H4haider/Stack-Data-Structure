#pragma once
#include <iostream>
using namespace std;
template <typename T>
class AbstractStack {
protected:
	T* arr;
	int csize;
	int msize;
public:
	AbstractStack(int m) : msize(m) {
		arr = new T[msize];
		csize = 0;
	}
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractStack() {
		if (arr) delete[] arr;
	}
};

