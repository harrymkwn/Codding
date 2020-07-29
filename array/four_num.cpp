#include <bits/stdc++.h>
using namespace std;

void fourNumberSum(vector<int> array, int targetSum) {

    map<int,vector<pair<int,int>>>mp;
    map<pair<pair<int,int>,pair<int,int>>,bool> s;
    vector<vector<int>> ret;
    ret.resize(array.size()*array.size(),vector<int>(4));
    sort(array.begin(),array.end());

    for(int i=0;i<array.size();i++)
    for(int j=i+1;j<array.size();j++){
        mp[array[i]+array[j]].push_back({array[i],array[j]});
    }

    map<int,vector<pair<int,int>>>::iterator ptr;
    map<int,vector<pair<int,int>>>::iterator str;
    int k=0;

    while (ptr->first * 2 <=targetSum && ptr!=mp.end())
    {
        if((str = mp.find(targetSum - ptr->first)) != mp.end()){
            for(int i=0;i<ptr->second.size();i++)
            for(int j=0;j<str->second.size();j++){
                
            }
        }
    }
    
}


int main(){
    int n,targetSum;
    cin>>n>>targetSum;
    vector<int> array(n,0);
    for(int i=0;i<n;i++)cin>>array[i];

    fourNumberSum(array,targetSum);
    return 0;
}