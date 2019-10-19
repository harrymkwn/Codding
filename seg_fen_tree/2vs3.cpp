#include<bits/stdc++.h>
using namespace std;
#define mod 3

void seg_tree(int* arr, int *tree ,int start,int end,int in){
    if(start == end){
        tree[in]=arr[start]%3;
        return ; 
    }
    else {
        int mid = (start+end)/2;
        seg_tree(arr,tree,start,mid,2*in);
        seg_tree(arr,tree,mid+1,end,2*in+1);
        
        tree[in] = tree[2*in]*pow(2,(end-mid)) +  tree[2*in + 1];
        tree[in] %=3;
    }
}

void update(int * arr,int * tree, int start,int end,int in,int idx){
    if(start==end){
        if(arr[idx]==0){
        arr[idx] = 1;
        tree[in]=1;
        }
        return;
    }else{
    int mid = (start+end)/2;
    if(start<=idx && mid>=idx)
    update(arr,tree,start,mid,2*in,idx);
    else
    update(arr,tree,mid+1,end,2*in+1,idx);
    
        tree[in] = tree[2*in]*pow(2,(end-mid)) +  tree[2*in + 1];
        tree[in] %=3;
    }
}


int query(int * tree , int start,int end,int l,int r,int in){
    if(start>r || end <l)
    {
        return 0;
    } else if(start>=l && end<=r)
    {
        return tree[in];
    }else {
        int mid = (start+end)/2;
        int  q1 = query(tree,start,mid,l,r,2*in);
        int  q2 = query(tree,mid+1,end,l,r,2*in+1);
        q1%=3;
        q2%=3;
        if(r<mid)
            return q1%3;
        return (q1*pow(2,(end-mid)))+q2;
    }
}

int main(){
    int n,m;
    cin>>n;
    int * arr = new int[n];
    int h = (int)ceil(log2(n));
    long long  size = 2*pow(2,h) ;
    int * tree = new int [size];
    string a ;
    cin>>a;
    for(int i =0;i<a.length();i++)
        arr[i]=(int)a[i]-48;
    for(int i =0;i<size;i++)
        tree[i]=0;
    
    seg_tree(arr,tree,0,n-1,1);
    for(int i=0;i<size;i++)
        cout<<tree[i]<<" ";
    cout<<"\n";
    cin>>m;
    while(m--){
        int x,y,z;
        cin>>x;
        if(x==0){
            cin>>y>>z;
            int a = query(tree,0,n-1,y,z,1);
            cout<<a%3<<"\n";
        }
        else{
            cin>>y;
            update(arr,tree,0,n-1,1,y);
        }
    }
    delete[] arr;
    delete[] tree;
    return 0;
}