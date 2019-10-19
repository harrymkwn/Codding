#include<bits/stdc++.h>
using namespace std;

bool detetcycleUtil(int v,vector<int>* arr ,bool*visited,bool* recstack){
    if(!visited[v]){
        visited[v] = true;
        recstack[v] = true;

        vector<int>::iterator i;
        for(auto i : arr[v]){
            if(!visited[i] && detetcycleUtil(i,arr,visited,recstack))
                return true;
            else if(recstack[v])
                return true;
        }
    }
    recstack[v]=false;
    return false;
}

bool detectcycle(vector<int>* arr ,bool*visited,bool* recstack,int n){
    for(int i=0;i<n;i++){
        if(detetcycleUtil(i,arr,visited,recstack))
            return true;
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<int>arr[n];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        arr[x-1].push_back(y-1);
        arr[y-1].push_back(x-1);
    }
    bool* visited = new bool[n];
    memset(visited,false,n);
    bool* recstack = new bool[n];
    memset(recstack,false,n);
    
    if(detectcycle(arr,visited,recstack,n))
        cout<<"there is cycle";
    else cout<<"there is no cycle";

    return 0;
}