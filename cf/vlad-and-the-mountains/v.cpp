#include "silky/stl.hpp"
using namespace std;
#define int ll
int Tmain(){
    READ(int,N,M);
    Vec<int>A(N+1);read(A);
    Vec<ai3>edges(M+1);
    FOR(i,1,M){
        READ(int,u,v);
        edges[i]=ai3{max(A[u],A[v]),u,v};
    }
    edges.sort();
    DSU dsu(N+1);
    Vec<int>rt(N+1),p(2*N+1),W(2*N+1);
    Vec<Vec<int>>t(2*N+1);
    FOR(i,1,N)rt[i]=i;
    int tot=N;
    for(auto [w,u,v]:edges){
        int a=dsu[u],b=dsu[v];
        if(a==b)continue;
        int x=++tot;
        W[x]=w;
        p[rt[a]]=p[rt[b]]=x;
        t[x].push_back(rt[a]);
        t[x].push_back(rt[b]);
        dsu(a,b);
        rt[dsu[a]]=x;
    }
    constexpr int LOG=21;
    Vec<array<int,LOG>> lift(tot+1);
    Vec<int>dep(tot+1),root(tot+1);
    ROF(i,tot,1){
        lift[i][0]=p[i]?p[i]:i;
        dep[i]=p[i]?dep[p[i]]+1:0;
        root[i]=p[i]?root[p[i]]:i;
    }
    FOR(j,1,LOG-1)FOR(i,1,tot)lift[i][j]=lift[lift[i][j-1]][j-1];
    auto lca=[&](int u,int v)->int{
        if(root[u]!=root[v])return -1;
        if(dep[u]<dep[v])swap(u,v);
        ROF(j,LOG-1,0){
            if(dep[lift[u][j]]>=dep[v])
                u=lift[u][j];
        }
        if(u==v)return u;
        ROF(j,LOG-1,0){
            if(lift[u][j]!=lift[v][j]){
                u=lift[u][j];
                v=lift[v][j];
            }
        }
        return lift[u][0];
    };
    READ(int,Q);
    FOR(i,1,Q){
        READ(int,u,v,w);
        int x=lca(u,v);
        YES((x==-1?1e18:W[x])<=A[u]+w);
    }
    return 0;
}
