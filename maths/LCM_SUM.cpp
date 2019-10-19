#include<bits/stdc++.h>
using namespace std;

int eulerTotient(int n){

    int* arr = new int[n+1];
    for(int i=0;i<=n;i++)arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==i)
        {
            arr[i]=i-1;
            for(int j=i*2;j<=n;j+=i)
                arr[j] = (int)((arr[j]*(i-1))/(i));
        }
    }
    
    int sum=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            sum+=i*arr[i];
    }
    sum++;
    delete [] arr;
    return (n*sum)/2;
}


int main(){

int n;
cin>>n;
cout<<eulerTotient(n)<<"\n";
}