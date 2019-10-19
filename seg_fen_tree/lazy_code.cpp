#include<bits/stdc++.h>
using namespace std;

void update_lazytree(long long* tree,long long* lazy,int start,int end,int currPos,int p,int q,long long value){
    
    if(start>end){
        return ;
    }
        
    if(lazy[currPos]!=0){
        tree[currPos] += (end-start+1)*lazy[currPos];
        if(start!=end){
        lazy[2*currPos] += lazy[currPos];
        lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    // complete overlap.
    if(start>q || end<p){
        return;
    }
    //total overlap.
    if(start>=p && end<=q){
        tree[currPos] += (end-start+1)*value;
        if(start!=end){
            lazy[2*currPos] += value;
            lazy[2*currPos+1] += value;
        }
        return ;
    }
    
    // partial overlap.
    int mid = (start + end)/2;
    update_lazytree(tree,lazy,start,mid,2*currPos,p,q,value);
    update_lazytree(tree,lazy,mid+1,end,2*currPos+1,p,q,value);
    tree[currPos] = tree[2*currPos] + tree[2*currPos+1];
    return ;
}
long long find_sum(long long* tree,long long* lazy,int start,int end,int currPos,int p,long long q){
    
    if(start>end)
    {
        return 0;
    }

    if(lazy[currPos]!=0){
        tree[currPos] += (end-start+1)*lazy[currPos];
        if(start!=end){
        lazy[2*currPos] += lazy[currPos];
        lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    
    if(start>q || end<p){
        return 0;
    }
    //total overlap.
    if(start>=p && end<=q){
        return tree[currPos];
    }
    // partial overlap.
    int mid = (start + end)/2;
    long long lA=find_sum(tree,lazy,start,mid,2*currPos,p,q);
    long long rA=find_sum(tree,lazy,mid+1,end,2*currPos+1,p,q);
    return rA + lA;
}
int main() {
    int t;
    cin >> t;
    long long* tree = new long long[4*100000]();
    long long* lazy = new long long[4*100000]();
    while(t--){
        int n,c;
        cin >> n >> c;
    
        while(c--){
            
            int m,p,q,v;
            cin >> m;
            if(m==0)
            {
                cin >> p >> q >> v;
                update_lazytree(tree,lazy,0,n-1,1,p-1,q-1,v);
            }
            else
            {
                cin >> p >> q;
                cout << find_sum(tree,lazy,0,n-1,1,p-1,q-1) << endl;
            }
        }
      //  delete[] tree;
       // delete[] lazy;
    }
}