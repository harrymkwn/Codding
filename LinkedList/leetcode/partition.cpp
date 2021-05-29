#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* lower = new ListNode(-1);
    ListNode* higher = new ListNode(-1);

    ListNode* lowerTemp = lower;
    ListNode* higherTemp = higher;


    while (head)
    {
        if(head->val<x){
            lowerTemp->next = head;
            head = head->next;
            lowerTemp = lowerTemp->next;
            lowerTemp->next = NULL;
        }else{
            higherTemp->next = head;
            head = head->next;
            higherTemp = higherTemp->next;
            higherTemp->next = NULL;
        }
    }

    lowerTemp->next = higher->next;

    return lower->next;
}