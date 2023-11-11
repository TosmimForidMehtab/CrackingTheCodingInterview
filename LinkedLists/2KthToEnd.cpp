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

// ================= BETTER ====================
int findLen(Node *head) {
    int len{0};
    Node *curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }
    return len;
}
Node *nthNodeFromEndBetter(Node *head, int n) {
    // Write your code here
    int len = findLen(head);
    Node *curr = head;
    for (int i = 0; i < len - n; i++) {
        curr = curr->next;
    }
    return curr;
}
// ================= BEST ====================
Node *nthNodeFromEndBest(Node *head, int n) {
    // Write your code here
    Node *p1 = head, *p2 = head;

    while (n > 1) {
        p2 = p2->next;
        n--;
    }

    while (p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}