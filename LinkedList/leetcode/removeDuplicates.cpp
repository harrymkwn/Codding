#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
    ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}

ListNode* deleteDuplicates(ListNode* head) {
    set<int> s;
    ListNode* temp = head;
    while (temp->next) {
        
        if(temp->val == temp->next->val){
            deleteNode(temp);
        }
        temp = temp->next;
    }

    return head;
}