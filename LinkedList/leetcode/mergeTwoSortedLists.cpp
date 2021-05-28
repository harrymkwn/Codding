#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* temp = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    while (l1) {
        temp->next = l1;
        l1 = l1->next;
        temp = temp->next;
    }

    while (l2) {
        temp->next = l2;
        l2 = l2->next;
        temp = temp->next;
    }
    return head->next;
}

ListNode* mergeTwoListsRecursive(ListNode* a, ListNode* b) {
    ListNode* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->val <= b->val) {
        result = a;
        result->next = mergeTwoListsRecursive(a->next, b);
    } else {
        result = b;
        result->next = mergeTwoListsRecursive(a, b->next);
    }
    return (result);
}

int main() { return 0; }