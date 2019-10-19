#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
    cin>>n;
    int * arr = new int[n+1];
    int count=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(abs(arr[i]-i)>2){
            cout<<"NO";
            return 0;
        }
        if(arr[i]!=i){
            count+=abs(arr[i]-i);
        }
    }
    cout<<"YES\n"<<count/2;
    return 0;

       
}