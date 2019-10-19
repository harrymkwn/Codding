#include <bits/stdc++.h>
using namespace std;

struct node{
    int i,level;

    node() : i(0),level(0){}
};
int snake_steps(int* moves){

    bool* visited = new bool[150];
    memset(visited,false,101);
    queue<node> q;

    node qe;
    qe.i=1;
    qe.level=0;
    q.push(qe);
    visited[1]=true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if(top.i==99)
            return top.level;

        for(int j=top.i+1;j<=top.i+6 && j<100;j++){
            if(!visited[j]){

                visited[j]=true;
                qe.level = top.level + 1;

                if(moves[j])
                    qe.i=moves[j];
                else
                    qe.i=j;
                q.push(qe);
        }
    }
    }
    return 0;
    
}


int main()
{
    int *moves = new int[150];
    for(int j=0;j<=100;j++)moves[j]=0;
    //stairs
    moves[2]=38;
    moves[4]=14;
    moves[9]=31;
    moves[33]=85;
    moves[52]=88;
    moves[88]=99;

    //snakes
    moves[98]=8;
    moves[51]=11;
    moves[92]=53;
    moves[56]=15;
    moves[62]=57;

    cout<<snake_steps(moves);

    delete[] moves;
}