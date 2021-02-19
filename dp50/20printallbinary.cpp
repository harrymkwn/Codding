#include<bits/stdc++.h>
using namespace std;

void findndigitbinary(int n,int i,vector<string> &zeros,vector<string> &ones){

    if(i>=n){return;}
    if(i==0){
        zeros.push_back("0");
        ones.push_back("1");
        findndigitbinary(n,i+1,zeros,ones);
        return;
    }
    vector<string> temp(ones);
    ones = zeros;
    for(auto &str:ones)str.push_back('1');
    zeros.insert(zeros.end(),temp.begin(),temp.end());
    for(auto &str:zeros)str.push_back('0');
    findndigitbinary(n,i+1,zeros,ones);
}


int main(){
    int n;
    cin>>n;
    vector<string> zeros,ones;
    
    findndigitbinary(n,0,zeros,ones);
    zeros.insert(zeros.end(),ones.begin(),ones.end());
    for(auto str : zeros)cout<<str<<"\n";

    return 0;
}