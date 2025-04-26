#include "MyStack.h"
int main() {
	MyStack<int> s(6);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.display();
	s.pop();
	s.display();




	system("pause");
	return 0;
}