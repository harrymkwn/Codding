#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    int n;
    cout<<" Enter no of processes : ";
    cin>>n;
    vector<int> arrival(n,0);
    vector<int> service(n,0);
    queue<pair<int,pair<int,int>>> q;
    vector<int> turnAroundTime(n,0);
    for (int i = 0; i < arrival.size(); i++){cin>>arrival[n];}
    for (int i = 0; i < service.size(); i++){cin>>service[n];}
    
    int i=0;
    while (i++)
    {
        if(q.front().second.second != 0){
            q.front().second.second--;
        }else
        {
            turnAroundTime[q.front().first] = i - arrival[q.front().first];
            q.pop();
        }
        for (int j = 0; j < arrival.size(); j++)
        {
            if(arrival[j]==i)q.push({j,{0,service[j]}});
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<turnAroundTime[n]<<" ";
    }
    
    
  return 0;
}