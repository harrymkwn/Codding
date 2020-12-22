#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int x,c=0;
        cin>>x;
        while (x)
        {   
            int last  = x%10;
            x/=10;
            if(last==4)c++;
        }
        cout<<c<<"\n";
    }
    return 0;
}