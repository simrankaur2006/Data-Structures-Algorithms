#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* topNode;
public:
    Stack() { topNode = nullptr; }

    void push(int x) {
        Node* newNode = new Node{x, topNode};  // new node points to old top
        topNode = newNode;                      // new node becomes top
    }
    void pop() {
        if (topNode == nullptr) { cout << "Underflow\n"; return; }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    int top() { return topNode->data; }
    bool isEmpty() { return topNode == nullptr; }
};