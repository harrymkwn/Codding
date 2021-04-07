#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/356/problem/A

class SegmentTree{

    int n,size;
    vector<int> tree,array;

    void updateUtils(int start,int end,int in,int l,int r,int val){

        if(r<start || end < l)return;
        
        if(start==end && start!=val && this->tree[in]==-1){
            this->array[start] = val;
            this->tree[in] = val;
            return;
        }
        else if(start==end)return;


        int mid = (start+end)>>1;
        if(tree[in]!=-1){
            if(mid<this->tree[in])
                this->updateUtils(mid+1,end,2*in+1,l,r,val);
            else
                this->updateUtils(start,mid,2*in,l,r,val);
        }
        else{
            this->updateUtils(start,mid,2*in,l,r,val);
            this->updateUtils(mid+1,end,2*in + 1,l,r,val);
        }
        if(l <= start && end <= r){tree[in]=val;}
    }

    public:

    SegmentTree(vector<int> &arr){
        this->n = arr.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->array = arr;
        this->tree.resize(this->size,-1);

        // this->buildTree();
    }


    void update(int l,int r,int win){
        this->updateUtils(0,this->n-1,1,l-1,r-1,win-1);
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
        cout<<"\n\n";
    }

    void printArray(){

        for(auto x : this->array)cout<<x+1<<" ";
        cout<<"\n";
    }

};

int main(){
    int n,m,l,r,w;
    cin>>n>>m;
    vector<int> arr(n,-1);
    // for(int i=0;i<n;i++)cin>>arr[i];

    SegmentTree tree(arr);

    for(int i=0;i<m;i++){
        cin>>l>>r>>w;
        tree.update(l,r,w);
        // tree.printTree();
    }
    tree.printArray();
    return 0;
}