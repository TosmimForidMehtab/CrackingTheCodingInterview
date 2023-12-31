#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
// ================= Sorted LL ====================
ListNode *deleteDuplicatesSorted(ListNode *head) {
    if (!head or !head->next)
        return head;
    ListNode *curr = head;
    while (curr and curr->next) {
        if (curr->val == curr->next->val) {
            ListNode *nodeToDel = curr->next;
            curr->next = nodeToDel->next;
            delete nodeToDel;
        } else
            curr = curr->next;
    }
    return head;
}
// ================= Sorted LL(Recursive) ====================
ListNode *deleteDuplicatesSortedRec(ListNode *head) {
    if (head == NULL or head->next == NULL)
        return head;
    ListNode *newHead = deleteDuplicatesSortedRec(head->next);
    if (head->val == newHead->val)
        return newHead;

    head->next = newHead;
    return head;
}
// ================= Unsorted LL(Brute) ====================
ListNode *deleteDuplicatesBrute(ListNode *head) {
    if (head == NULL)
        return head;

    ListNode *curr = head;
    while (curr) {
        ListNode *temp = curr;
        while (temp->next != NULL) {
            if (curr->data == temp->next->data) {
                ListNode *next_next = temp->next->next;
                ListNode *nodeToDelete = temp->next;
                delete (nodeToDelete);
                temp->next = next_next;
            } else
                temp = temp->next;
        }
        curr = curr->next;
    }
    return head;
}
// ================ Unsorted LL (Better) ===================
// Sort the LL first and then aplly the algo for the sorted one

// ================ Unsorted LL (Best) ===================
ListNode *deleteDuplicatesBetter(ListNode *head) {
    if (!head)
        return head;

    unordered_set<int> seen;
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

int32_t main() {
    fast;

    cout << endl;
    cin.get();
}