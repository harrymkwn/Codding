#include<bits/stdc++.h>
using namespace std;
long long* tree = new long long[4*1000000];
long long* lazy = new long long[4*1000000];

void update(long long*tree , long long* lazy, int l,int r,int startR,int endR,int in,int inc){
    if(l>r)
        return;
    
    if(lazy[in]!=0){
        tree[in] += (r-l+1)*lazy[in];
        if(l!=r){
            lazy[2*in]+=lazy[in];
            lazy[2*in +1]+=lazy[in]; 
        }
        lazy[in]=0;
    }
    if(r<startR || endR<l)
        return;
    if(startR<=l && endR>=r)
    {
        tree[in] += inc*(r-l+1);
        if(l!=r){
            lazy[2*in] += inc;
            lazy[2*in+1] += inc;
        }
        lazy[in]=0;
        return;
    }

    int mid = (l+r)/2;
    update(tree,lazy,l,mid,startR,endR,2*in,inc);
    update(tree,lazy,mid+1,r,startR,endR,2*in+1,inc);

    tree[in] = tree[2*in] + tree[2*in +1]; 
}


long long query(long long* tree,long long in,int start,int end,int l,int r,long long* lazy){
    if(l>r)return 0;
    if(lazy[in]!=0){
        tree[in] += (start-end+1)*lazy[in];
        if(start!=end){
            lazy[2*in]+=lazy[in];
            lazy[2*in +1]+=lazy[in];
        }
        lazy[in]=0;
    }
    if(start>r || end<l){
        return  0;
    }
    if(start>=l && end<=r){
        return tree[in];
    }
    int mid = (start + end)/2;
    long long q1=query(tree,2*in,start,mid,l,r,lazy);
    long long q2=query(tree,(2*in)+1,mid+1,end,l,r,lazy);
    //cout<<q1<<" "<<q2<<"\n";
    return q1+q2;
}




int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        int h =(int)(ceil(log2(n)));
        long long size  =  2 *(int)pow(2,h);
        for(int i=0;i<4*1000000;i++)tree[i]=0,lazy[i]=0;
        while(m--)
        {
            int x,y,z,w;
            cin>>x;
            if(x==0){
                cin>>y>>z>>w;
                update(tree,lazy,0,n-1,y-1,z-1,1,w);
                //for(int i=0;i<size;i++)cout<<tree[i]<<" ";
                //cout<<"\n";
            }
            if(x==1){
                cin>>y>>z;
                long long a = query(tree,1,0,n-1,y-1,z-1,lazy);
                cout<<a<<"\n";
            }
        }
    }
    delete[] tree;
    delete[] lazy;
}