#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int main(){


    vector<int> arr = {1,2,3,3,4,5};
    auto pos = std::adjacent_find(std::begin(arr), std::end(arr));
    if (pos != std::end(arr)) {
      cout<<"yaay there is present ";
    }
  return 0;
}