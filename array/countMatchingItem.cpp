#include<bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

    int i = ruleKey == "type" ? 0 : (ruleKey == "color" ? 1 : 2);
    return count_if(items.begin(),items.end(), [&](auto const &x){return x[i]==ruleValue} );
}

int main(){
    
    return 0;
}