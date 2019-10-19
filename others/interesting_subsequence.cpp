#include<bits/stdc++.h>
using namespace std;
int main() {

	int n,k,l;
    cin>>n>>k>>l;
    int * arr= new int[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    int mini = *min_element(arr,arr+n);
    int maxi = *max_element(arr,arr+n);
    int cost =INT_MAX;
    for(int j=mini ; j<maxi;j++){
        int inc=0,dec=0;
        for(int i=0;i<n;i++){
            if(arr[i]<j)
                inc+=j-arr[i];
            else if (arr[i]>j)
            {
                dec+=arr[i]-j;
            }
        }
        if(inc>=dec)
            cost = min(cost,(dec*k + (inc-dec)*l));
    }
    cout<<cost<<"\n";
    return 0;
}