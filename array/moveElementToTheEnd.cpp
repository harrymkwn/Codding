#include <bits/stdc++.h>
using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{   
    if(array.empty())return array;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<array.size();i++)if(array[i]==toMove)q.push(i);
    if(q.empty())return array;
    int i=0,j=q.top();
    while (i<array.size() && j<array.size())
    {
        if(array[i]==toMove){i++;continue;}
        if(j<i){
            swap(array[i],array[j]);
            q.pop();
            q.push(i);
            j=q.top();
        }
        i++;
    } 
    return array;
}

int main(){
    vector<int> array({1, 2, 4, 5, 3});
    int k = 3;
    vector<int> ret = moveElementToEnd(array,k);
    for(int i=0;i<ret.size();i++)cout<<ret[i]<<" ";
    return 0;
}