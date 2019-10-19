#include<bits/stdc++.h>
using namespace std;

struct node
{
    int ss,s;
};

void buidltree(int* arr,node * tree,int l,int r,int in){

    if(l ==r)
    {
        tree[in].ss= arr[l]*arr[l];
        tree[in].s = arr[l];
        return;
    }
    int mid = (l+r)/2;
    buidltree(arr,tree,l,mid,2*in);
    buidltree(arr,tree,mid+1,r,2*in+1);

    tree[in].ss = tree[2*in].ss + tree[2*in+1].ss;
    tree[in].s = tree[2*in].s + tree[2*in+1].s;
}

void update1(int*arr,node *tree , int * lazy, int l,int r,int startR,int endR,int in,int inc){
    if(l>r)
        return;
    
    if(lazy[in]!=0){
        tree[in].ss += lazy[in]*lazy[in]*(r-l+1) + tree[in].s*lazy[in]*2;
        tree[in].s += (r-l+1)*lazy[in];
        if(l!=r){
            lazy[2*in]+=lazy[in];
            lazy[2*in +1]+=lazy[in];
            lazy[in]=0;
        }
    }
    if(r<startR || endR<l)
        return;
    if(startR<=l && endR>=r)
    {
        tree[in].ss += inc*inc*(r-l+1) + tree[in].s*inc*2;
        tree[in].s += inc*(r-l+1);
        if(l!=r){
            lazy[2*in] += inc;
            lazy[2*in+1] += inc;
        }
        return;
    }

    int mid = (l+r)/2;
    update1(arr,tree,lazy,l,mid,startR,endR,2*in,inc);
    update1(arr,tree,lazy,mid+1,r,startR,endR,2*in+1,inc);

    tree[in].ss = tree[2*in].ss + tree[2*in+1].ss;
    tree[in].s = tree[2*in].s + tree[2*in +1].s; 
}
void setallfromhere(int*arr , int* lazy,node * tree,int in,int l,int r,int inc){
    if(l==r)
        {
            arr[l]=inc;
            tree[in].ss = inc*inc;
            tree[in].s = inc;
            lazy[in] = 0;
        return;
        }
    int mid = (l+r)/2;
    setallfromhere(arr,lazy,tree,2*in,l,mid,inc);
    setallfromhere(arr,lazy,tree,2*in+1,mid+1,r,inc);
    tree[in].ss = tree[2*in].ss + tree[2*in+1].ss;
    tree[in].s = tree[2*in].s + tree[2*in + 1].s;
    lazy[in]=0;
}
void update2(int*arr,node *tree , int * lazy, int l,int r,int startR,int endR,int in,int inc){
    if(l>r)
        return;
    
    if(r<startR || endR<l)
        return;
    if(startR<=l && endR>=r)
    {
        tree[in].ss= inc*inc*(r-l+1);
        tree[in].s = inc*(r-l+1);
        setallfromhere(arr,lazy,tree,in,l,r,inc);
        return;
    }

    int mid = (l+r)/2;
    update2(arr,tree,lazy,l,mid,startR,endR,2*in,inc);
    update2(arr,tree,lazy,mid+1,r,startR,endR,2*in+1,inc);

    tree[in].ss = tree[2*in].ss +tree[2*in+1].ss;
    tree[in].s = tree[2*in].s + tree[2*in + 1].s;

}


node query(node * tree,int in,int start,int end,int l,int r){
    if(start>r || end<l){
        node a;
        a.ss=0;a.s=0;
        return  a;
    }
    if(start>=l && end<=r){
        return tree[in];
    }
    int mid = (start + end)/2;
    node q1=query(tree,2*in,start,mid,l,r);
    node q2=query(tree,(2*in)+1,mid+1,end,l,r);
    node a;
    a.ss= q1.ss+q2.ss;
    a.s= q1.s+q2.s;
    return a;
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":\n";
        int n,m;
        cin>>n>>m;
        int * arr = new int[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int h =(int)(ceil(log2(n)));
        long long size  =  2 *(int)pow(2,h) - 1;
        node * tree = new node[size];
        int * lazy = new int[size];
        for(int i=0;i<size;i++)tree[i].ss=0,tree[i].s=0,lazy[i]=0;
        buidltree(arr,tree,0,n-1,1);
        while(m--)
        {
            int x,y,z,w;
            cin>>x;
            if(x==0){
                cin>>y>>z>>w;
                update2(arr,tree,lazy,0,n-1,y-1,z-1,1,w);
            }
            if(x==1){
                cin>>y>>z>>w;
                update1(arr,tree,lazy,0,n-1,y-1,z-1,1,w);
            }
            if(x==2){
                cin>>y>>z;
                node a = query(tree,1,0,n-1,y-1,z-1);
                cout<<a.ss<<"\n";
            }

        }
        
    }
}