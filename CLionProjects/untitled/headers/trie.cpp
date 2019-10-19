//
// Created by harry on 25/6/19.
//

#include "trie.h"
#include<bits/stdc++.h>
using namespace std;



void trie::insert(int value,node* head){

    node * cur =head;
    for(int i=31;i>=0;i--){
        int b = (value>>i)&1;

        if(b==0){
            if(!cur->left)
                cur->left = new node();
            cur = cur->left;
        }else{
            if(!cur->right)
                cur->right = new node();
            cur = cur->right;
        }
    }
}

int trie::findmaxXor(node* head , int*arr , int n){

    int max_xor = INT_MIN;

    for(int i=0;i<n;i++){
        int cur_xor = 0;
        int value = arr[i];
        node * cur = head;
        for(int j=31;j>=0;j--){
            int b = (value>>j)&1;

            if(b==0){
                if(cur->right){
                    cur_xor+= pow(2,j);
                    cur = cur->right;
                }
                else
                    cur = cur->left;
            }else{
                if(cur->left){
                    cur_xor+=pow(2,j);
                    cur=cur->left;
                }
                else
                    cur=cur->right;
            }
        }
        if(cur_xor>max_xor)
            max_xor = cur_xor;
    }
    return max_xor;

}



trie::trie() {
    int n;
    cin>>n;
    int arr[n];
    node * head = new node();
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        insert(arr[i],head);
    }
    cout<<findmaxXor(head,arr,n);
}