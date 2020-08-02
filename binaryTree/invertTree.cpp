#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};


void invertBinaryTree(BinaryTree *tree) {
	queue<BinaryTree*> q;
	q.push(tree);
	while(q.size()>0){
		BinaryTree *temp = q.front();
        q.pop();
        if(temp==NULL)continue;
        swap(temp->left,temp->right);
        q.push(temp->left);
        q.push(temp->right);
	}
}
