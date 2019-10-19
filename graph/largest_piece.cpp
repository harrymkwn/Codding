#include<bits/stdc++.h>
using namespace std;
int n;
bool check(char** cake,int n,bool** visited,int x, int y){
    if(x>=0 && x<n && y>=0 && y<n && !visited[x][y] && cake[x][y]=='1')
        return true;
    return false;
}


int dfs(char** cake,int n,bool** visited,int x, int y){
    int l=0,r=0,u=0,d=0;
    
    if(check(cake,n,visited,x,y)){
        visited[x][y]=true;
        l = dfs(cake,n,visited,x,y-1);
        r = dfs(cake,n,visited,x,y+1);
        u = dfs(cake,n,visited,x-1,y);
        d = dfs(cake,n,visited,x+1,y);
        return 1+l+r+u+d;
    }
    else
    {
        return 0;
    }
}


int solve(int n,char** cake)
{
    int maxans=0;
	bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]= new bool[n];
        for(int j=0;j<n;j++)
            visited[i][j]==false;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!visited[i][j] && cake[i][j]=='1')
            {   
                int ans= dfs(cake,n,visited,i,j);
                maxans = max(ans,maxans);
            }
    delete[] visited;
    return maxans;
}

int main(){
    cin>>n;
    char** cake = new char*[n];
    for(int i=0;i<n;i++){
        cake[i]=new char[n];
        for(int j=0;j<n;j++)
        cin>>cake[i][j];
    }
    cout<<solve(n,cake);
}