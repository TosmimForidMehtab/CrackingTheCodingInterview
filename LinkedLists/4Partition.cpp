#include <bits/stdc++.h>
#define int long long
#define endl "\n"
// clang-format off
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// clang-format on
using namespace std;
template <typename T> class LinkedListNode {
  public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};
// ================= BETTER ====================
LinkedListNode<int> *partitionList(LinkedListNode<int> *head, int k) {
    LinkedListNode<int> *small = new LinkedListNode<int>(0);
    LinkedListNode<int> *large = new LinkedListNode<int>(0);
    LinkedListNode<int> *smallHead = small;
    LinkedListNode<int> *largeHead = large;
    while (head) {
        if (head->data < k) {
            smallHead->next = head;
            smallHead = smallHead->next;
        } else {
            largeHead->next = head;
            largeHead = largeHead->next;
        }
        head = head->next;
    }
    smallHead->next = large->next;
    largeHead->next = NULL;
    return small->next;
}
// ================= BEST ====================
int32_t main() {
    fast;

    cout << endl;
    cin.get();
}