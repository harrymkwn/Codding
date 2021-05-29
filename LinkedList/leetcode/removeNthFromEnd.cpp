#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* forward = head;
    ListNode* backward = head;
    ListNode* prev = NULL;
    int i = 1;
    while (forward->next && i < (n)) {
        i++;
        forward = forward->next;
    }

    while (forward->next) {
        forward = forward->next;
        prev = backward;
        backward = backward->next;
    }
    cout << backward->val << "\n";
    if (backward->next) {
        backward->val = backward->next->val;
        backward->next = backward->next->next;
    } else {
        if (prev == NULL)
            return NULL;
        else
            prev->next = NULL;
    }

    return head;
}

pair<ListNode*, int> _removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) {
        if (n == 1) {  // Check if we need to remove the last element,
            return {nullptr, -1};  // if yes then make the current as NULL and
                                   // make count = -1
        }
        return {head, 1};  // If not, then return the same head and count as 1
    }

    pair<ListNode*, int> p = _removeNthFromEnd(head->next, n);
    head->next = p.first;

    if (p.second == -1) {  // Check if already got the answer, if yes then just
                           // return the head
        return {head, -1};
    }

    if (p.second + 1 == n) {  // Check if have to remove the current element
        return {head->next, -1};
    }

    return {head, p.second + 1};
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    return _removeNthFromEnd(head, n).first;
}

int main() { return 0; }