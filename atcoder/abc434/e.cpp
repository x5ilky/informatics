#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    using pii=pair<int,int>;
    int N;cin>>N;
    map<int,vector<pii>> adj{};
    map<int,bool> vis;
    vector<bool>visedge(N*2+1);
    for (int i=1;i<=N;i++){
        int x,r;cin>>x>>r;
        adj[x+r].push_back({x-r,i});
        adj[x-r].push_back({x+r,i});
        visedge[i]=false;
    }

    function<pii(int)> dfs=[&](int node){
        vis[node]=true;
        bool tree=true;
        int sz=1;
        for (auto [e,i]:adj[node]) {
            if(visedge[i]) continue;
            visedge[i]=true;
            if(vis[e]) {
                tree=false;
                continue;
            }
            auto res=dfs(e);
            tree&=res.second;
            sz+=res.first;
        }
        return pii{sz,tree};
    };

    int ans=0;
    for (auto &[i, _] : adj){
        if(vis[i])continue;
        auto[sz,tree]=dfs(i);
        ans+=sz-tree;
    }
    cout<<ans<<endl;
}
