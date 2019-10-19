#include<bits/stdc++.h>
using namespace std;

bool level_order_traversal(int* pre,int n){

    stack<int> s;
    int root=INT_MIN;

    for(int i=0;i<n;i++){

        if(pre[i]<root)
            return false;

        while (!s.empty() && pre[i]>s.top())
        {
            root = s.top();
            s.pop();
        }
        
        s.push(pre[i]);
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)cin>>pre[i];

    if(level_order_traversal(pre,n))
        cout<<"array in level order\n";
    else
        cout<<"array not in level order\n";

    return 0;
}