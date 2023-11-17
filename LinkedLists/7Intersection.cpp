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
    ListNode(int x) : val(x), next(NULL){} *
};
// ================= BRUTE ====================
int len(ListNode *head) {
    ListNode *curr = head;
    int ans = 0;
    while (curr) {
        ans++;
        curr = curr->next;
    }
    return ans;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = len(headA);
    int lenB = len(headB);

    int diff = abs(lenA - lenB);
    ListNode *ptr1 = headA, *ptr2 = headB;
    if (lenB > lenA) {
        ptr1 = headB;
        ptr2 = headA;
    }
    while (diff--) {
        ptr1 = ptr1->next;
        if (!ptr1)
            return NULL;
    }
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}
// ================= BETTER ====================

// ================= BEST ====================
ListNode *getIntersectionNodeBest(ListNode *headA, ListNode *headB) {
    ListNode *h1 = headA, *h2 = headB;
    while (h1 != h2) {
        h1 = (h1 == NULL) ? headB : h1->next;
        h2 = (h2 == NULL) ? headA : h2->next;
    }
    return h1;
}
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}