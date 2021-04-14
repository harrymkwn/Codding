#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{

    struct Node
    {
        int freq, val;
        map<int, int> mp;

        Node() : freq{0}, val{0} {};
        Node(int val) : freq(1), val{val}{};

        void merge(const Node n1, const Node n2)
        {
            for (auto x : n1.mp)
            {
                this->mp[x.first] = x.second;
                if (x.second > this->freq)
                {
                    this->freq = x.second;
                    this->val = x.first;
                }
            }
            for (auto x : n2.mp)
            {
                this->mp[x.first] += x.second;
                if (this->mp[x.first] > this->freq)
                {
                    this->freq = this->mp[x.first];
                    this->val = x.first;
                }
            }
        }

        static Node combine(const Node n1,const Node n2){

            Node temp;
            for (auto x : n1.mp)
            {
                temp.mp[x.first] = x.second;
                if (x.second > temp.freq)
                {
                    temp.freq = x.second;
                    temp.val = x.first;
                }
            }
            for (auto x : n2.mp)
            {
                temp.mp[x.first] += x.second;
                if (temp.mp[x.first] > temp.freq)
                {
                    temp.freq = temp.mp[x.first];
                    temp.val = x.first;
                }
            }  
            return temp;
        }
    };

    int n, size;
    vector<int> array;
    vector<Node> tree;

    void buildTreeUtils(int start, int end, int in)
    {

        if (start == end)
        {
            this->tree[in].mp[this->array[start]]=1;
            this->tree[in].freq=1;
            this->tree[in].val=this->array[start];
            return;
        }

        int mid = (start + end) >> 1;
        this->buildTreeUtils(start, mid, 2 * in);
        this->buildTreeUtils(mid + 1, end, 2 * in + 1);

        this->tree[in].merge(this->tree[2 * in],this->tree[2 * in + 1]);
    }

    void buildTree()
    {
        this->buildTreeUtils(0, this->n - 1, 1);
    }

    Node queryUtils(int start, int end, int in, int l, int r)
    {

        if (r < start || end < l)
            return 0;   

        if (l <= start && end <= r)
            return this->tree[in];

        int mid = (start + end) >> 1;

        return Node::combine(this->queryUtils(start, mid, 2 * in, l, r),this->queryUtils(mid + 1, end, 2 * in + 1, l, r));
    }

public:
    SegmentTree(vector<int> &arr)
    {
        this->n = arr.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2 * pow(2, h);
        this->array = arr;
        this->tree.resize(this->size, 0);

        this->buildTree();
    }

    int query(int left, int right,int threshold)
    {
        Node temp = this->queryUtils(0, this->n - 1, 1, left, right);

        if(threshold >  temp.freq)return -1;
        return temp.val;
    }
};

int main()
{
    int n,m,l,r,t;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree tree(arr);

    for(int i=0;i<m;i++){
        cin>>l>>r>>t;
        cout<<tree.query(l,r,t)<<"\n";
    }
    return 0;
}