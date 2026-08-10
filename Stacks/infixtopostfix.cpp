#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) {
            result += c;  // operand goes straight to output
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // remove the '(' itself
        }
        else {  // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    cout << infixToPostfix("a+b*c");     // Output: abc*+
    cout << "\n";
    cout << infixToPostfix("(a+b)*c");   // Output: ab+c*
    return 0;
}