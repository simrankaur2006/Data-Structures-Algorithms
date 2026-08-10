#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;      // first insertion
        rear = (rear + 1) % size;         // move rear circularly
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear) {              // only one element was left
            front = rear = -1;
        } else {
            front = (front + 1) % size;   // move front circularly
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);   // queue full now (size=5)

    q.dequeue();    // removes 1
    q.dequeue();    // removes 2

    q.enqueue(6);   // wraps around and fills index 0
    q.enqueue(7);   // wraps around and fills index 1

    cout << q.getFront();  // Output: 3
    return 0;
}