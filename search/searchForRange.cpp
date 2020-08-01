#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// int binaryHelper(vector<int>array,int start,int end,int target){

//     if(start<end){
//         int mid = (start+end)>>1;
//         if(array[mid]==target)return mid;
//         if(array[mid]>target)return binaryHelper(array,start,mid-1,target);
//         return binaryHelper(array,mid+1,end,target);
//     }
//     return -1;
// }

// vector<int> searchForRange(vector<int> array,int target){

//     int ind = binaryHelper(array,0,array.size()-1,target);
//     if(ind==-1)return {-1,-1};
//     int lastind=ind,firstind=ind;
//     while(array[ind]==array[lastind])lastind++;
//     while(array[ind]==array[firstind])firstind--;
//     return {firstind+1,lastind-1};
// }

void binaryHelper(vector<int> array, int start, int end, int target, vector<int> &finalarray, bool goLefft)
{

    if (start > end)
        return;

    int mid = (start + end) >> 1;

    if (array[mid] < target)
        return binaryHelper(array, mid + 1, end, target, finalarray, goLefft);
    else if (array[mid] > target)
        return binaryHelper(array, start, mid - 1, target, finalarray, goLefft);
    else
    {
        if (goLefft)
        {
            if (mid == 0 || array[mid - 1] != target)
            {
                finalarray[0] = mid;
                return;
            }
            else
                return binaryHelper(array, start, mid - 1, target, finalarray, goLefft);
        }
        else
        {
            if (mid == array.size() - 1 || array[mid + 1] != target){
                finalarray[1] = mid;
                return;
            }else
            {
                return binaryHelper(array,mid+1,end,target,finalarray,goLefft);
            }
            
        }
    }
}

vector<int> searchForRange(vector<int> array, int target)
{
    vector<int> finalarray(2,-1);
    binaryHelper(array,0,array.size()-1,target,finalarray,true);
    binaryHelper(array,0,array.size()-1,target,finalarray,false);
    return finalarray;
}

int main()
{
    vector<int> pair = searchForRange({0, 1, 2, 3, 4, 10}, 10);
    cout << pair[0] << " " << pair[1] << "\n";
    return 0;
}