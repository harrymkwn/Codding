#include<bits/stdc++.h>
using namespace std;

class SegmentTree{

    int n,size;
    vector<int> tree,array;

    void buildTreeUtils(int start,int end,int in,bool &flag){
        
        if(start==end){
            this->tree[in] = this->array[start];
            flag=true;
            return;
        }

        int mid = (start+end)>>1;
        this->buildTreeUtils(start,mid,2*in,flag);
        this->buildTreeUtils(mid+1,end,2*in + 1,flag);

        if(flag)this->tree[in] = this->tree[2*in] | this->tree[2*in + 1];
        else this->tree[in] = this->tree[2*in] ^ this->tree[2*in + 1];
        
        flag = !flag;
    }

    void buildTree(){
        bool flag=true;
        this->buildTreeUtils(0,this->n - 1,1,flag);
    }

    void updateUtils(int start,int end,int in,int i,int val,bool &flag){

        if(start==end && start==i){
            this->array[i] = val;
            this->tree[in] = val;
            flag=true;
            return;
        }

        int mid = (start+end)>>1;

        if(i<= mid)this->updateUtils(start,mid,2*in,i,val,flag);
        else this->updateUtils(mid+1,end,2*in + 1,i,val,flag);

        if(flag)this->tree[in] = this->tree[2*in] | this->tree[2*in + 1];
        else this->tree[in] = this->tree[2*in] ^ this->tree[2*in + 1];
        
        flag = !flag;
    }

    int queryUtils(int start,int end,int in,int l,int r){

        if(r<start || end < l)return 0;

        if(l <= start && end <= r)return tree[in];

        int mid = (start+end)>>1;
        return  this->queryUtils(start,mid,2*in,l,r) ^ this->queryUtils(mid+1,end,2*in+1,l,r);
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


    void update(int index,int val){
        bool flag=true;
        this->updateUtils(0,this->n-1,1,index-1,val,flag);
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
    int t,n,u,v;
    cin>>t>>n;
    vector<int> arr(pow(2,t),0);
    for(int i=0;i<pow(2,t);i++)cin>>arr[i];

    SegmentTree tree(arr);
    // tree.printTree();
    for(int i=0;i<n;i++){
        cin>>u>>v;
        tree.update(u,v);
        cout<<tree.getValue()<<"\n";
    }
    return 0;
}