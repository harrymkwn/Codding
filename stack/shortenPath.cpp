#include<bits/stdc++.h>
using namespace std;

string shortenPath(string path) {

    stack<string> s;
    int i=0;
    int n = path.size();
    cout<<n<<"\n";
    while (i< path.size() - 1)
    {
        if(path[i]== '/'){
            cout<<"there is problem\n";
            i++;}
        while(path[i]=='/'){
            cout<<"there is problem\n";
            i++;
        }
        if(path[i]=='.' && i!=n-1 && path[i+1]=='.' && !s.empty()){
            cout<<"there is problem\n";
            s.pop();
            i+=2;
        }
        else if(path[i]=='.' && i!=n-1 && path[i+1]== '.' && s.empty()){
            cout<<"there is problem\n";
            s.push("..");
            i+=2;
        }
        else if(path[i]=='.'){
            cout<<"there is problem\n";
            i++;}
        else if(path[i]!= '.' && path[i]!= '/'){
            cout<<"there is problem\n";
            string str = "";
            while(path[i]!='/'){
                str += path[i];
                i++;
            }
            s.push(str);
        }
    }
    string str = "";

    while(!s.empty()){
        str = "/" + s.top() + str;
        s.pop();
    }

    return str;
}


int main(){
    string str = "/foo/../test/abc";
    cout<<shortenPath(str)<<"\n";
}