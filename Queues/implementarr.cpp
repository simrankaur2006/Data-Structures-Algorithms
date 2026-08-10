#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    void enqueue(int x) {
        if (rear == 99) { cout << "Overflow\n"; return; }
        if (front == -1) front = 0;   // first element being added
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) { cout << "Underflow\n"; return; }
        front++;
        if (front > rear) { front = rear = -1; }  // reset when empty
    }

    int getFront() { return arr[front]; }
    bool isEmpty() { return front == -1 || front > rear; }
};