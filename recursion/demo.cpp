#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void call(vector<int> &array)
{
    array[0] = 10;
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

void rec(vector<int> array)
{
    call(array);
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

int main()
{
    rec({1,2,3,4,5});
    return 0;
}