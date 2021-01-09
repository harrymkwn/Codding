#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val) : left(NULL), right(NULL), data(val) {}
    node() : left(NULL), right(NULL), data(0) {}
};

class binaryTree
{
    node *root,*lcA;
    
    void inorder(node *root)
    {
        if (root->left)
            inorder(root->left);
        cout << root->data << " ";
        if (root->right)
            inorder(root->right);
    }
    void preorder(node *root)
    {
        cout << root->data << " ";
        if (root->left)
            preorder(root->left);
        if (root->right)
            preorder(root->right);
    }
    void postorder(node *root)
    {
        if (root->left)
            postorder(root->left);
        if (root->right)
            postorder(root->right);
        cout << root->data << " ";
    }

    void deleteNode(node *data_node)
    {
        node *temp = this->root;

        if (!root)
            return;

        if (!this->root->left && !this->root->right)
        {
            if (this->root != data_node)
                return;
            this->root = NULL;
        }

        queue<node *> q;
        q.push(temp);

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left)
            {
                if (temp->left == data_node)
                {
                    temp->left = NULL;
                    return;
                }
                q.push(temp->left);
            }
            if (temp->right)
            {
                if (temp->right == data_node)
                {
                    temp->right = NULL;
                    return;
                }
                q.push(temp->right);
            }
        }
    }

    bool lca(node* root, int p, int q){
        if(!root)return false;

        bool left=false,right=false,cur=false;
        if(root->left)left = lca(root->left,p,q);
        if(root->data==p || root->data==q)cur = true;
        if(root->right)right = lca(root->right,p,q);

        if(left&&right || cur&&right || cur&&left){this->lcA = root; return false;}
        if(left || right || cur)return true;
        
        return false;
    }
    
public:
    binaryTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        if (this->root == NULL)
        {
            this->root = new node(val);
            return;
        }

        node *temp = this->root;
        queue<node *> q;
        q.push(temp);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            else
            {
                temp->left = new node(val);
                return;
            }

            if (temp->right != NULL)
                q.push(temp->right);
            else
            {
                temp->right = new node(val);
                return;
            }
        }
    }

    void inorderprint()
    {
        cout << "\n";
        if (root)
            return this->inorder(this->root);
    }
    void preorderprint()
    {
        cout << "\n";
        if (root)
            return this->preorder(this->root);
    }
    void postorderprint()
    {
        cout << "\n";
        if (root)
            return this->postorder(this->root);
    }

    void deletenode(int val)
    {
        node *temp = this->root;
        node *key_node = NULL;
        queue<node *> q;
        q.push(temp);

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->data == val && !key_node)
                key_node = temp;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        if (key_node)
        {
            int x = temp->data;
            this->deleteNode(temp);
            key_node->data = x;
        }
    }

    void inorder_stack()
    {
        node *temp = this->root;
        if (temp == NULL)
            return;
        cout << "\n";
        stack<node *> s;
        s.push(temp);

        while (temp != NULL || !s.empty())
        {

            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    void traversal_treak()
    {
        unordered_map<node *, int> mp;
        stack<node *> s;
        s.push(this->root);

        while (!s.empty())
        {
            node *cur = s.top();

            if (cur == NULL)
            {
                s.pop();
                continue;
            }
            if (mp[cur] == 0)
                s.push(cur->left);
            else if (mp[cur] == 1)
                cout << cur->data << "\n";
            else if (mp[cur] == 2)
                cout << cur->data << "\n";
            else
            {
                s.pop();
                continue;
            }
            mp[cur]++;
        }
    }

    vector<vector<int>> levelOrder()
    {
        vector<vector<int>> ret;
        if (!root)ret;
        queue<pair<node *, int>> q;
        q.push({this->root, 0});

        while (!q.empty())
        {
            pair<node *, int> temp = q.front();
            q.pop();
            try
            {
                ret.at(temp.second).push_back(temp.first->data);
            }
            catch (const std::exception &e)
            {
                ret.push_back({temp.first->data});
            }

            if (temp.first->left)
                q.push({temp.first->left, temp.second + 1});
            if (temp.first->right)
                q.push({temp.first->right, temp.second + 1});
    vector<bool> isInTree(100,0);    }

        return ret;
    }
    node* lowestCommonAncestor(int p, int q) {
        this->lcA = nullptr;
        this->lca(this->root,p,q);
        return this->lcA;
    }
};

int main()
{

    binaryTree *tree = new binaryTree();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);
    tree->insert(11);
    tree->insert(12);
    tree->insert(13);
    tree->insert(14);
    tree->insert(15);
    tree->inorderprint();
    cout<<"\n";
    node* lca = tree->lowestCommonAncestor(10,5);
    cout<<lca->data<<"\n";
    lca = tree->lowestCommonAncestor(2,11);
    cout<<lca->data<<"\n";
    lca = tree->lowestCommonAncestor(3,12);
    cout<<lca->data<<"\n";

    return 0;
}