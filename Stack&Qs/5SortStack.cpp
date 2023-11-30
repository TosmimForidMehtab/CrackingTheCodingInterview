#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;

// ================= BETT54ER ====================
void sortStack(stack<int> &st) {
    // Write your code here
    stack<int> temp;
    while (!st.empty()) {
        int poppedEle = st.top();
        st.pop();
        while (!temp.empty() and poppedEle < temp.top()) {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(poppedEle);
    }

    // 	Ascending
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
    //	For descending
    // swap(st, temp);
}
// ================= Recursion ====================
void insert(stack<int> &st, int temp) {
    if (st.empty() or st.top() <= temp) {
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
    return;
}
void sortStack(stack<int> &st) {
    if (st.size() == 1)
        return;

    int temp = st.top();
    st.pop();
    sortStack(st);

    insert(s, temp);
    return;
}
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}