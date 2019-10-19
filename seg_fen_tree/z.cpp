#include<bits/stdc++.h>
using namespace std;
int * tree;
int * lazy;

void update(int *tree , int * lazy, int l,int r,int startR,int endR,int in,int inc){
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


int query(int * tree,int in,int start,int end,int l,int r,int* lazy){
    if(lazy[in]!=0){
        tree[in] += (r-l+1)*lazy[in];
        if(l!=r){
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
    int q1=query(tree,2*in,start,mid,l,r,lazy);
    int q2=query(tree,(2*in)+1,mid+1,end,l,r,lazy);
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
        int * tree = new int[size];
        int * lazy = new int[size];
        for(int i=0;i<size;i++)tree[i]=0,lazy[i]=0;
        while(m--)
        {
            int x,y,z,w;
            cin>>x;
            if(x==0){
                cin>>y>>z>>w;
                //cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n";
                update(tree,lazy,0,n-1,y-1,z-1,1,w);
                //for(int i=0;i<=size;i++)cout<<tree[i]<<" ";
                //cout<<"\n";
            }
            if(x==1){
                cin>>y>>z;
                //cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n";
                int a = query(tree,1,0,n-1,y-1,z-1,lazy);
                cout<<a<<"\n";
            }

        }
        
    }
}