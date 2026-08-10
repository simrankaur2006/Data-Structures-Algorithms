#include <iostream>
#include <algorithm>
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
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            // NOTE: for prefix conversion via this trick, use STRICT > 
            // instead of >= here, to correctly handle same-precedence operators
            while (!st.empty() && precedence(st.top()) > precedence(c)) {
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

string infixToPrefix(string s) {
    // Step 1: reverse the string
    reverse(s.begin(), s.end());

    // Step 2: swap ( and )
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: get postfix of modified string
    string postfix = infixToPostfix(s);

    // Step 4: reverse the postfix result
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    cout << infixToPrefix("a+b*c");     // Output: +a*bc
    cout << "\n";
    cout << infixToPrefix("(a+b)*c");   // Output: *+abc
    return 0;
}