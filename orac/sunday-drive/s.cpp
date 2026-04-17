#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);
    int S;cin>>S;vector<int>C(S+1);
    for(int i=1;i<=S;i++)cin>>C[i];
    using pii=pair<int,int>;
    int N,H,M;cin>>N>>H>>M;
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=M;i++){
        int u,v,m;cin>>u>>v>>m;
        adj[u].push_back({v,m});
        adj[v].push_back({u,m});
    }
    const int INF=1e9+7;
    vector<vector<int>>δ(N+1,vector<int>(S+1,INF));
    using state=pair<int,pii>;
    priority_queue<state,vector<state>,greater<state>>pq;
    pq.push({0,{H,0}});
    while(!pq.empty()){
        auto [d,ε]=pq.top(); pq.pop();
        auto [u,r]=ε;
        if(r>=S)continue;
        if(d>δ[u][r])continue;
        for(auto [v,m]:adj[u]){
            int nd=d+(m!=C[r+1]);
            if(δ[v][r+1]<=nd)continue;
            δ[v][r+1]=nd;
            pq.push({nd,{v,r+1}});
        }
    }
    cout<<δ[H][S]<<endl;
}

// begin signature
// +----------------------------------------+
// |允せ火ビビビ火山允允山山山允允允允汎労和|
// |シㇵㇸ・ㇸ一ㇵシミシシシシミミミ丁ビせ允|
// |一ヘシシヘㇵ・・　・ㇸ・　　　　・ㇵミ火|
// |火山せミ一　・ㇵㇸ　　・一ㇵ一・ㇸㇸㇸシ|
// |洪火シ・　ㇵㇵ一・ㇸㇸ　　　一ヘヘ　　一|
// |允丁一一ㇸ一・・ヘ　・　　・一・　ㇸ・・|
// |允丁ㇸ　　一ㇸミせ允允山丁ミヘ一　ㇵヘ一|
// |允丁ミミㇵミ洪労汎ミヘㇵㇵヘミビ丁ㇵ　シ|
// |せせビㇵ山洪允シヘ・ㇸ一ㇵ一　一ミビヘ　|
// |汎ビミ労允丁允ビㇵ・シミ丁丁シ・ㇵビミ・|
// |丁允汎ㇵ火洪洪せヘ・・　ㇵ丁丁一一ビミ一|
// |洪允ㇵ火洪李労山丁ミミヘ　ヘシヘㇸビミㇵ|
// |汎・シせ洪山せ山ミミ丁シヘ　シ一ㇸミビヘ|
// |山・ㇵビ汎ビシミせ允汎允火シ　一ヘシビせ|
// |せ・　ミ山せシ丁允李耗耗李允ミミ丁シシミ|
// |火ㇵ一ㇵ丁汎ビ丁汎耗義義奏労せミ一　・・|
// |ビㇸㇵㇵビ允允せ汎奏慶陽李山ミ・ㇵミビ丁|
// |ミ　ㇸヘビ允李労洪耗奏和允ミ　シせ汎洪山|
// |ヘㇸ　ミビ允汎火允汎汎せミ　ミ允李奏和汎|
// |シ・　シせせ丁シ丁ビミヘㇵ一火労群慶耗允|
// +----------------------------------------+
// 2026 (April 17th) 17:47:37
// end signature


