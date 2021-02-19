#include<bits/stdc++.h>
using namespace std;

void wordbreak(unordered_map<string,bool> &dict,string s,string out){
    if(s.length()==0){
        cout<<out<<"\n";
        return;
    }

    for(int i=1;i<=s.length();i++){
        string temp = s.substr(0,i);

        if(dict.find(temp) != dict.end()){
            wordbreak(dict,s.substr(i),out + " " + temp);
        }
    }
}


int main(){
    unordered_map<string,bool> mp;
    vector<string> dict = { "this", "th", "is", "famous", "Word", "break","b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
    for(auto x : dict)mp[x] = true;
    string str;
    cin>>str;

    wordbreak(mp,str,"");
    return 0;
}