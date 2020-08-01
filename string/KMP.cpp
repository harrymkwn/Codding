#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> knuthMorisPrattPatternSearching(string str,string ptn){
    vector<int> suf(ptn.size()+1,0);
    vector<int> start;
    for(int j=0,i=1;i<ptn.size();i++){
        if(ptn[i]==ptn[j] && i!=j){suf[i]=j+1;j++;}
        else {
            j=0;
            if(ptn[i]==ptn[j]){suf[i]=j+1;j++;}
        }
    }
    
    for(int j=0,i=0;i<str.size();){
        if(str[i]==ptn[j]){
            while(str[i]==ptn[j]){
                i++;
                j++;
            }
            if(j==ptn.size()){start.push_back(i-ptn.size());i++;j=0;}
            else j=suf[i];
        }else i++;
    }
    return start;
}

string finalized(string str,string ptn){
    vector<int> v = knuthMorisPrattPatternSearching(str,ptn);
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<"\n";
    int j=0;
    if(v.empty())return str;
    for(int i=0;i<str.size();i++){
        if(i>v[j])j++;
        else if(i==v[j]){
            str.insert(v[j] + j,"_");
            str.insert(v[j] + ptn.size() + j+1,"_");
            i=v[j] + ptn.size() + 2*j + 1;
            j++;
        }
    }
    return str;
}

int main(){
  
  cout<<finalized("abcaabababaaaababc","aba")<<"\n";
  return 0;
}