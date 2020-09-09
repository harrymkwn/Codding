#include<bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

int lengthofList(LinkedList* head){ 

    int l=0;
    LinkedList * temp = head;
    while (temp!=NULL)
        temp = temp->next;
    delete head;
    return l;    
}

LinkedList *findMiddleNode(LinkedList* head , int upto){

    int curentNode = 1;
    LinkedList* temp = NULL;
    while (curentNode<upto)
    {
        temp = temp->next;
        curentNode++;
    }
    return temp;
}

LinkedList* reverseLinkedList(LinkedList* head){

    if(head==NULL || head->next==NULL)return head;
    LinkedList* cur = NULL;
    LinkedList* temp = head;
    LinkedList* root = head;
    while (root->next!=NULL)
    {
        root = root->next;
        temp->next = cur;
        cur = temp;
        temp = root;
    }
    return cur;
}

LinkedList *invertedBisection(LinkedList *head) {
  
  int length = lengthofList(head);

  LinkedList* firstHalfTail = head;
  LinkedList* middleNode = NULL;
  LinkedList* secondHalf = head;

    firstHalfTail = findMiddleNode(head,length/2);
    if(length%2==0){
        secondHalf = firstHalfTail->next;
        middleNode = NULL;
    }else
    {
        middleNode = firstHalfTail->next;
        secondHalf = middleNode->next->next;
    }

    firstHalfTail->next = NULL;
    reverseLinkedList(head);
    secondHalf = reverseLinkedList(secondHalf);

    if(middleNode==NULL){
        head->next = secondHalf;
    }else
    {
        head->next = middleNode;
        middleNode->next = secondHalf;
    }
    return firstHalfTail;
}
