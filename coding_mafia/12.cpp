#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    int x,c=0;
    while (n--)
    {
        cin>>x;
        if(x%k==0)c++;
    }
    cout<<c<<"\n";
    return 0;
}