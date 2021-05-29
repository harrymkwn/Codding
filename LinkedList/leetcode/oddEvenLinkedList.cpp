#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* temp = head;
    ListNode* lower = new ListNode(-1);
    ListNode* higher = new ListNode(-1);

    ListNode* lowerTemp = lower;
    ListNode* higherTemp = higher;


    while (temp)
    {   
        if(temp){
            lowerTemp->next = head;
            lowerTemp = lowerTemp->next;
            temp = temp->next;
            lowerTemp->next = NULL;
        }
        if(temp){
            higherTemp->next = head;
            higherTemp = higherTemp->next;
            temp = temp->next;
            higherTemp->next = NULL;
        }
    }

    lowerTemp->next = higher->next;
    return lower->next;
}