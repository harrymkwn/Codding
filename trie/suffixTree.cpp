#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void populateSuffixTrieFrom(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            this->insertSubStringStartingAtI(i,str);
        }
        
    }

    void insertSubStringStartingAtI(int ind, string str)
    {
        TrieNode *node = this->root;

        for (int i = ind; i < str.length(); i++)
        {
            if (node->children.find(str[i]) == node->children.end())
            {
                TrieNode *newNode = new TrieNode();
                node->children.insert({str[i], newNode});
            }
            node = node->children[str[i]];
        }
        node->children.insert({this->endSymbol, NULL});
    }


    bool contains(string str)
    {
        TrieNode* node = this->root;

        for(char c : str){
            if(node->children.find(c)==node->children.end())return false;

            node = node->children[c];
        }

        return node->children.find('*')!=node->children.end();
    }
};
