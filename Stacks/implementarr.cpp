#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int topIdx;
public:
    Stack() { topIdx = -1; }

    void push(int x) {
        if (topIdx == 99) { cout << "Overflow\n"; return; }
        arr[++topIdx] = x;
    }
    void pop() {
        if (topIdx == -1) { cout << "Underflow\n"; return; }
        topIdx--;
    }
    int top() { return arr[topIdx]; }
    bool isEmpty() { return topIdx == -1; }
};