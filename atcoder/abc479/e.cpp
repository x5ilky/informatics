#include <bits/stdc++.h>
#include <silky/stl.hpp>
using namespace std;
#define int long long
signed main() {
    int N;cin>>N;
    Graph<0>g(N);
    vector<pii>E(N);
    FOR(i,1,N-1){
        int u,v;cin>>u>>v;
        E[i]={u,v};
        g(u,v);
    }
    int t=1;
    Vec<int>tin(N+1),tout(N+1),untin(N+1),sz(N+1,1);
    function<void(int,int)>dfs=[&](int u,int p){
        untin[tin[u]=t++]=u;
        for(auto [v,_]:g[u]){
            if(v==p)continue;
            dfs(v,u);
            sz[u]+=sz[v];
        }
        tout[u]=t;
    };
    dfs(1,-1);
    Vec<int>d(N+2);
    FOR(i,1,N-1){
        auto[u,v]=E[i];
        if(tin[v]<tin[u])swap(u,v);
        // printf("uv = %d %d, %d %d\n",u,v,tin[u],tin[v]);
        if(sz[v]>N/2){
            d[tin[v]]+=i;
            d[tout[v]]-=i;
        }else{
            d[1]+=i;
            d[tin[v]]-=i;
            d[tout[v]]+=i;
        }
        // dcheck(d);
    }
    {
        Vec<int>ans(N+1);
        int D=0;
        FOR(i,1,N){
            D+=d[i];
            ans[untin[i]]=D;
        }
        write(ans);
    }
}
