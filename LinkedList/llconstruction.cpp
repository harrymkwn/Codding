#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value): value(value){};
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }
  void addNode(Node *node){
    if(head==NULL && tail==NULL){
      head = node;
      tail = node;
    }
    else
    {
      tail->next = node;
      node->prev = tail;
      tail = tail->next;
    }  
  }
  void setHead(Node *node) {
    if(head==NULL){
      head=node;
      tail=node;
      return;
    }
    insertBefore(head,node);
  }

  void setTail(Node *node) {
    if(tail==NULL){
      head=node;
      tail=node;
      return;
    }
    insertAfter(tail,node);
  }
  void insertBefore(Node *node, Node *nodeToInsert) {
      if(nodeToInsert==head && nodeToInsert==tail)return;
      remove(nodeToInsert);
      nodeToInsert->prev = node->prev;
      nodeToInsert->next = node;
      if(node->prev == NULL)head = nodeToInsert;
      else node->prev->next = nodeToInsert;
      node->prev = nodeToInsert ;
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    if(nodeToInsert==head && nodeToInsert==tail)return;
    remove(nodeToInsert);
    nodeToInsert->next = node->next;
    nodeToInsert->prev = node;
    if(node->next == NULL)tail = nodeToInsert;
    else node->next->prev = nodeToInsert;
    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    if(position==1){setHead(nodeToInsert);return;}
    Node *curNode = head;
    int i=1;

    while (curNode!=NULL && i++!=position)
      curNode = curNode->next;

    if(curNode==NULL){setTail(nodeToInsert);}
    else insertBefore(curNode,nodeToInsert);
  }
  void removeNodesWithValue(int value) {
    Node *curNode = head;

    while (curNode!=NULL)
    {
      Node *nodeToRemove = curNode;
      curNode = curNode->next;
      if(curNode->value==value){
        remove(nodeToRemove);
    }
    }   
  }

  void remove(Node *node) {
    if(node==head)head = head->next;
    if(node==tail)tail = tail->prev;

    removeNodeBindings(node);
  }

  void removeNodeBindings(Node *node){
    if(node->prev !=NULL)
      node->prev->next = node->next;
    if(node->next !=NULL)
      node->next->prev = node->prev;
      node->next=NULL;
      node->prev=NULL;
  }
  void printLinkedList(){
    Node* node = this->head;
    while(true){
     cout<<node->value<<" ";
      if(node ==tail)break;
      node = node->next;
     }
  }

    bool containsNodeWithValue(int value) {
      Node* curNode = head;
      while (curNode!=NULL)
      {
        if(curNode->value ==value)return true;
        curNode = curNode->next;
      }
      
    return false;
  }
};

int main(){
  DoublyLinkedList linkedList;
  Node* node = new Node(5);
  linkedList.addNode(node);
  Node* node2 = new Node(3);
  linkedList.addNode(node2);
  Node* node3 = new Node(3);
  linkedList.addNode(node3);
  Node* node4 = new Node(4);
  linkedList.setHead(node4);
  Node* node5 = new Node(5);
  linkedList.setTail(node5);
  Node* node6 = new Node(6);
  linkedList.setTail(node3);
  linkedList.printLinkedList();
}