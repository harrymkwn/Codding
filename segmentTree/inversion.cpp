#include<bits/stdc++.h>
using namespace std;

class SegmentTree{

    int n,size;
    vector<int> tree,array;

    void buildTreeUtils(int start,int end,int in){
        
        if(start==end){
            this->tree[in] = this->array[start];
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

    void updateUtils(int start,int end,int in,int i,int val){

        if(start==end && start==i){
            this->array[i] = val;
            this->tree[in] = val;
            return;
        }

        int mid = (start+end)>>1;

        if(i<= mid)this->updateUtils(start,mid,2*in,i,val);
        else this->updateUtils(mid+1,end,2*in + 1,i,val);

        this->tree[in] = this->tree[2*in] + this->tree[2*in+1];
        
    }

    int queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return 0;

        if(l <= start && end <= r)return tree[in];

        int mid = (start+end)>>1;
        return  this->queryUtils(start,mid,2*in,l,r) + this->queryUtils(mid+1,end,2*in+1,l,r);
    }

    public:

    SegmentTree(vector<int> &arr){
        this->n = arr.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->array = arr;
        this->tree.resize(this->size,0);

        this->buildTree();
    }

    SegmentTree(int _n){
        this->n = _n;
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->tree.resize(this->size,0);
    }

    void update(int index,int val){
        this->updateUtils(0,this->n-1,1,index-1,val);
    }

    int query(int left,int right){
        return this->queryUtils(0,this->n-1,1,left,right);
    }

    void printTree(){
        int signal=2;

        for(int i=1;i<this->tree.size();i++){
            if(i==signal){
                cout<<"\n";
                signal *= 2;
            }
            cout<<this->tree[i]<<" ";
        }
        cout<<"\n";
    }

    int getValue(){
        return this->tree[1];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    SegmentTree tree(n);

    multiset<int> s;
    for(int i=0;i<n;i++){
        
        s.insert(arr[i]);

        auto x = s.upper_bound(arr[i]);

        int dist = distance(x,s.end());

        tree.update(i,dist);
    }

    
    return 0;
}