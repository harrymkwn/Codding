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
