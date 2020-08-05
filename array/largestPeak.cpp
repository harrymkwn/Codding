#include <bits/stdc++.h>
using namespace std;

int longestPeak(vector<int> array)
{
    vector<int> pre(array.size(), 1);
    vector<int> suf(array.size(), 1);
    int max = INT_MIN;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] > array[i - 1])
            pre[i] = pre[i - 1] + 1;
    }
    for (int j = array.size() - 2; j >= 0; j--)
    {
        if (array[j] > array[j + 1])
            suf[j] = suf[j + 1] + 1;
    }
    for (int i=0;i<array.size();i++){

        if(pre[i]==1 || suf[i]==1)continue;
        int curSum = pre[i] + suf[i] -1;
        if(curSum>=3 && curSum > max)max=curSum;
    }

        return max == INT_MIN ? 0 : max;
}

int main(){
    cout<<longestPeak({5,4,3,2,1,2,1});
}