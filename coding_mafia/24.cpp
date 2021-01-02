#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<long long> arr(20,1);
    for(int i=1;i<20;i++)arr[i] = arr[i-1]*(i+1); 

    while (t--)
    {
        int x;
        cin>>x;
        cout<<arr[x == 0 ? 0 : x-1]<<"\n";
    }
    
    return 0;
}