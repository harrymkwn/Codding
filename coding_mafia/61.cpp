#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n,k;
    cin>>a>>n>>k;
    vector<int> arr(k,0);
    for(int i=0; a>0;i++){
        arr[i]= a%(n+1);
        a/=(n+1);
    }
    for(int i=0;i<k;i++)cout<<arr[i]<<" ";

    return 0;
}