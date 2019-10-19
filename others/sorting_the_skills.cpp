#include<bits/stdc++.h>
using namespace std;


string check(int a[], int n) 
{ 
    int max=INT_MIN,max_index=0;
    for(int i=1;i<n;i++){
        if((max-a[i])!=1 && max_index<i)
            return "No";
        else if(max<a[i])
            max=a[i],max_index=i;
    }
    return "Yes";
    
} 

int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        int a[x];
        for(int j=0;j<x;j++)
            cin>>a[j];
        cout<<check(a,x-1)<<endl;
    }
	return 0;
}
