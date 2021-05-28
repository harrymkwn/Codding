#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* newList = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = newList;
        newList = cur;
        cur = next;
    }

    return newList;
}

bool isPalindrome(ListNode* head) {
    if(!head && !head->next)return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* rev = reverseList (slow);
    ListNode* cur = head;

    while (rev) {
        if (rev->val != cur->val) return false;

        rev = rev->next;
        cur = cur->next;
    }

    return true;

    return true;
}
