#include<bits/stdc++.h>
using namespace std;

bool func(vector<int> a,vector<int> b){
    if(a[0]!=b[0])return a[0]<b[0];
    else if(a[1]!=b[1])return a[1]<b[1];
    return a[2]<b[2];
}

int main(){

    int n,targetSum,k=0;
    cin>>n>>targetSum;
    vector<int> array(n,0);
    map<pair<int,pair<int,int>>,bool> s;
    map<int,vector<pair<int,int>>> mp;
    for(int i=0;i<n;i++)cin>>array[i];
    vector<vector<int>> ret;
    ret.resize(n*n,vector<int>(3));

    for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++){
        if(array[i]<array[j])mp[array[i]+array[j]].push_back({array[i],array[j]});
        else mp[array[i]+array[j]].push_back({array[j],array[i]});
    }


    for(int i=0;i<n;i++){
        if(mp.find(targetSum-array[i]) != mp.end()){
            for(int j=0;j<mp[targetSum - array[i]].size();j++){
                int a,b,c;
                if(array[i]==mp[targetSum-array[i]][j].second || mp[targetSum-array[i]][j].first==array[i])continue;
                if(array[i]> mp[targetSum-array[i]][j].second){           
                    a = mp[targetSum-array[i]][j].first;
                    b = mp[targetSum-array[i]][j].second;
                    c = array[i];
                }else if(array[i]< mp[targetSum-array[i]][j].first)
                {
                    a = array[i];
                    b = mp[targetSum-array[i]][j].first;
                    c = mp[targetSum-array[i]][j].second;
                }else
                {
                    a = mp[targetSum-array[i]][j].first;
                    b = array[i];
                    c = mp[targetSum-array[i]][j].second;
                }
                
                
                if(!s[{a,{b,c}}]){
                    ret[k][0] = a;
                    ret[k][1] = b;
                    ret[k][2] = c;
                    s[{a,{b,c}}]=true;
                    k++;    
                }
            }
        }
    }
    ret.resize(k,vector<int>(3));
    sort(ret.begin(),ret.end(),func);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i][0]<<" "<<ret[i][1]<<" "<<ret[i][2]<<"\n";
    }

    return 0;
}