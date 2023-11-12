#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
// ================= CCI Version ====================
void deleteNode(Node *node) {
    // Write your code here.
    Node *nodeToDel = node->next;
    node->data = nodeToDel->data;
    node->next = nodeToDel->next;
    nodeToDel->next = NULL;
    delete nodeToDel;
}
// ================= Leetcode Version Delete exactly the mid====================
Node *deleteMiddle(ListNode *head) {
    if (!head or !head->next)
        return NULL;
    Node *slow = head, *fastt = head->next;
    while (fastt and fastt->next) {
        fastt = fastt->next->next;
        if (!fastt)
            break;
        slow = slow->next;
    }
    Node *nodeToDel = slow->next;
    slow->next = slow->next->next;
    nodeToDel->next = NULL;
    delete nodeToDel;
    return head;
}
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}