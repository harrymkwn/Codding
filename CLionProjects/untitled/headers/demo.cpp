//
// Created by harry on 17/4/19.
//
#include "demo.h"
#include <bits/stdc++.h>
using namespace std;
//
//void dfs(int x){
//    void dfs(ll cur)
//    {
//        vis[cur]=1;
//        for(auto i:gr[cur])
//        {
//            if(!vis[i.f])
//            {
//                dist[i.f]=dist[cur]+i.se;
//                dfs(i.f);
//            }
//        }
//    }
//}

void  demo::setvalue(int x) {
    book_id = x;
}
int demo::getvalue() {
    return book_id;
}
int  demo::sum(int x){
    return book_id+x;
}