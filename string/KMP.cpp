#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool/*vector<int> */knuthMorisPrattPatternSearching(string str,string substr){
    vector<int> suf(substr.size()+1,0);
    // vector<int> start;
    for(int j=0,i=1;i<substr.size();i++){
        if(substr[i]==substr[j] && i!=j){suf[i]=j+1;j++;}
        else {
            j=0;
            if(substr[i]==substr[j]){suf[i]=j+1;j++;}
        }
    }
    
    for(int j=0,i=0;i<str.size();){
        if(str[i]==substr[j]){
            while(str[i]==substr[j]){
                i++;
                j++;
            }
            if(j==substr.size()){/*start.push_back(i-substr.size());i++;j=0;*/return true;}
            else j=suf[i];
        }else i++;
    }
    return false;
}

// string finalized(string str,string substr){
//     vector<int> v = knuthMorisPrattPatternSearching(str,substr);
//     for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
//     cout<<"\n";
//     int j=0;
//     if(v.empty())return str;
//     for(int i=0;i<str.size();i++){
//         if(i>v[j])j++;
//         else if(i==v[j]){
//             str.insert(v[j] + j,"_");
//             str.insert(v[j] + substr.size() + j+1,"_");
//             i=v[j] + substr.size() + 2*j + 1;
//             j++;
//         }
//     }
//     return str;
// }

int main(){
  
  cout<<knuthMorisPrattPatternSearching("abcaabababaaaababc","abga")<<"\n";
  return 0;
}