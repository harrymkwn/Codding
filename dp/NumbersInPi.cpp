#include<bits/stdc++.h>
using namespace std;

int numbersInPi(string pi, vector<string> numbers)
{
    set<string> numbersTable;
    for(string val:numbers)numbers.push_back(val);

    unordered_map<int,int> cache;
    int minSpaces = getMinimumSpaces(pi,numbersTable,&cache,0);
    return minSpaces == INT_MAX ? -1 : minSpaces;
}

int getMinimumSpaces(string pi,set<string> numbersTable,unordered_map<int,int> *cache,int idx){
    if(idx == pi.length())return -1;
    if(cache->find(idx) != cache->end()){ return cache->at(idx); }

    int minSpaces=INT_MAX;
    for(int i=idx ; i<pi.size();i++){
        string prefix = pi.substr(idx,i-idx+1);
        if(numbersTable.find(prefix) != numbersTable.end()){
            int minSpacesSuffix = getMinimumSpaces(pi,numbersTable,cache,i+1);

            if(minSpacesSuffix == INT_MAX){
                minSpaces = min(minSpaces,minSpacesSuffix); 
            }else{
                minSpaces = min(minSpaces,minSpacesSuffix + 1);
            }
        }
    }
    cache->insert({idx,minSpaces});
    return cache->at(idx);
}