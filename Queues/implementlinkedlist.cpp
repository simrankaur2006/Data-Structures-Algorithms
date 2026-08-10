#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;
public:
    Queue() { front = rear = nullptr; }

    void enqueue(int x) {
        Node* newNode = new Node{x, nullptr};
        if (rear == nullptr) {           // queue was empty
            front = rear = newNode;
            return;
        }
        rear->next = newNode;   // link new node after current rear
        rear = newNode;         // update rear to new node
    }

    void dequeue() {
        if (front == nullptr) { cout << "Underflow\n"; return; }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;  // queue became empty
        delete temp;
    }

    int getFront() { return front->data; }
    bool isEmpty() { return front == nullptr; }
};