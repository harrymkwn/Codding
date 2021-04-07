#include<bits/stdc++.h>
using namespace std;

class SegmentTree{

    struct Node
    {
        int val,count;

        Node(int _val):val{_val},count{1}{};
        Node():val{0},count{0}{};

        Node merge( const Node  &t1, const Node &t2){
            Node temp;

            temp.val = __gcd(t1.val,t2.val);
        
            int t=0;
            if(temp.val==t1.val)t += t1.count;
            if(temp.val==t2.val)t += t2.count;
            temp.count = t;
            return temp;
        }
    };
    

    int n,size;
    vector<int> array;
    vector<Node> tree;

    void buildTreeUtils(int start,int end,int in){
        
        if(start==end){
            this->tree[in] = Node(this->array[start]);
            return;
        }

        int mid = (start+end)>>1;
        this->buildTreeUtils(start,mid,2*in);
        this->buildTreeUtils(mid+1,end,2*in + 1);

        this->tree[in] = this->tree[in].merge(this->tree[2*in], this->tree[2*in+1]); 
    }

    void buildTree(){
        this->buildTreeUtils(0,this->n - 1,1);
    }

    Node queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return Node();

        if(l <= start && end <= r)return this->tree[in];

        int mid = (start+end)>>1;
        
        Node temp, left = this->queryUtils(start,mid,2*in,l,r) , right=this->queryUtils(mid+1,end,2*in+1,l,r);
        temp = temp.merge(left,right);

        return temp;
    }

    public:

    SegmentTree(vector<int> &arr){
        this->n = arr.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->array = arr;
        this->tree.resize(this->size,Node());
        this->buildTree();
    }


    pair<int,int> query(int left,int right){
        Node temp = this->queryUtils(0,this->n-1,1,left-1,right-1);
        return {temp.val,temp.count};
    }

};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    SegmentTree tree(arr);


    int t{0},l{0},r{0};
    cin>>t;
    pair<int,int> ans;
    while(t--){
        cin>>l>>r;
        ans = tree.query(l,r);
        // cout<<ans.first<<" "<<ans.second<<"\n";
        cout<<(r-l+1-ans.second)<<"\n";
    }

    return 0;
}