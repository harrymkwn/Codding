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



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* l1 = reverseList(l1);
    ListNode* l2 = reverseList(l2);

    ListNode* result = NULL;
    ListNode* prev = NULL;
    int carry=0;
    while(l1 || l2){
        int temp=0;

        if(l1){
            temp += l1->val;
            l1 = l1->next; 
        }

        if(l2){
            temp += l2->val;
            l2 = l2->next;
        }

        temp += carry;
        carry = temp/10;
        temp%=10;

        ListNode* newNode = new ListNode(temp);

        if(!result){
            result = newNode;
            prev = newNode;
        }else{
            prev->next = newNode;
            prev = prev->next;
        }
    }

    if(carry){
        prev->next = new ListNode(carry);
    }

    return reverseList(result);
}