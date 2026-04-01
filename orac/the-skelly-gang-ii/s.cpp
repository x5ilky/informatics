#include <bits/stdc++.h>

using namespace std;

// im not smart :(
// ben had to teach me (i didn't know this existed !)

int main() {
    using pii=pair<int,int>;
    int id=1;
    int N,M;cin>>N>>M;
    vector<vector<pii>>adj(N+1);
    vector<pii> edges(M+1);
    for (int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        edges[i]={u,v};
    }
    vector<bool> vis(N+1,false);
    vector<int> tin(N+1,-1), low(N+1,-1);
    unordered_set<int> bridges;
    int timer=0;

    // thank you cp-algo
    function<void(int,int)> dfs=[&](int v, int p) {
        vis[v] = true;
        tin[v] = low[v] = timer++;
        bool parent_skipped = false;
        for (auto [to,id] : adj[v]) {
            if (to == p && !parent_skipped) {
                parent_skipped = true;
                continue;
            }
            if (vis[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v])
                    bridges.insert(id);
            }
        }
    };
    for (int i=1;i<=N;++i) {
        if (!vis[i])
            dfs(i,-1);
    }
    vis.assign(N+1,false);

    vector<int> cn(N+1,-1),cc(N+1,0);
    function<void(int,int)> dfs2=[&](int v, int c) {
        cc[c]++;
        vis[v]=true;
        cn[v]=c;
        for (auto [to,id] : adj[v]) {
            if (bridges.find(id) != bridges.end()) continue;
            if (vis[to]) continue;
            dfs2(to,c);
        }
    };
    id=1;
    for (int i=1;i<=N;++i) {
        if (!vis[i]) dfs2(i,id++);
    }
    vector<bool>bridgevis(N+1,false);
    vector<vector<int>>bridgeadj(N+1);
    for (auto b:bridges){
        bridgeadj[cn[edges[b].first]].push_back(cn[edges[b].second]);
        bridgeadj[cn[edges[b].second]].push_back(cn[edges[b].first]);
    }
    
    vector<int> sz(N+1,0);
    function<void(int,int)> dfs3=[&](int u, int p){
        sz[u]=cc[u];
        for (auto v:bridgeadj[u]){
            if(v==p)continue;
            dfs3(v,u);
            sz[u]+=sz[v];
        }
    };
    dfs3(1,-1);
    long long ans=-1e9;
    function<void(int,int)> dfs4=[&](int u, int p){
        ans=max(ans,(long long)sz[u]*(long long)(sz[1]-sz[u]));
        for (auto v:bridgeadj[u]){
            if(v==p)continue;
            dfs4(v,u);
        }
    };
    dfs4(1,-1);
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火丁ミミミミ丁ビせ山允洪李|
// |和労允せビミシㇵ一・・・ㇸ一ヘミ丁火山洪|
// |汎せ丁ヘ一ㇸ　ㇸㇸ　・ㇸ・　　一ヘ丁火允|
// |ビシㇸㇸ　ㇸ　一ヘシㇸ一ㇵシヘ一・ヘ丁せ|
// |ヘ・ㇸ・・一ヘ丁　ㇸ・　　・ㇵミビヘヘ丁|
// |一　　一一シ丁・ㇵㇸ・ヘシシシヘシビビヘ|
// |　ㇸㇵヘヘ丁　一一ㇸシビ火せ火せせビ丁ビ|
// |一シ丁火丁ミ一シ・一ヘヘシミ丁火山汎せ丁|
// |ミ丁丁丁丁ㇵ・ㇵ・　　　　・一ヘミビビビ|
// |ミミ丁丁丁　ㇵㇸㇵヘシシヘ一・・ㇵㇵㇵヘ|
// |火山せミ　ㇵシ丁火火せ火ビミヘ・ㇸㇵ・ㇸ|
// |洪せミㇸシビせ允汎洪洪汎山火丁ㇵ　ㇵㇸㇸ|
// |汎ビミシ火允洪允汎洪汎汎労汎せ丁ㇵ　ㇵ一|
// |汎火ビミせ汎汎汎允汎洪労労洪汎山ビシㇸㇸ|
// |労山山ミせ汎汎山洪李耗奏和洪山火丁ミミㇵ|
// |洪允山火允汎山汎李奏陽奏李允火ミㇵㇸ・・|
// |汎允允允允汎允労奏義陽和汎せミ一　一ㇵㇵ|
// |允允允汎汎允労奏義陽和洪せシ・一ミビビ丁|
// |山山洪允山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |允允汎汎汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (March 30th) 22:16:35
// end signature
