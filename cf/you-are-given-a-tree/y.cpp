#include <bits/stdc++.h>
#define PRAGMA
#include "silky/stl.hpp"
using namespace std;
#define int long long
signed main() {
    fastio();
    int N;cin>>N;
    Graph<0>g(N);g.read_tree();
    Vec<int>ord(1),par(N+1);
    function<void(int,int)>dfs=[&](int u,int p){
        for(auto [v,_]:g[u]){
            if(v==p)continue;
            par[v]=u;
            dfs(v,u);
        }
        ord.push_back(u);
    };
    dfs(1,-1);
    Vec<pii>dp(N+1);
    auto solve=[&](int k){
        FOR(i,1,N){
            int u=ord[i];
            int n=0;
            int l1=0,l2=0,l3=0;
            for(auto [v,_]:g[u]){
                if(v==par[u])continue;
                n+=dp[v].first;
                if(dp[v].second>l3)l3=dp[v].second;
                if(l3>l2)swap(l2,l3);
                if(l2>l1)swap(l2,l1);
            }
            if(l1>=k)dp[u]={n+1,l2+1};
            else if(l1+l2+1>=k)dp[u]={n+1,0};
            else dp[u]={n,l1+1};
        };
        return dp[1].first;
    };
    Vec<int>ans(N+1);
    function<void(int,int,int,int)>dnc=[&](int tl,int tr,int bl,int br){
        if(tl>tr)return;
        if(bl==br){
            FOR(i,tl,tr)ans[i]=bl;
            return;
        }
        int tm=(tl+tr)/2;
        int a=solve(tm);
        ans[tm]=a;
        dnc(tl,tm-1,bl,a);
        dnc(tm+1,tr,a,br);
    };
    ans[1]=N;
    dnc(2,N,N,0);
    FOR(i,1,N)write(ans[i]);
}
