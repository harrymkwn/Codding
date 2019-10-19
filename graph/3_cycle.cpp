#include<bits/stdc++.h>
using namespace std;

int dfs(int** edges,int n,int sv,int count,int cv){
    if (count==-1)
        return 0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sv==i)
            continue;
        
        if(edges[sv][i]){
            if(i==cv && count==0){sum++;}
            sum += dfs(edges,n,i,count-1,cv);
        }
    }
    return sum;
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<m;i++){
        edges[u[i]-1][v[i]-1]++;
        edges[v[i]-1][u[i]-1]++;
    }
    int sum=0;
    for(int i=0;i<n;i++)
            sum+=dfs(edges,n,i,2,i);
    return sum/6;
    
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}