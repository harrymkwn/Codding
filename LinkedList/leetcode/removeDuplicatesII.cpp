#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* result = new ListNode(-1);
    ListNode* temp = result;
    while (head)
    {
        bool isDuplicate=false;
        ListNode* temp = head;
        while(temp->next && temp->next->val==head->val){
            isDuplicate=true;
            temp = temp->next;
        }

        if(temp->next)
            head = temp->next;
        else{
            if(!isDuplicate){
                result->next = temp;
                result->next->next = NULL;
            }
            break;
        }
        if(!isDuplicate){
            result->next = temp;
            result = result->next;
            result->next = NULL;
        }
    }
    return temp->next;
}
