#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int lengthOfLinkedList(ListNode* temp) {
    int i = 0;

    while (temp) {
        i++;
        temp = temp->next;
    }
    return i;
}

int getDecimalValue(ListNode* head) {
    string s;
    while (head) {
        s += to_string(head->val);
        head = head->next;
    }
    cout << s;
    // return 0;
    bitset<32> binary{s};

    return (int)binary.to_ulong();
}

int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    cout << getDecimalValue(head) << "\n";
    return 0;
}