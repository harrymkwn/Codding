#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<pair<int,int>>arr;
    for(int i=0;i<10;i++){
        arr.push_back(make_pair(i%2,10-i));
    }

    sort(arr.begin(),arr.end());

    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    }
    
}