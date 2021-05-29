#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* dist;
    while (fast->next && fast->next)
    {
        if(slow==fast){dist=fast;break;}
    }
    if(!fast->next || !fast->next->next)return NULL;

    slow = head;
    
    while (slow !=dist)
    {
        slow = slow->next;
        dist = dist->next;
    }

    return slow;
}