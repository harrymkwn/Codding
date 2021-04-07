#include<bits/stdc++.h>
using namespace std;

//TODO Marge Sort Practice
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

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

    int queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return 0;

        if(l <= start && end <= r)return tree[in];

        int mid = (start+end)>>1;
        return  this->queryUtils(start,mid,2*in,l,r) + this->queryUtils(mid+1,end,2*in+1,l,r);
    }

    public:

    SegmentTree(){
        this->n = 20002;
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->tree.resize(this->size,0);
    }


    void update(int val){
        this->updateUtils(0,this->n-1,1,val + 10000);
    }

    int query(int val){
        return this->queryUtils(0,this->n-1,1,0,val+9999);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    SegmentTree tree;

    for(int i=n-1;i>=0;i--){
        int temp = tree.query(arr[i]);
        tree.update(arr[i]);
        arr[i] = temp;
    }
    return 0;
}