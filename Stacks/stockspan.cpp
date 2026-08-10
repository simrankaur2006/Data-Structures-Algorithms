#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpanOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {
        // pop indices whose price <= current price (they're "beaten")
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // if stack empty -> no bigger price before -> span = i+1 (all days count)
        // else -> span = distance from last bigger price
        span[i] = st.empty() ? (i + 1) : (i - st.top());

        st.push(i);  // push current day's index
    }
    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockSpanOptimized(prices);
    for (int x : result) cout << x << " ";
    // Output: 1 1 1 2 1 4 6
    return 0;
}