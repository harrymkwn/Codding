#include <bits/stdc++.h>
using namespace std;

vector<int> largestRange(vector<int> array)
{
    if(array.empty())return {-1,-1};
    if(array.size()==1)return {array[0],array[0]};
    unordered_map<int,bool>mp;
    vector<int> bestRange;
    int longestRange = INT_MIN;
    for(int i=0;i<array.size();i++)mp[array[i]]=true;
    
    for(int val : array){
        if(!mp[val])continue;
        mp[val] = false;
        auto currentValue = mp[val];
        int currentLength =1;
        int left = currentValue - 1;
        int right = currentValue + 1;

        while (mp.find(left)!= mp.end())
        {
            mp[left]=false;
            left--;
            currentLength++;
        }
        while (mp.find(right)!= mp.end())
        {
            mp[right]=false;
            right++;
            currentLength++;
        }
        if(currentLength > longestRange){
            longestRange = currentLength;
            bestRange = {left+1,right-1};
        }
    }

    return bestRange;
}

int main(){
    vector<int> ret = largestRange({1,11,3,0,15,5,2,4,10,7,12,6});
    for(int i=0;i<ret.size();i++)cout<<ret[i]<<" ";
    return 0;
}