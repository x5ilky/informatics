#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,K;cin>>N>>K;
    using pii=pair<int,int>;
    vector<set<pii>>adj(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].insert({v,w});
        adj[v].insert({u,w});
    }
    vector<bool>used(N+1,false);
    vector<int> ans;
    function<void(int,int)> solve=[&](int u,int depth){
        printf("solve depth %d\n",depth);
        vector<int>sz(N+1,0);
        function<void(int,int)> dfs=[&](int u,int p){
            for(auto [e,w]:adj[u]){
                if(used[e])continue;
                if(e==p)continue;;
                dfs(e,u);
                sz[u]+=sz[e]+w;
            }
        };
        dfs(u,-1);
        function<int(int,int)> cent=[&](int v,int p){
            printf("find centroid %d\n",v);
            for(auto [e,w]:adj[v]){
                if(used[e])continue;
                if(e==p)continue;
                if(sz[e]>sz[u]/2)return cent(e,v);
            }
            return v;
        };
        int centroid=cent(u,-1);
        fill(sz.begin(),sz.end(),0);
        dfs(centroid,-1);
        printf("centroid at %d depth %d\n",centroid,depth);
        int md=1ull<<60;
        for(auto [c,_]:adj[centroid]){
            if(used[c])continue;
            md=min(md,sz[c]);
        }
        function<void(int,int,int)> fill=[&](int u,int p,int d){
            printf("mark %d dist %d\n",u,d);
            used[u]=true;
            for(auto [e,w]:adj[u]){
                if(used[e])continue;
                if(e==p)continue;;
                if(d+w<=K)
                    fill(e,u,d+w);
                else solve(e,depth+1);
            }
        };
        printf("cent %d\n",centroid);
        fill(centroid,0,0);
        ans.push_back(centroid);
    };
    solve(1,0);
    cout<<ans.size()<<endl;
    for(auto e:ans)cout<<e<<" ";
    cout<<endl;
}
