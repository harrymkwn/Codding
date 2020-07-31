#include<bits/stdc++.h>
using namespace std;

string shortenPath(string path) {

    stack<string> s;
    int i=0;
    int n = path.size();

    for(int i=0;i<n;){
        if(path[i]=='.' && i!=n-1){
            if(path[i+1]=='.' && !s.empty() && s.top()!=".."){
                s.pop();
                i+=2;
            }
            else if(path[i+1]=='.'){
                s.push("..");
                i+=2;
            }
            else  i++;
        }
        else if(path[i]!='/'){
            string str = "";
            while(path[i]!='/' && i<n){
                str += path[i];
                i++;
            }
            s.push(str);
        }else
        {
            if(path[i]=='/')i++;
            while(path[i]=='/'){
                i++;
            }
        }
        
    }
    string str = "";

    while(!s.empty()){
        str = "/" + s.top() + str;
        s.pop();
    }
    if(path[0]!='/')str.erase(str.begin()+0);
    if(str.empty() && path[0]=='/')str = "/";
    return str;
}


int main(){
    string str = "../../foo/bar/baz";
    cout<<shortenPath(str)<<"\n";
}