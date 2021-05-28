#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* removeElements(ListNode* head, int val) {
    if(!head)return NULL;

    if(head->val == val)
        return removeElements(head->next,val);
    else
        return head->next = removeElements(head->next,val);
}
