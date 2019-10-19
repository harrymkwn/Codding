#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        string s;
        cin>>s;
        stack<int> sta;
        bool flag =true;
        int max=0,temp_max=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                sta.push(i);
                if(!sta.empty() && s[i-1]==')')flag = false;
            }
            else if(!sta.empty()){
                if(flag){
                    temp_max = (i-sta.top()+1);
                    cout<<i<<" "<<sta.top()<<"\n";
                }
                sta.pop();
            }
            if(sta.empty())flag=true;
            
            if(max<temp_max)
                max = temp_max;
        }
        cout<<max<<"\n";
    }
}