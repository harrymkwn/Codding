#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

pair<int, string> uniqueval(string word)
{

    sort(word.begin(), word.end());
    int key = 0;
    for (int i = 0; i < word.size(); i++)
    {
        key += int(word[i] - 96) * pow(2, i);
    }
    return {key, word};
}

vector<vector<string>> groupAnagrams(vector<string> words)
{
    vector<vector<string>> ret;
    ret.resize(words.size(),vector<string>(words.size()));
    map<pair<int, string>, vector<string>> mp;
    map<pair<int, string>, vector<string>>::iterator itr;
    pair<int,string> pr;
    for (int i = 0; i < words.size(); i++)
    {
        pr = uniqueval(words[i]);
        mp[pr].push_back(words[i]);
    }
    int i=0,j=0;
    for(itr = mp.begin() ;itr!= mp.end() ; itr++){
        for(j=0;j<itr->second.size();j++){
            ret[i][j] = itr->second[j];
        }
        ret[i].resize(j);
        i++;
    }
    ret.resize(i);

    return ret;
}

int main()
{
    vector<string> words({"yo","act","cat","tac","oy","flop","olfp","foo"});
    vector<vector<string>> ret = groupAnagrams(words);
    for(int i=0;i<ret.size();i++){
    for(int j=0;j<ret[i].size();j++){
        cout<<ret[i][j]<<" ";
    }
    cout<<"\n";}
    return 0;
}