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

int lengthOfList(LinkedList* head){ 

    int l=0;
    LinkedList * temp = head;
    while (temp!=NULL)
		{
			temp = temp->next;
			l++;
		}
    delete temp;
    return l;    
}

LinkedList* reverseLinkedList(LinkedList* head){	 
	LinkedList* temp = head;
	LinkedList* cur = NULL;
	
	while(head!=NULL){
		head = head->next;
		temp->next = cur;
		cur = temp;
		temp = head;
	}
	return cur;
}