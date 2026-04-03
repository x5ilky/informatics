#include <bits/stdc++.h>

using namespace std;

int main() {
    using pii=pair<int,int>;
    int N;cin>>N;
    vector<array<int,3>>W;
    vector<vector<pii>>W2(N+1);
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=N-1;i++){
        for (int j=i+1;j<=N;j++){
            int w;cin>>w;
            W.push_back({w,i,j});
            W2[i].push_back({j,w});
        }
    }
    sort(W.begin(),W.end());
    
    vector<int>HEAD(N+1),sz(N+1,1);
    function<int(int)> head=[&](int node) {
        if(HEAD[node]==node)return node;
        return HEAD[node]=head(HEAD[node]);
    };

    function<void(int,int)> join=[&](int u, int v) {
        u=head(u),v=head(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        HEAD[v]=u;
        sz[u]+=sz[v];
    };
    for (int i=1;i<=N;i++)HEAD[i]=i;

    for (auto [w,u,v]:W){
        if(head(u)==head(v))continue;
        join(u,v);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=1;i<=N;i++){
        const int INF=1e9+7;
        vector<int>dist(N+1,INF);
        function<void(int)> dfs=[&](int u) {
            for (auto [v,w]:adj[u]){
                if(dist[u]+w<dist[v]) {
                    dist[v]=dist[u]+w; dfs(v);
                }
            }
        };
        dist[i]=0;
        dfs(i);
        for (auto [v,w]:W2[i]){
            if(dist[v]!=w){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎允せ火ビビビ火山汎労耗陽覇|
// |義奏李汎山火丁ミヘ一ㇸㇸ一ㇵミビ山洪耗陽|
// |李汎火ミㇵ一・ㇸㇵ一ㇸㇸ一・ㇸヘビ允李群|
// |山ミ一一・一一　一一一ㇵ一　ㇸ・シせ洪奏|
// |ミㇸ一　ヘ　　ㇸㇵヘㇵ一・・ㇵ・・ミ山李|
// |ヘ・ㇵㇸ一ㇸシ丁ヘ　ㇵミ丁シ・　・　ミ山|
// |一ㇸ　ㇸㇸヘㇸㇵㇵㇸミせ允汎允山ミ・・シ|
// |火火丁ヘ一ㇵ・ヘㇸㇵ火汎李耗耗和汎火シ　|
// |洪洪火ㇵヘシ・ヘ・丁允李耗李洪允山せ丁ヘ|
// |李山ヘビビ・シ　ミ允洪汎洪労労洪汎允ビㇵ|
// |允シ允せㇵ一一ㇵせ労和奏群群奏和労洪汎シ|
// |ビ丁汎ビㇸヘ・シせ労奏慶覇慶慶陽耗洪火ビ|
// |　ミ允せヘㇸㇵㇸ丁山労耗奏耗奏群耗労允丁|
// |一・丁允火ㇵㇸヘ　シ火允汎汎汎洪洪允允允|
// |・一　ミ山せシ　ㇵ一ㇸヘ丁ビ丁ビ火ビ允和|
// |ㇵビㇵ　シ火山丁ㇵ　一ㇸ　・・ㇸシ火洪耗|
// |丁允ビヘ・シ火允ビシㇵ一一ㇵシ丁せ洪耗奏|
// |山汎山丁ヘ一シ丁火せ火ビ火ビ允洪和群陽李|
// |洪李洪山火丁ミミミビ火允允ミ允和義群李山|
// |允和耗李洪汎允允汎洪李和山丁汎耗群義和汎|
// +----------------------------------------+
// 2026 (April 3rd) 17:31:41
// end signature
