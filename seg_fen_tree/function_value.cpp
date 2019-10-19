#include<bits/stdc++.h>
using namespace std;
long long mod;
struct node
{
    long long l,r;
    node(){
        l=0;r=0;
    }
};
void buildtree(long long* arr,long long *tree,long long start,long long end,long long in){

    if(start==end){
        tree[in]=arr[start]%mod;
        return;
    } else{
        long long mid = (start+end)/2;
        buildtree(arr,tree,start,mid,2*in);
        buildtree(arr,tree,mid+1,end,2*in+1);
        tree[in] = (tree[2*in] + tree[2*in + 1]+mod)%mod;
    }
}

long long query(long long * tree,long long in,long long start,long long end,long long l,long long r){
    if(start>r || end<l){
        return  0;
    }
    if(start>=l && end<=r){
        return tree[in]%mod;
    }
    long long mid = (start + end)/2;
    long long q1=query(tree,2*in,start,mid,l,r);
    long long q2=query(tree,(2*in)+1,mid+1,end,l,r);
    return (q1+q2+mod)%mod;
}

int main(){
    long long n;
    cin>>n>>mod;
    node* inputs = new node[n];
    long long max=0;
    for(long long i=0;i<n;i++)
    {
        cin>>inputs[i].l>>inputs[i].r;
        if(max<inputs[i].r)
            max=inputs[i].r;
    }
    long long* dp = new long long[max];
    dp[0]=1;
    dp[1]=1;
    for(long long i=2;i<max;i++){
        if(i%2==1)dp[i]=(2*dp[i-1]-dp[i-2]+2)%mod;
        else dp[i]= (3*dp[i-2])%mod;        
    }
    long long h =(long long)(ceil(log2(max)));
    long long size  =  2 *(long long)pow(2,h) - 1;
    long long * tree = new long long[size];
    for(long long i=0;i<size;i++)tree[i]=0;
    buildtree(dp,tree,0,max-1,1);
    for(long long i=0;i<n;i++){
        cout<<"\n"<<query(tree,1,0,max-1,inputs[i].l-1,inputs[i].r-1);
    }

    delete[] dp;
    delete[] inputs;
    delete[] tree;
}