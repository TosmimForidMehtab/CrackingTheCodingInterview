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
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};
// ================= BRUTE ====================
bool isPalindromeBrute(Node *head) {
    stack<Node *> visitedNodes;
    Node *cur = head;
    while (cur != NULL) {
        visitedNodes.push(cur);
        cur = cur->next;
    }

    cur = head;
    while (cur != NULL) {
        // compare node values
        Node *temp = visitedNodes.top();
        if (cur->data != temp->data) {
            return false;
        }
        visitedNodes.pop();
        cur = cur->next;
    }

    return true;
}
// ================= BETTER ====================
Node *findMid(Node *head) {
    if (!head or !head->next)
        return head;
    Node *slow = head, *fastt = head->next;
    while (fastt and fastt->next) {
        slow = slow->next;
        fastt = fastt->next->next;
    }
    return slow;
}

// Reveerse LL after mid
void reverseLL(Node *&head) {
    Node *prev = NULL, *curr = head, *later;
    while (curr) {
        later = curr->next;
        curr->next = prev;
        prev = curr;
        curr = later;
    }
    head = prev;
}

bool isPalindrome(Node *head) {
    // write your code here
    Node *h1 = head;
    Node *mid = findMid(head);
    Node *h2 = mid->next;
    mid->next = NULL;
    reverseLL(h2);
    while (h1 and h2) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}
// ================= Recursive 👾 ====================
bool isPalindromeHelper(Node **left, Node *right) {
    // base case
    if (right == NULL) {
        return true;
    }

    bool isSublistPalindrome = isPalindromeHelper(left, right->next);
    if (isSublistPalindrome == false) {
        return false;
    }

    if ((*left)->data != right->data) {
        return false;
    }

    // move left pointer to its next node
    *left = (*left)->next;
    return true;
}

bool isPalindromeRec(Node *head) {
    // call the recursive function
    return isPalindromeHelper(&head, head);
}
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}