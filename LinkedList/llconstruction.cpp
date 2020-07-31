#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
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

  void setHead(Node *node) {
    node->next = this->head;
    this->head = node;
    this->head->prev = NULL;
  }

  void setTail(Node *node) {
    node->next = NULL;
    node->prev = this->tail;
    this->tail->next = node;
    this->tail = this->tail->next;
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
    
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    // Write your code here.
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    // Write your code here.
  }

  void removeNodesWithValue(int value) {
    // Write your code here.
  }

  void remove(Node *node) {
    // Write your code here.
  }

  bool containsNodeWithValue(int value) {
    // Write your code here.
    return false;
  }
};
