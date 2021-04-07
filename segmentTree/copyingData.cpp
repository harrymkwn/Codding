#include<bits/stdc++.h>
using namespace std;


class SegmentTree{

    int n,size;
    vector<int> array;
    vector<pair<int,int>> tree;


    void updateUtils(int start,int end,int in,int l,int r,int x,int y){
        if(r<start || end < l)return;

        if(l <= start && end <= r){
            this->tree[in] = {x,y};
            return;
        }

        int mid = (start+end)>>1;

        this->updateUtils(start,mid,2*in,l,r,x,y);
        this->updateUtils(mid+1,end,2*in + 1,l,r,x,y);
        
    }

    pair<int,int> queryUtils(int start,int end,int in,int x){

        if(start==end){
            return this->tree[in];
        }
        if(this->tree[in].first!=-1 && this->tree[in].second!=-1)return this->tree[in];
        int mid = (start+end)>>1;
        if(x<=mid)return this->queryUtils(start,mid,2*in,x);
        return this->queryUtils(mid+1,end,2*in+1,x);
    }

    public:

    SegmentTree(int _n){
        this->n = _n;
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->tree.resize(this->size,{-1,-1});
    }


    void update(int x,int y,int k){
        if(y+k<this->n)
            this->updateUtils(0,this->n-1,1,y,y+k,x,y);

        else{
            this->updateUtils(0,this->n-1,1,y,this->n-1,x,y);
            this->updateUtils(0,this->n-1,1,0,(y+k)%(this->n),x,y);
        } 

    }

    void print(){
        int breakLine=2;
        cout<<"\n\n\n\n";
        for(int i=1;i<this->size;i++){
            if(i==breakLine){
                cout<<"\n";
                breakLine*=2;
            }
            cout<<"("<<this->tree[i].first<<" , "<<this->tree[i].second<<")  ";
        }
        cout<<"\n\n\n\n";
    }
    pair<int,int> query(int x){
        return this->queryUtils(0,this->n-1,1,x);
    }

};


int main(){
    int n,m,t,x,y,k;
    cin>>n>>m;
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    SegmentTree tree(n);
    for(int i=0;i<m;i++){
        cin>>t;
        if(t==1){
            cin>>x>>y>>k;
            x--,y--,k--;
            tree.update(x,y,k);
            tree.print();
        }
        else {
            cin>>x;
            x--;
            pair<int,int> temp = tree.query(x);
            if(temp.second==-1)cout<<b[x]<<" first output \n";
            else cout<<a[x - (temp.second - temp.first)]<<"\n";
            // else if(temp.second<=temp.first) cout<<a[x - (temp.first - temp.second)]<<"\n";
        }
    }

    return 0;
}