#include <bits/stdc++.h>
using namespace std;


int waterArea(vector<int> heights)
{
    vector<int> prefix(heights.size(), 0);
    vector<int> suffix(heights.size(), 0);
    prefix[0] = heights[0];
    for (int i = 1; i < heights.size(); i++)
    {
        prefix[i] = max(prefix[i - 1], heights[i]);
    }
    suffix[heights.size()-1]=heights[heights.size()-1];
    for (int i = heights.size() - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], heights[i]);
    }
    int waterArea=0;
    for (int i = 0; i < heights.size(); i++)
    {
        waterArea += min(prefix[i],suffix[i]) - heights[i];
    }
    return waterArea;
}


int main(){
    cout<<waterArea({0, 1, 0, 1, 0});
    return 0;
}