#include<bits/stdc++.h>
using namespace std;


//TODO Fanwick Practice
// https://codeforces.com/contest/459/problem/D


class SegmentTree{

    int n,size;
    vector<int> array;
    vector<unordered_map<int,int>> tree;

    void buildTreeUtils(int start,int end,int in){
        
        if(start==end){
            this->tree[in][this->array[start]]++;
            return;
        }

        int mid = (start+end)>>1;
        this->buildTreeUtils(start,mid,2*in);
        this->buildTreeUtils(mid+1,end,2*in + 1);

        unordered_map<int,int> temp;
        for(auto x : this->tree[2*in]){
            temp[x.first] += x.second;
        }
        for(auto x : this->tree[2*in + 1]){
            temp[x.first] += x.second;
        }
        this->tree[in] = temp;
    }

    void buildTree(){
        this->buildTreeUtils(0,this->n - 1,1);
    }

    int queryUtils(int start,int end,int in,int l,int r,int val){

        if(r<start || end < l)return 0;

        if(l <= start && end <= r){
            int count=0;
            for(auto x : this->tree[in]){
                if(x.first > val)count+= x.second;
            }

            return count;
        }
        int mid = (start+end)>>1;
        return  this->queryUtils(start,mid,2*in,l,r,val) + this->queryUtils(mid+1,end,2*in+1,l,r,val);
    }

    public:

    SegmentTree(vector<int> &arr){
        this->n = arr.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->array = arr;
        this->tree.resize(this->size);

        this->buildTree();
    }

    int query(int right,int val){
        return this->queryUtils(0,this->n-1,1,0,right,val);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> prefix(n,0),suffix(n,0);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        prefix[i] = ++mp[arr[i]];
    }
    mp.clear();
    for(int i=n-1;i>=0;i--){
        suffix[i] = ++mp[arr[i]];
    }

    SegmentTree tree(prefix);
    int count=0;
    for(int i=1;i<n;i++){
        count += tree.query(i-1,suffix[i]);
    }
    cout<<count<<"\n";
    return 0;
}