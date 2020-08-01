#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void quickSortHelper(vector<int> &arr, int start, int end);
vector<int> quickSort(vector<int> array)
{
    // quickSortHelper(array, 0, array.size() - 1);
    quickSortHelper(array, 0, 6);
    for(int i=0;i<array.size();i++)cout<<array[i]<<" ";
    return array;
}

// void quickSortHelper(vector<int> &array,int start ,int end){
//     int pivot = array[end];
//     int i= start -1;

//     for(int j = start; j<end;j++){

//         if(array[j]<pivot){
//             i++;
//             change(&array[i],&array[j]);
//         }
//     }
//     change(&array[i+1],&array[end]);

//     quickSortHelper(array,start,i);
//     quickSortHelper(array,i+2,end);
// }

void quickSortHelper(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int leftInd = start;
        int rightInd = end - 1;

        while (leftInd <= rightInd)
        {
            if (arr[leftInd] < pivot && arr[rightInd] >pivot)
            {
                swap(leftInd, rightInd);
            }
            if (arr[leftInd] <= pivot)
                leftInd++;
            if (arr[rightInd] >= pivot)
                rightInd--;
        }
        swap(arr[end], arr[rightInd]);

        quickSortHelper(arr, start, rightInd - 1);
        quickSortHelper(arr, rightInd + 1, end);
    }
}

int main()
{
    quickSort({2,3,5,5,6,8,9});
    return 0;
}