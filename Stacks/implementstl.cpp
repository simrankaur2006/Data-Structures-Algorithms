#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << "\n";  // 30
    st.pop();
    cout << st.top() << "\n";  // 20
    cout << st.size() << "\n"; // 2
    cout << st.empty() << "\n"; // 0 (false)
    return 0;
}