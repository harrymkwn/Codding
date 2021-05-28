#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> s;

    ListNode *tempA = headA;
    while (tempA) {
        s.insert(tempA);
        tempA = tempA->next;
    }

    ListNode *tempB = headB;

    while (tempB) {
        if (s.find(tempB) != s.end()) return tempB;
    }

    return NULL;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tailA = headA;
    ListNode *tailB = headB;

    int a = 1, b = 1;
    while (tailA->next) {
        a++;
        tailA = tailA->next;
    }

    while (tailB->next) {
        b++;
        tailB = tailB->next;
    }

    if (tailA != tailB) return NULL;

    cout << a << " " << b << "\n";

    ListNode *tempA = headA;
    ListNode *tempB = headB;
    if (a > b) {
        while (a != b) {
            tempA = tempA->next;
            a--;
        }

    } else if (b > a) {
        while (a != b) {
            tempB = tempB->next;
            b--;
        }
    }

    while (tempA && tempB)
    {
        if(tempA==tempB)return tempA;

        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}

int main() { return 0; }