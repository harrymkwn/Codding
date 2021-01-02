#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        string inexp;
        string postexp="";
        stack<char> s;
        map<char,int> prec;
        prec['+']=1;
        prec['-']=1;
        prec['/']=2;
        prec['*']=2;
        prec['^']=3;
        cin>>inexp;
        for(auto x:inexp){
            if(x=='('){
                s.push(x);
            }    
            else if(x==')'){
                while(!s.empty() and s.top()!='('){
                    char top = s.top();
                    s.pop();
                    postexp += top;
                }
                if(!s.empty())s.pop();
            }
            else if(x=='*' or x=='+' or x=='-' or x=='/' or x=='^'){
                while(!s.empty() and s.top()!='(' and prec[s.top()]>prec[x]){
                    char top = s.top();
                    s.pop();
                    postexp+= top;
                }
                s.push(x);
            }
            else{
                postexp += x;
            }
        }
        while(!s.empty() and s.top()!='('){
            char top = s.top();
            s.pop();
            if(top!='(' and top!=')')postexp += top;
        }
        cout<<postexp<<"\n";
    }
    return 0;
}