
#include<bits/stdc++.h>
using namespace std;



//
class SegmentTree{

    int n,size;
    vector<int> tree,array;

    void updateUtils(int start,int end,int in,int i,int val=1){

        if(start==end && start==i){
            this->tree[in] += val;
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

    }

    SegmentTree(int n){
        this->n = n;
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->array.resize(this->n,0);
        this->tree.resize(this->size,0);    
    }

    void update(int index,int val=1){
        this->updateUtils(0,this->n-1,1,index);
    }

    int query(int left){
        return this->queryUtils(0,this->n-1,1,left,(this->n)-1);
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

};


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> temp = arr;
    sort(arr.begin(),arr.end());
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)mp[temp[i]]=i;
    for(int i=0;i<n;i++)arr[i] = mp[arr[i]];

    SegmentTree tree(n+1);
    long long ans=0;
    for(int i=0;i<n;i++){
        int l = tree.query(arr[i]+1);
        int r = max(0,arr[i]-i+l);
        ans += 1ll*l *r ;
        tree.update(arr[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
