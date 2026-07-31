#include "swap.h"
#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>>g;
void init(int _N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    N=_N;g.resize(2*N+2);
    vector<int>HEAD(2*N+2),cycle(2*N+2);
    iota(HEAD.begin(),HEAD.end(),0); 
    function<int(int)>head=[&](int u){
        return u==HEAD[u]?u:HEAD[u]=head(HEAD[u]);
    };
    auto join=[&](int u,int v){
        u=head(u),v=head(v);
        cycle[u]|=cycle[v];
        HEAD[v]=u;
    };
    vector<array<int,3>>E(M);
    for(int i=0;i<M;i++)E[i]={W[i],U[i],V[i]};
    sort(E.begin(),E.end());
    int c=N+1;
    for(auto [w,u,v]:E){
        u=head(u),v=head(v);
        if(u==v){
            cycle[u]|=1;
            continue;
        }
        join(u,v);
        HEAD[head(u)]=c;
        g[u].push_back(c);
        g[c].push_back(u);
        g[v].push_back(c);
        g[c].push_back(v);
        c++;
    }
}

int getMinimumFuelCapacity(int X, int Y) {
  return 0;
}
