#include<bits/stdc++.h>
using namespace std;

void eulerTotient(int n){

    int* arr = new int[n+1];
    for(int i=0;i<=n;i++)arr[i]=i;
    for(int i=2;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=2;i<=n;i++){
        if(arr[i]==i)
        {
            arr[i]=i-1;
            for(int j=i*2;j<=n;j+=i)
                arr[j] = (int)((arr[j]*(i-1))/(i));
        }
    }
    for(int i=2;i<=n;i++)
        cout<<arr[i]<<" ";
}


int main(){

int n=25;
eulerTotient(n);
}