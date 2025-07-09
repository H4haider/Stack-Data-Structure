#include <iostream>
#include <Stack.h>
#include<Queue.h>

int main() {
    stack<int> s;
    queue<int> q;

    while (!q.isempty()) {
        int val = q.dequeue();
        s.push(val);

        while (!s.isempty()) {
            int top1 = s.pop();
            int top2 = s.pop();
            int top3 = s.pop();

            if (top1 > 0 && top2 > 0 && top3 < 0) {
                int res;
                if (top3 == -1) {
                    res = top1 + top2;
                }

                if (top3 == -2) {
                    res = top1 * top2;
                }

                if (top3 == -3) {
                    res = top1 / top2;
                }
                s.push(res);
            }

            else {
                s.push(top3);
                s.push(top2);
                s.push(top1);
                break;
            }
        }
    }

    if (!s.isempty()) {
        int res = s.top();
        cout << "Result: " << res << endl;
    }
    else {
        cout << "Stack is empty" << endl;
    }

    return 0;
}