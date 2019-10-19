#include<bits/stdc++.h>
using namespace std;

int minstep(int* arr,int n){

    bool* visited = new bool[n];
    vector<int>occurnces[10];
    int* distance = new int[n];

    for(int i=0;i<n;i++){
        occurnces[arr[i]].push_back(i);
        visited[i]=false;
        distance[i]=0;
    }


    queue<int>q;
    q.emplace(0);
    distance[0]=0;
    visited[0]=true;


    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        if(pos==n-1)
            break;

        for(int i=0;i<occurnces[arr[pos]].size();i++){
            int v = occurnces[arr[pos]][i];
            if(!visited[v]){
                visited[v]=true;
                distance[v] = distance[pos]+ 1;
                q.emplace(v);
            }
        }
        if(pos+1<n && !visited[pos+1]){
                visited[pos+1]=true;
                distance[pos+1] = distance[pos]+1;
                q.emplace(pos+1);
            }
        if(pos-1>=0 && !visited[pos-1]){
                visited[pos-1]=true;
                distance[pos-1]=distance[pos]+1;
                q.emplace(pos-1);
            }
    }
    int ans = distance[n-1];
    delete[] visited;
    delete[] distance;
    return ans;
    
}



int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<minstep(arr,n);
}