#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  unordered_map<char, TrieNode *> children;
};

class Trie
{
public:
  TrieNode *root = new TrieNode();
  char endsymbol = '*';

  void insert(string str)
  {
    TrieNode *node = this->root;
    for (int i = 0; i < str.length(); i++)
    {
      if (node->children.find(str[i]) == node->children.end())
      {
        TrieNode *newNode = new TrieNode();
        node->children[str[i]] = newNode;
      }
      node = node->children[str[i]];
    }
    node->children.insert({this->endsymbol, NULL});
  }
};

bool isSpecial(string string ,TrieNode *TrieNode,int idx,int count,Trie *trie){
  auto c = string[idx];

  if(TrieNode->children.find(c)==TrieNode->children.end())return false;

  auto nextTrieNode = TrieNode->children[c];

  auto atEndofString = idx == string.length() -1;
  if(atEndofString)
    return nextTrieNode->children.find(trie->endsymbol)!= nextTrieNode->children.end()&& count+1>=2;

  if(nextTrieNode->children.find(trie->endsymbol)!=nextTrieNode->children.end()){
    auto restIsSpecial = isSpecial(string,trie->root,idx+1,count+1,trie);
    if(restIsSpecial)return true;
  }
  return isSpecial(string,nextTrieNode,idx+1,count,trie);
}

vector<string> specialStrings(vector<string> strings)
{
  auto trie = new Trie();

  for(auto string : strings){
    trie->insert(string);
  }
  vector<string> result;
  for(auto string : strings){
    if(isSpecial(string,trie->root,0,0,trie)){
      result.push_back(string);
    }
    return result;
  }
  return strings;
}