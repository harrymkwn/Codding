#include<bits/stdc++.h>
using namespace std;

struct node
{
    int pos,l,r,val;

    node() : pos(0),l(0),r(0),val(0){}
};

bool check(node a,node b){
    if(a.val == b.val)
        return a.l>b.l;
    return a.val>b.val;
}

void update(int index,int* bit,int n){

    index = index +1;
    
    while (index<=n)
    {
        bit[index]++;

        index += ((-index)&index);
    }
    
}
int query(int index,int* bit){

    int sum =0;
    index = index +1 ;
    while (index>=0)
    {
        sum+= bit[index];

        index -= ((-index)&index);
    }
    return sum;
    
}

int main() {

    int n,q;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>q;
    node* a = new node[n+q+1];

    for (int i = 1; i <= n; i++)
    {
        a[i].val = arr[i-1];
        a[i].l=0;
        a[i].r=i;
        a[i].pos = i-1;
    }
    
    for(int i=n+1;i<n+q+1;i++){
        cin>>a[i].l>>a[i].r>>a[i].val;
        a[i].pos=i-n;
    }

    sort(a+1 , a + q+ n + 1,check);

    int* bit = new int[n+1];
    fill_n(bit,n+1,0);

    int* ans = new int[q+1];

    for (int i = 1; i < n+q+1; i++)
    {
        if(a[i].l!=0){

            ans[a[i].pos]=(query(a[i].r,bit) - query((a[i].l)-1,bit));
        }
        else
        {
            update(i,bit,n);
        }
        
    }

    for (int i = 1; i <= q; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    

    delete[] bit;
    delete[] ans;
    delete[] a;
    delete[] arr;
    return 0;
}