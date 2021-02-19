#include<bits/stdc++.h>
using namespace std;

int findoptimal(vector<int> a,int i,int j,int n,unordered_map<string,int> &lookup){

    if(i>j)return 0;

    string key = to_string(i) + "|" + to_string(j) + "|" + to_string(n);

    if(lookup.find(key) == lookup.end()){

        lookup[key] = INT_MAX;

        int leftpart,rightpart;
        for(int k=i;k<=j;k++){
            leftpart = findoptimal(a,i,k-1,n+1,lookup);
            rightpart = findoptimal(a,k+1,j,n+1,lookup);
            int cost = a[k]*n + leftpart + rightpart;

            lookup[key] = min(lookup[key],cost);
        }
    }
    return lookup[key];
}

int main(){
    vector<int> a({25,10,20});
    int  n = a.size();
    unordered_map<string,int> lookup;

    cout<<findoptimal(a,0,n-1,1,lookup)<<"\n";

    return 0;
}