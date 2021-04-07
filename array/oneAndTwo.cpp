#include<bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {

    int i= 0,n = bits.size();
    while (i<n)
    {
        if(bits[i]==0){i++;if(n==i)return true;}
        else i+=2;
    }
    return false;            
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<isOneBitCharacter(arr);
    return 0;
}