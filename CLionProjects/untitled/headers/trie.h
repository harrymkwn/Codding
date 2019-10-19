//
// Created by harry on 25/6/19.
//

#ifndef UNTITLED_TRIE_H
#define UNTITLED_TRIE_H
struct node{

    node * left;
    node * right;
};

class trie {

public:
    trie();
    void insert(int value,node* head);
    int findmaxXor(node* head , int*arr , int n);
};


#endif //UNTITLED_TRIE_H
