#include <bits/stdc++.h>
using namespace std;
class Solution
{

    class Employee{
    public:
        int id;
        int importance;
        vector<int> subordinates;
    };

public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int importance=0;
        queue<int> q;
        q.push(id-1);

        while (!q.empty())
        {
            int cv = q.front();
            q.pop();
            
            importance += employees[cv]->id;

            for (auto x : employees[cv]->subordinates){
                q.push(x-1);
            }
        }
        return importance;
    }
};