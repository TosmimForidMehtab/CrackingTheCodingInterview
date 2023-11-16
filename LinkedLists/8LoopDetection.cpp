#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ================= BETTER (Floyd's Cycle detection
// algorithm)====================
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fastt = head;
    while (fastt and fastt->next) {
        fastt = fastt->next->next;
        slow = slow->next;

        if (slow == fastt)
            break;
    }

    slow = head;
    while (slow != fastt) {
        slow = slow->next;
        fastt = fastt->next;
    }
    return slow;
}

int32_t main() {
    fast;

    cout << endl;
    cin.get();
}