#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;  // closing with nothing to match

            char topChar = st.top();
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[')) {
                st.pop();
            } else {
                return false;  // mismatch
            }
        }
    }
    return st.empty();  // true only if all matched
}

int main() {
    cout << isBalanced("{[()]}");  // 1 (true)
    cout << isBalanced("{[(])}");  // 0 (false)
    return 0;
}