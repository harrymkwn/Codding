#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {

    sort(arrayOne.begin(),arrayOne.end());
    sort(arrayTwo.begin(),arrayTwo.end());
    int i=0,j=0;
    int max=INT_MAX;
    int n=0,m=0;
    while (i<arrayOne.size()-1 && j<arrayTwo.size()-1)  
    {
        if(max > abs(arrayOne[i] - arrayTwo[j])){
            max = abs(arrayOne[i] - arrayTwo[j]);
            n=i;m=j;
        }
        if((arrayTwo[j+1]-arrayOne[i]) > (arrayOne[i+1]-arrayTwo[j]))i++;
        else j++;
    }
    if(i==(arrayOne.size()-1)){
        while (j<arrayTwo.size())
        {
            if(max > abs(arrayOne[i]-arrayTwo[j])){
                max = abs(arrayOne[i]-arrayTwo[j]);
                n=i;m=j;
            }
            j++;
        }
    }
    if(j==(arrayTwo.size()-1)){
        while (i<arrayOne.size())
        {
            if(max > abs(arrayOne[i]-arrayTwo[j])){
                max = abs(arrayOne[i]-arrayTwo[j]);
                n=i;m=j;
            }
            i++;
        }
    }
    vector<int> ret;
    ret.push_back(arrayOne[n]);
    ret.push_back(arrayTwo[m]);
    return ret;

}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n,0);
    vector<int> arr2(m,0);
    vector<int> ret;
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=0;i<m;i++)cin>>arr2[i];

    ret  = smallestDifference(arr1,arr2);
    cout<<ret[0]<<" "<<ret[1]<<"\n";
    return 0;
}
