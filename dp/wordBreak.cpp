#include<bits/stdc++.h>
using namespace std;
string ltrim(string& s,  const string& delimiters = " \f\n\r\t\v" )
{
    s.erase( 0, s.find_first_not_of( delimiters ) );
    return s;
}


bool wordBreakUtils(string s,unordered_set<string>& uset,unordered_map<string,bool> &dp){

    if(0==s.length())return true;
    if(dp[s])return true;
    for(int j=1;j<=s.length() && !dp[s];j++){

        string sub = s.substr(0,j);
        if(uset.find(sub)!=uset.end()){
            dp[s] = wordBreakUtils(s.substr(j),uset,dp);
        }
    }
    
    return dp[s];
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,bool> dp;
    unordered_set<string> uset;

    for(string &x : wordDict)uset.insert(x);
    return wordBreakUtils(s,uset,dp);       
}

bool wordBrakIterative(string s, vector<string> &wordDict){
    unordered_set<string> uset;
    int maxlen=0;
    for(string &x : wordDict)uset.insert(x);
    
    for(auto x : uset){
        maxlen = max(maxlen,(int)x.length());
    }
    vector<bool> dp(s.length()+1,false);
    dp[0]=true;
    for(int i=1;i<=s.length();i++){
        for(int j=i;j>=0;j--){
            string temp = s.substr(j,i-j);
            if(uset.find(temp)!=uset.end()){
                dp[i] = dp[i] || dp[j];
            }
        }
        cout<<dp[i]<<" ";
    }
    return dp[s.length()];   
}

void findAllwordBreakSentancesUtils(string s,unordered_set<string>& uset,vector<string> &ret,string out){

    if(0==s.length()){ret.push_back(ltrim(out));}
    for(int j=1;j<=s.length();j++){

        string sub = s.substr(0,j);
        if(uset.find(sub)!=uset.end()){
            findAllwordBreakSentancesUtils(s.substr(j),uset,ret,(out + " " + sub));
        }
    }    
}

vector<string> findAllwordBreakSentances(string s, vector<string>& wordDict) {
    vector<string> ret;

    unordered_set<string> uset;

    for(string &x : wordDict)uset.insert(x);
    findAllwordBreakSentancesUtils(s,uset,ret,""); 

    return ret;
}

int main(){
    
    return 0;
}