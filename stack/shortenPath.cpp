#include<bits/stdc++.h>
using namespace std;

bool isTokenImportant(string token){ return token.length() && token!=".";}

string shortenPath(string path) {

    vector<string> tokens;
    vector<string> filteredTokens;
    bool isAbsolute = path[0] == '/';
    string token;

    istringstream iss(path);

    while (getline(iss,token,'/'))
    {
        tokens.push_back(token);
    }
    copy_if(tokens.begin(),tokens.end(),back_inserter(filteredTokens),isTokenImportant);
    
    vector<string> stack;

    if(isAbsolute)stack.push_back("");

    for(string token : filteredTokens){

        if(token==".."){
            if(stack.size()==0 || stack[stack.size()-1]==".."){
                stack.push_back(token);
            }else if(stack[stack.size()-1]!=""){
                stack.pop_back();
            }
        }else
        {
            stack.push_back(token);
        }        
    }
    if(stack.size()==1 && stack[0]=="")return "/";

    ostringstream oss;
    for (int i = 0; i < stack.size(); i++)
    {
        if(i!=0)oss<<"/";
        oss<<stack[i];
    }

    return oss.str();
}



// string shortenPath(string path) {

//     stack<string> s;
//     int i=0;
//     int n = path.size();

//     for(int i=0;i<n;){
//         if(path[i]=='.' && i!=n-1){
//             if(path[i+1]=='.' && !s.empty() && s.top()!=".."){
//                 s.pop();
//                 i+=2;
//             }
//             else if(path[i+1]=='.'){
//                 s.push("..");
//                 i+=2;
//             }
//             else  i++;
//         }
//         else if(path[i]!='/'){
//             string str = "";
//             while(path[i]!='/' && i<n){
//                 str += path[i];
//                 i++;
//             }
//             s.push(str);
//         }else
//         {
//             if(path[i]=='/')i++;
//             while(path[i]=='/'){
//                 i++;
//             }
//         }
        
//     }
//     string str = "";

//     while(!s.empty()){
//         str = "/" + s.top() + str;
//         s.pop();
//     }
//     if(path[0]!='/')str.erase(str.begin()+0);
//     if(str.empty() && path[0]=='/')str = "/";
//     return str;
// }


int main(){
    string str = "../../foo/bar/baz";
    cout<<shortenPath(str)<<"\n";
}