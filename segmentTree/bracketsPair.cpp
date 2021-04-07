#include<bits/stdc++.h>
using namespace std;


// t1 : contains number of free '('
// t2 : contains number of free ')'
// t3 : contains number of perfect '()'

class SegmentTree{

    //Definition
    struct Node
    {
        int t1,t2,t3;
        Node():t1{0},t2{0},t3{0}{};
        Node(int a,int b,int c):t1{a},t2{b},t3{c}{};

        Node operator +(const Node &rhs){
            int temp = min(t1,rhs.t2);

            Node ret;

            ret.t1 = t1 + rhs.t1 - temp;
            ret.t2 = t2 + rhs.t2 - temp;
            ret.t3 = t3 + rhs.t3 + temp;

            return ret;
        }
    };

    //Declaration
    int n,size;
    string str;
    vector<Node> tree;

    void buildTreeUtils(int start,int end,int in){
        
        if(start==end){
            if(this->str[start]=='(')this->tree[in].t1++;
            else this->tree[in].t2++;
            return;
        }

        int mid = (start+end)>>1;
        this->buildTreeUtils(start,mid,2*in);
        this->buildTreeUtils(mid+1,end,2*in + 1);

        this->tree[in] = this->tree[2*in] + this->tree[2*in+1];
    }

    void buildTree(){
        this->buildTreeUtils(0,this->n - 1,1);
    }


    Node queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return Node(0,0,0);

        if(l <= start && end <= r)return  this->tree[in];

        int mid = (start+end)>>1;
        return  this->queryUtils(start,mid,2*in,l,r) + this->queryUtils(mid+1,end,2*in+1,l,r);
    }

    public:

    SegmentTree(string s){
        this->n = s.length();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->str = s;
        this->tree.resize(this->size);
        this->buildTree();
    }

    int query(int left,int right){
        return (this->queryUtils(0,this->n-1,1,left-1,right-1).t3);
    }

};

int main(){
    string s;
    cin>>s;
    
    SegmentTree tree(s);

    int n,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        cout<<2*tree.query(u,v)<<"\n";
    }

    return 0;
}