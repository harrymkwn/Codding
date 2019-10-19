//
// Created by harry on 24/5/19.
//

#ifndef UNTITLED_DP__H
#define UNTITLED_DP__H


class dp_ {
private:
    struct maxValues{
        int maximumSum=0;
        int maximumLeft=0;
        int maximumRight=0;
        int maximumUp = 0;
        int maximumDown=0;
    }lastAns;
public:
    void fibonaki(int n);
    void alph_code(char* arr,int n);
    void lis(int* arr,int n,int** d);
    void lds(int* arr,int n,int** d);
    void bitonicsubarray(int *arr , int n);
    int minimumCost(int cells[][3],int n,int m);
    int friendPairing(int n);
    bool ifthere(int a[],int n,int sum);
    int cutrod(int arr[],int n);
    void paintFence(int n,int k);
    void khadane(int* arr , int n,int L , int R,dp_::maxValues & lastAns);
    void maximumSum(int grid[4][5],int n,int m);
    int longestCommonSubsequence(string a,string b);
    int maxProfit(int* price , int n);
};


#endif //UNTITLED_DP__H
