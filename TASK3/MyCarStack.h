#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyCarStack
{
protected:
	T* cars;
	int csize;
	int msize;
public:
	MyCarStack() :msize(8), csize(0) {
		cars = new T[msize];
	}

	void park(T val) {
		if (isFull()) {
			cerr << "Parking is Full!" << endl;
		}
		else {
			cars[csize++] = val;
		}
	}

	void display() const {
		for (int i = 0; i < csize; i++) {
			cout << cars[i] << " ";
		}
	}

	int countofcars() {
		return csize;
	}

    T* remove(T val) {
        if (isEmpty()) {
            cerr << "Parking lot is empty.\n";
            return nullptr;
        }

        T* temp = new T[msize];
        int tempSize = 0;
        bool found = false;
        T* removedCar = nullptr;

      
        while (csize > 0) {
            T topCar = cars[csize - 1];
            csize--;

            if (topCar == val) {
                removedCar = new T(topCar);
                found = true;
                break;
            }
            else {
                temp[tempSize++] = topCar;
            }
        }

        
        for (int i = tempSize - 1; i >= 0; i--) {
            cars[csize++] = temp[i];
        }

        delete[] temp;

        if (!found) {
            cerr << "Car " << val << " not found.\n";
            return nullptr;
        }

        return removedCar;
    }

    bool search(T val) const {
        for (int i = 0; i < csize; i++) {
            if (cars[i] == val)
                return true;
        }
        return false;
    }


};

