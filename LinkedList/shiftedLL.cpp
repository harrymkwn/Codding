#include<bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value)
    {
        this->value = value;
        next = NULL;
    }
};

LinkedList *shiftLinkedList(LinkedList *head, int k)
{
    if(k==0)return head;
    LinkedList *first = head;
    LinkedList *second = head;
    if (k > 0)
    {
        int counter = 1;
        while (counter <= k)
        {
            second = second->next;
            counter++;
					  if(second==NULL)second=head;
        }
			  if(counter!=k+1)return head;
        if (second == NULL)
            return head;

        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        second->next = head;
        second = first->next;
        first->next = NULL;
        head = second;
    }
    else
    {
        int counter = 1;
        k *= -1;
        while (counter < k)
        {
            first = first->next;
            counter++;
						if(first==NULL)first=head;
        }
			  if(counter!=k)return head;
        if (first == NULL)
            return head;

        while (second->next != NULL){
            second = second->next;
        }
        second->next = head;
        second = first->next;
        first->next = NULL;
        head = second;
    }
    
    return head;
}