#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string longestSubstringWithoutDuplication(string str)
{
    int start = 0,m=0,mi=0;
    unordered_map<char,int> mp;

    for(int i=0;i<str.size();i++){
        if(mp.find(str[i])==mp.end())mp[str[i]]=i;
        else if(mp[str[i]] >= start){
            if(m<i-start){
                m = i-start;
                mi = start;
            }
            start = mp[str[i]]+1;
            mp[str[i]] = i;
        }else
        {
            mp[str[i]]=i;
        } 
    }
    return str.substr(mi,m);
}

int main()
{
    string str= "abcdabcef";
    cout<<longestSubstringWithoutDuplication(str)<<"\n";
    return 0;
}