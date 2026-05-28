#include "fun.h"
#include <bits/stdc++.h> 
using namespace std;
vector<int> createFunTour(int N, int Q) {
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(hoursRequired(i,j))g[i].push_back(j);
        }
    }
    vector<int>sz(N+1);
    function<void(int,int)>fsz=[&](int u,int p){
        sz[u]=1;
        for(auto v:g[u])if(v!=p)fsz(v,u),sz[u]+=sz[v];
    };
    function<int(int,int,int)>fcentr=[&](int u,int p,int s){
        for(auto v:g[u])if(v!=p&&sz[v]*2>s)return fcentr(v,u,s);
        return u;
    };
    fsz(1,-1);
    int centr=fcentr(1,-1,sz[1]);

}
