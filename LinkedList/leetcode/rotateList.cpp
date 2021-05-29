#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int LengthOfLinkedList(ListNode* head) {
    int i = 0;
    while (head) {
        i++;
        head = head->next;
    }
    return i;
}

ListNode* rotateRight(ListNode* head, int k) {
    int length = LengthOfLinkedList(head);
    if (length == 0) return head;
    cout << length << "\n";
    k %= length;
    if (k == 0) return head;
    ListNode* forward = head;
    ListNode* backward = head;

    int i = 1;
    while (i < k) {
        forward = forward->next;
        i++;
    }

    ListNode* prev = NULL;
    while (forward->next) {
        forward = forward->next;
        prev = backward;
        backward = backward->next;
    }

    forward->next = head;
    prev->next = NULL;
    return backward;
}