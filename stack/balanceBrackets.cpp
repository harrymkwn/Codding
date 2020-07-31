#include<bits/stdc++.h>
using namespace std;

bool balancedBrackets(string str) {
    stack<char> s;
    
    for(int i=0;i<str.size();i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] != '}' && str[i] != ']' && str[i] != ')')cout<<str[i]<<"\n";
        else if(s.empty() && (str[i] == '}' || str[i] == ']' || str[i] == ')')){
            return false;
        }
        else if(str[i] == '}' && s.top() == '{')s.pop();
        else if(str[i] == ']' && s.top() == '[')s.pop();
        else if(str[i] == ')' && s.top() == '(')s.pop();
    }
    if(!s.empty())return false;
    return true;
}

int main(){
    string str = "(a)";
    if(balancedBrackets(str))cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}