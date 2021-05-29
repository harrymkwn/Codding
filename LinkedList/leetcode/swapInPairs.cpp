#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {

    if(!head || !head->next || (head->next&& !head->next->next))return  head;

    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairs(head->next->next);
    second->next = first;

    return second;
}

ListNode* swapPairsIterative(ListNode* head) {

    if(!head || !head->next)return head;

    ListNode* temp = new ListNode(-1);
    ListNode* result = temp;
    ListNode* curNode = head;


    while(curNode && curNode->next){

        ListNode* nextNode = curNode->next->next;
        temp->next = curNode->next;
        curNode->next = NULL;
        temp->next->next = curNode;
        
        curNode = nextNode;
        temp = temp->next->next;
    }

    return result->next;
}
