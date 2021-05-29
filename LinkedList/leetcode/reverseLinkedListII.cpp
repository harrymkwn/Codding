#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getNthNode(ListNode* head, int idx) {
    int i = 1;
    while (i < (idx - 1) && head->next) {
        i++;
        head = head->next;
    }
    return head;
}

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

void print(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right || left > right) return head;

    if (left == 1) {
        ListNode* rightPoint = getNthNode(head, right)->next;
        ListNode* second = rightPoint->next;
    }
    ListNode* temp = NULL;
    ListNode* first;
    ListNode* leftPoint;
    if (left != 1) {
        first = getNthNode(head, left);
        leftPoint = first->next;
    }else{
        first = new ListNode(-1);
        temp = first;
        leftPoint = head;
    }
    ListNode* rightPoint = getNthNode(head, right)->next;
    ListNode* second = rightPoint->next;

    rightPoint->next = NULL;
    leftPoint = reverseList(leftPoint);
    first->next = leftPoint;
    while (first->next) {
        first = first->next;
    }
    first->next = second;
    return left==1 ? temp->next : head;
}


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    cout<<head->val<<"\n";
    print(head);
    head=  reverseBetween(head, 1, 4);
    print(head);
    return 0;
}


//TODO https://leetcode.com/problems/reverse-linked-list-ii/discuss/1234334/C%2B%2B-or-0ms-or-EXPLAINED-or-1-PASS-SOLUTION-or-O(n)-100-faster