#include <bits/stdc++.h>
using namespace std;

bool iscorrect(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

string findlongest(vector<vector<int>> grid, int n, int m, int i, int j, unordered_map<string, string> &mp)
{

    if (!iscorrect(i, j, n, m))
        return 0;

    string key = to_string(i) + "|" + to_string(j);

    if (mp.find(key) == mp.end())
    {
        string path="";

        if (j > 0 && grid[i][j] == grid[i][j - 1] + 1)
            path = findlongest(grid, n, m, i, j - 1, mp);
        if (i > 0 && grid[i][j] == grid[i - 1][j] + 1)
            path = findlongest(grid, n, m, i - 1, j, mp);
        if (i < n - 1 && grid[i][j] == grid[i + 1][j] + 1)
            path = findlongest(grid, n, m, i + 1, j, mp);
        if (j < m - 1 && grid[i][j] == grid[i][j + 1] + 1)
            path = findlongest(grid, n, m, i, j + 1, mp);

        mp[key] = to_string(grid[i][j]) + "-" + path;
    }

    return mp[key];
}

int main()
{
    unordered_map<string ,string> mp;
    vector<vector<int>> grid;
    int n,m;
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>grid[i][j];

    int maxlen=0;
    string maxstr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            string str = findlongest(grid,n,m,i,j,mp);

            int size = count(str.begin(),str.end(),'-');

            if(size > maxlen){
                maxstr = str;
                maxlen = size;
            }
        }
    }
    maxstr = maxstr.substr(0,maxstr.length()-1);
    reverse(maxstr.begin(),maxstr.end());
    cout<<maxlen<<"\n"<<maxstr<<"\n";
    return 0;
}