#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// clang-format on
using namespace std;
class MinStack {
  public:
    stack<int> s1, s2;
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if (s2.empty() or val <= s2.top())
            s2.push(val);
    }

    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return s2.top(); }
};

int32_t main() {
    fast

            cout
        << endl;
    cin.get();
}