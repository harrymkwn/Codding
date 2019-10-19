#include<bits/stdc++.h>
using namespace std;

struct node{
    int d,p;

    node() : d(0),p(0){}
};

int find_min(int n,int d,int p,int k,node* arr,int i){
    if(i>n)return 0;
    if(i==n){
        if(p>d)
            return (d);
        else
            return (d-p)*5 + p;
    }

    if(i==0) {
        if (arr[i].d <= p) {
            return min(find_min(n, d - arr[i].d, p - arr[i].d + arr[i].p, k, arr, i + 1) + arr[i].d + k,
                       find_min(n, d - arr[i].d, p - arr[i].d, k, arr, i + 1) + arr[i].d);
        }else{
            return find_min(n, d - arr[i].d, arr[i].p, k, arr, i + 1) + p + (arr[i].d - p) * 5 + k;
        }
    }

    if (arr[i].d - arr[i-1].d<= p) {
        return min(find_min(n, d - arr[i].d + arr[i-1].d , p - arr[i].d + arr[i-1].d + arr[i].p, k, arr, i + 1) + arr[i].d - arr[i-1].d + k,
                   find_min(n, d - arr[i].d + arr[i-1].d , p - arr[i].d + arr[i-1].d, k, arr, i + 1) + arr[i].d - arr[i-1].d);
    }else{
        return find_min(n, d - arr[i].d + arr[i-1].d ,  arr[i].p, k, arr, i + 1) + p + (arr[i].d - arr[i-1].d - p) * 5 + k;
    }
}

int main(){

    int n,d,p,k;

    cin>>n>>d>>p>>k;

    node * arr = new node[n];

    for (int i = 0; i < n; i++)cin>>arr[i].d;
    for (int i = 0; i < n; i++)cin>>arr[i].p;

    int** dp  = new int*[101];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[101];
    }
    cout<<find_min(n,d,p,k,arr,0);
}