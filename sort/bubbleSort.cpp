#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// vector<int> bubbleSort(vector<int> array) {

//   for(int i=0;i<array.size()-1;i++){
//       for(int j=0;j<array.size()-i-1;j++)
//         {
//             if(array[j]>array[j+1]){
//                 change(&array[j],&array[j+1]);
//             }
//         }
//   }
//   return array;
// } /* O(n^1) always */

vector<int> bubbleSort(vector<int> arr)
{

    if (arr.empty())
        return {};
    int counter = 1;
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;

        for (int i = 0; i < arr.size() - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        counter++;
    }
    return arr;
}
/* 
    O(n) best case
    O(n^2) average & worst case
*/

int main()
{
    vector<int> arr({9, 8, 7, 6, 5, 4, 3, 2, 1});
    vector<int> ret = bubbleSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << ret[i] << " ";
    return 0;
}