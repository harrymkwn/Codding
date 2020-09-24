// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;


// bool isNextSteptoGo(vector<vector<int> > maze,int x,int y,int prevx,int prevy){
//     return x>=0 && y>=0 && x<maze.size() && y<maze[0].size() && maze[x][y]!=0 && (x!=prevx || y!=prevy);
// }


// bool canfind(vector<vector<int> > maze,int x,int y,int prevx,int prevy){
//     if(maze[x][y]==9)return true;
    
//     if(isNextSteptoGo(maze,x,y-1,prevx,prevy)){
//         bool left = canfind(maze,x,y-1,x,y);
//         if(left)return left;
//     }
    
//     if(isNextSteptoGo(maze,x-1,y,prevx,prevy)){
//         bool up = canfind(maze,x-1,y,x,y);
//         if(up)return up;
//     }
    
//     if(isNextSteptoGo(maze,x+1,y,prevx,prevy)){
//         bool down = canfind(maze,x+1,y,x,y);
//         if(down)return down;
//     }
//     if(isNextSteptoGo(maze,x,y+1,prevx,prevy)){
//         bool right = canfind(maze,x,y+1,x,y);
//         if(right)return right;
//     }
    
    
//     return false;
// }

// int main()
// {
// 	int m=0,n=0;
// 	cin>>m>>n;
// 	vector<vector<int> > maze(m,vector<int>(n,0));
	
// 	for(int i=0;i<m;i++)
// 	    for(int j=0;j<n;j++)
// 	        cin>>maze[i][j];
	
// 	bool reached = canfind(maze,0,0,-1,-1);
//     if(maze[0][0]==0)reached=false;
// 	if(reached)cout<<1;
// 	else cout<<0;
// 	return 0;
// }

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool isNextSteptoGo(vector<vector<int> > maze,vector<vector<bool> > flag,int x,int y,int prevx,int prevy){
    return x>=0 && y>=0 && x<maze.size() && y<maze[0].size() && maze[x][y]!=0 && (x!=prevx || y!=prevy);
}


bool canfind(vector<vector<int> > maze,vector<vector<bool> > flag , int x,int y,int prevx,int prevy){
    if(maze[x][y]==9)return true;
    flag[x][y] = true;
    if(isNextSteptoGo(maze,flag,x,y-1,prevx,prevy)){
        bool left = canfind(maze,flag,x,y-1,x,y);
        if(left)return left;
    }
    
    if(isNextSteptoGo(maze,flag,x-1,y,prevx,prevy)){
        bool up = canfind(maze,flag,x-1,y,x,y);
        if(up)return up;
    }
    
    if(isNextSteptoGo(maze,flag,x+1,y,prevx,prevy)){
        bool down = canfind(maze,flag,x+1,y,x,y);
        if(down)return down;
    }
    if(isNextSteptoGo(maze,flag,x,y+1,prevx,prevy)){
        bool right = canfind(maze,flag,x,y+1,x,y);
        if(right)return right;
    }
    
    
    return false;
}

int main()
{
	int m=0,n=0;
	cin>>m>>n;
	vector<vector<int> > maze(m,vector<int>(n,0));
	vector<vector<bool> > flag(m,vector<bool>(n,false));
	for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	        cin>>maze[i][j];
	
// 	flag[0][0]=true;
	bool reached = canfind(maze,flag,0,0,-1,-1);
	if(maze[0][0]==0)reached=false;
	if(reached)cout<<1;
	else cout<<0;
	return 0;
}