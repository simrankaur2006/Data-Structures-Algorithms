#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);   // enqueue
    q.push(20);
    q.push(30);

    cout << q.front() << "\n";  // 10
    q.pop();                     // dequeue
    cout << q.front() << "\n";  // 20
    cout << q.size() << "\n";   // 2
    cout << q.empty() << "\n";  // 0 (false)
    return 0;
}