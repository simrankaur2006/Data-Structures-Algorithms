#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;
public:
    void push(int x) { v.push_back(x); }       // add at end
    void pop() { if (!v.empty()) v.pop_back(); }  // remove from end
    int top() { return v.back(); }
    bool isEmpty() { return v.empty(); }
};