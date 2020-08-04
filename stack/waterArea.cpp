#include<bits/stdc++.h>
using namespace std;

int waterArea(vector<int> heights)
{
    if(heights.size()<0)return -1;
    stack<int> s;
    int popedCache = 0;
    int waterArea=0;
    for (int i = 0; i < heights.size(); i++)
    {
        if(heights[i] != 0 && s.empty()){
            s.push(i);
        }
        else if(heights[i] !=0){
            if(heights[s.top()] > heights[i])
            {
                waterArea += heights[i] * (i-s.top()-1);
                s.push(i);
                popedCache = i;
            }
            else{
                waterArea += heights[s.top()] * (i-s.top()-1);
                s.pop();
                while (!s.empty() && heights[i] >= heights[s.top()])
                {
                    waterArea += (heights[s.top()]-heights[popedCache]) * (i-s.top()-1);
                    popedCache = s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
    }
    if(!s.empty()){
        int popedInd = s.top();
        s.pop();
        if(!s.empty())
            waterArea+= (heights[popedInd]-heights[popedCache]) * (popedInd-s.top()-1);
    }

    return waterArea;
}