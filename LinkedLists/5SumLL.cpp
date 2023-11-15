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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// ================= BRUTE ====================
// Extract every number by iterating the lists and reverse them and add them and
// create and return a new LL based on that sum
// ================= BETTER ====================
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *newNode = new ListNode(-1);
    ListNode *p1 = l1, *p2 = l2, *curr = newNode;
    int carry = 0;
    while (p1 or p2) {
        int num1 = (p1 != NULL) ? p1->val : 0;
        int num2 = (p2 != NULL) ? p2->val : 0;

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
    }
    if (carry)
        curr->next = new ListNode(carry);
    return newNode->next;
}
// ================= BEST ====================

int32_t main() {
    fast;

    cout << endl;
    cin.get();
}