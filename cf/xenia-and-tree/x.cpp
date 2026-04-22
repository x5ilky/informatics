#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Q;cin>>N>>Q;
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
    }
    vector<int>sz(N+1);vector<bool>gone(N);
    vector<vector<int>>cen(N+1);
    function<void(int,int)>fsz=[&](int u,int p){
        sz[u]=1; for(auto v:g[u])if(!gone[v]&&v!=p)fsz(v,u),sz[u]+=sz[v];
    };
    function<int(int,int,int)>fcentr=[&](int u,int s,int p){
        for(auto v:g[u]){
            if(v==p||gone[v])continue;
            if(sz[v]*2>s)return fcentr(v,s,u);
        }
        return u;
    };
    function<void(int,int,int)>scentr=[&](int u,int p,int c){
        cen[u].push_back(c);
        for(auto e:g[u])if(e!=p)scentr(e,u,c);
    };
    function<void(int)>build=[&](int u){
        fsz(u,-1);
        int cent=fcentr(u,sz[u],-1);
        printf("centroid at %d\n",cent);
        scentr(cent,-1,cent);
        gone[cent]=true;
        for(auto v:g[cent]){
            if(gone[v])continue;
            build(v);
        }
    };
    build(1);
}
