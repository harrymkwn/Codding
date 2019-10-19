#include<bits/stdc++.h>
using namespace std;

int find(int n){
    int arr[100]={0};
    int i=0;
    while (n)
    {
        int mod = n%10;
        n/=10;
        arr[i++]=mod;
    }
    int length  =i;

    for (int i = 0; i < length-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            sort(arr,arr+i,greater<int>());
            break;
        }
    }
    int sum=0;

    for (int i = length; i >=0; i--)
    {
        sum = sum*10 + arr[i];
    }
    return sum;
} 


int main(){
    int n;
    cin>>n;
    cout<<find(n);
}