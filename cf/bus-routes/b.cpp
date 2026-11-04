#include <bits/stdc++.h>
using namespace std;
#include "silky/stl.hpp"
int main() {
    int T;cin>>T;while(T--){
        int N,M;read(N,M);
        Graph<0>g(N);g.read_tree();
        Vec<pii>R(M+1);read(R);
        if(N==2){
            YES(R.any(LAM(pii x, (x.first==1&&x.second==2)||(x.first==2&&x.second==1))));
            return 0;
        }
        Vec<Vec<int>>dest(N+1);
        for(auto [u,v]:R)dest[u].push_back(v),dest[v].push_back(u);
        int r;
        FOR(i,1,N)if(g.deg(i)>1)r=i;
        vector<int>leaves;
        int t=1;
        Vec<int>tin(N+1),tout(N+1);
        auto dfs=[&](int u,int p){
            bool leaf=true;
            tin[u]=t++;
            for(auto [v,_]:g[u]){
                if(v==p)continue;
                leaf=false;
            }
            tout[u]=t++;
            if(leaf)leaves.push_back(u);
        };
        dfs(r,-1);
        for(auto u:leaves){
            dest[u].sort([&](int x,int y){ return tin[x]<tin[y]; });
            for(auto v:dest[u]){

            }
        }
    }
}
