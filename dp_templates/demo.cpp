#include<bits/stdc++.h>
#include<dp.h>
using namespace std;

int main(){
    dp obj;

    int n,w;
    cin>>n>>w;
    vector<int>weights(n,0);
    vector<int>values(n,0);

    for(int i=0;i<n;i++)
        cin>>weights[i];
    for(int i=0;i<n;i++)
        cin>>values[i];

    
    cout<<obj.knapSack(weights,values,w);
    return 0;
}