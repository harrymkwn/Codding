//
// Created by harry on 16/6/19.
//
#include <bits/stdc++.h>
using namespace std;
#include "JXJ.h"

void JXJ::magic_square(int n) {
    int ms[n][n];
    memset(ms,0, sizeof(ms));
    int i=n/2;
    int j=n-1;
    for (int num = 1; num <=n*n ;) {

        if(i==-1 && j==n)
        {
            i=0;
            j=n-2;

        } else{
            if(j==n)
                j=0;
            if(i<0)
                i=n-1;

        }
        if(ms[i][j])
        {
            j-=2;
            i++;
            continue;
        } else
            ms[i][j]=num++;

        i--;j++;
    }
    for (int k = 0; k <n ; k++) {
        for (int l = 0; l < n; l++) {
            printf("%2d ",ms[k][l]);
        }cout<<"\n";
    }
}


