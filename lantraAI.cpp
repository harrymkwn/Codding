#include <bits/stdc++.h>
using namespace std;

void processArray(vector<int> &arr){
    return ;
}

int main()
{
    int a;
    vector<int> arr;

    while (cin >> a)
    {
        if (a < 0)
            break;
        if (a % 7 == 0 && a > 100)
            arr.push_back(-3);
        else if(a>100)
            arr.push_back(-2);
        else if(a%7==0)
            arr.push_back(-1);
        else arr.push_back(a);
    }
    processArray(arr);

    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<"\n";
    
    return 0;
}