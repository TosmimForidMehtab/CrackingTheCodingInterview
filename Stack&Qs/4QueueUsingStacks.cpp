#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
class MyQueue {
  public:
    stack<int> st1, st2;
    MyQueue() {}

    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        if (st1.empty())
            return -1;
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek() {
        if (st1.empty())
            return -1;
        return st1.top();
    }

    bool empty() { return st1.empty(); }
};
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}