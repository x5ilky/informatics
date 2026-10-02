#include "split.h"
#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
Vec<int>_find_split(int N,int A,int B,int C,Graph<0>&g){
    Vec<short>seen(N+1);
    Graph dtree(N);
    function<void(int)>dfs=[&](int u){
        seen[u]=true;
        for(auto [v,_]:g[u]){
            if(seen[v])continue;
            dtree(u,v);
            dfs(v);
        }
    };
    dfs(1);
    int centr=dtree.centroid();
    seen.fill(0);
    Vec<int>head(N+1),sz(N+1,-1),inside(N+1);
    function<void(int,int)>dfs2=[&](int u,int p){
        sz[p]++;head[u]=p;seen[u]=true;
        for(auto [v,_]:dtree[u]){
            if(v==centr||seen[v])continue;
            dfs2(v,p);
        }
    };
    FOR(i,1,N){
        if(i==centr)continue;
        if(!seen[i])sz[i]=0,dfs2(i,i);
    }
    seen.fill(0);
    int c=0;
    Vec<int>ans(N+1);
    function<void(int)>dfs3=[&](int u){
        if(c==A)return;
        seen[u]=true;c++;ans[u]=1;
        for(auto [v,_]:g[u]){
            if(seen[v]||!inside[v])continue;
            if(c==A)return;
            dfs3(v);
        }
    };
    function<void(int)>dfs4=[&](int u){
        seen[u]=true;c++;ans[u]=2;
        for(auto [v,_]:g[u]){
            if(seen[v])continue;
            if(c==B)return;
            dfs4(v);
        }
    };
    FOR(i,1,N){
        if(sz[i]==-1)continue;
        if(sz[i]>=A){
            for(int u=1;u<=N;u++)
                if(head[u]==i)
                    inside[u]=true;
            seen.fill(0);
            c=0;
            dfs3(i);
            c=0;
            dfs4(centr);
            FOR(i,1,N)if(ans[i]==0)ans[i]=3;
            return ans;
        }
    }
    Graph cg(N);
    for(int u=1;u<=N;u++){
        if(u==centr)continue;
        for(auto [v,_]:g[u]){
            if(v==centr)continue;
            if(head[u]!=head[v])
                cg(head[u],head[v]);
        }
    }
    seen.fill(0);
    FOR(i,1,N){
        if(sz[i]==-1||seen[i])continue;
        c=0;
        Vec<int>take;
        function<void(int)>dfs5=[&](int u){
            if(c>=A)return;
            seen[u]=true;
            take.push_back(u);
            c+=sz[u];
            if(c>=A)return;
            for(auto [v,_]:cg[u]){
                if(!seen[v]){
                    dfs5(v);
                    if(c>=A)return;
                }
            }
        };
        dfs5(i);
        if(c<A)continue;
        Vec<short>tk(N+1);
        for(int x:take)tk[x]=true;
        FOR(i,1,N)if(i!=centr&&tk[head[i]])inside[i]=true;
        seen.fill(0);
        c=0;
        dfs3(i);
        c=0;
        dfs4(centr);
        FOR(u,1,N)if(ans[u]==0)ans[u]=3;
        return ans;
    }
    return ans;
}
vector<int> find_split(int N, int a, int b, int c, vector<int> p, vector<int> q) {
    array<pii,3>D={pii{a,1},pii{b,2},pii{c,3}};
    sort(D.begin(),D.end());
    Graph g(N);
    g.input_from_vecs(p,q);
    auto v=_find_split(N,D[0].first,D[1].first,D[2].first,g);
    vector<int>A(N);
    if(v[1]==0)return A;
    FOR(i,1,N)A[i-1]=D[v[i]-1].second;
    return A;
}
