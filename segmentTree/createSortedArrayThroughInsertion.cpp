#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

//TODO Improve Accuracy
//https://leetcode.com/problems/create-sorted-array-through-instructions/submissions/
class SegmentTree{

    int n,size;
    vector<int> tree,array;

    void updateUtils(int start,int end,int in,int i,int val=1){

        if(start==end){
            if(start==i)this->tree[in]++;
            return;
        }

        int mid = (start+end)>>1;

        if(i<= mid)this->updateUtils(start,mid,2*in,i,val);
        else this->updateUtils(mid+1,end,2*in + 1,i,val);

        this->tree[in] = this->tree[2*in] + this->tree[2*in+1];
        
    }

    long long queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return 0;

        if(l <= start && end <= r)return tree[in]%m;

        int mid = (start+end)>>1;
        return  ((long long)this->queryUtils(start,mid,2*in,l,r) + this->queryUtils(mid+1,end,2*in+1,l,r))%m;
    }

    public:

    SegmentTree(){
        this->n = 100001;
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->tree.resize(this->size,0);
    }


    void update(int val){
        this->updateUtils(0,this->n-1,1,val);
    }

    long long query(int val){
        return min(this->queryUtils(0,this->n-1,1,0,val-1),this->queryUtils(0,this->n-1,1,val+1,100000));
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    SegmentTree tree;
    long long count=0;
    for(int i=0;i<n;i++){
        count = (count%m + tree.query(arr[i])%m)%m;
        
        tree.update(arr[i]);
    }
    cout<<count<<"\n";
    return 0;
}