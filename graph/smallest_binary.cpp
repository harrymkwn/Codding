#include<bits/stdc++.h>
using namespace std;



int reminder(string s,int n){

    int r=0;
    for(int i=0;i<s.length();i++){
        r = ((r*10)%n+(s[i]-'0')%n)%n;
    }
    return r;
}

//we can do this using bfs.
//int each node of graph thaere represent 0 and 1 
//every number concetnate with 0 and 1 become x0 and x1

string findmin(int n){
    queue<string>q;
    set<int>visited;
    q.push("1");
    string t;
    while (1)
    {
        t= q.front();
        q.pop();

        int r = reminder(t,n);

        if(r==0)return t;
        else if(visited.find(r)==visited.end()){
            q.emplace(t+"0");
            q.emplace(t+"1");
            visited.emplace(r);
        }
    }
    
}


int main(){
    int n;
    cin>>n;

    cout<<findmin(n)<<"\n";
}