#include<bits/stdc++.h>
using namespace std;

struct cell{
    int x,y;
    int dis;
    cell(int a,int b,int c) : x(a),y(b),dis(c){}
};


bool check(int x,int y,bool** visited){
    if( 1<=x && x<9 && 1<=y && y<9 && !visited[x][y])
        return true;
    return false;
}
int findmoves(cell pos1 , cell pos2){

    int dx[]={2,1,-1,-2,-2,-1,1,2};
    int dy[]={1,2,2,1,-1,-2,-2,-1};

    bool ** visit = new bool*[9];
    for(int i=1;i<=8;i++){
        visit[i] = new bool[9];
        for(int j=1;j<=8;j++)
            visit[i][j]=false;
    }
    queue<cell> q;
    q.emplace(pos1);
    visit[pos1.x][pos1.y]=true;

    while (!q.empty())
    {
        cell pos = q.front();
        q.pop();
        if(pos.x==pos2.x && pos.y==pos2.y)return pos.dis;
        for(int i=0;i<8;i++){
            if(check(pos.x+dx[i],pos.y+dy[i],visit)){
                int x = pos.x+dx[i];
                int y = pos.y+dy[i];

                cell paire(x,y,(pos.dis)+1);
                q.emplace(paire);
                visit[x][y]=true;
            }
        }
    }

    for(int i=0;i<10;i++)
        delete[] visit[i];
    delete[] visit;
    return 0;
    
}



int main(){
    cell start(3,3,0);
    cell end(8,8,0);
    cout<<findmoves(start,end);


}