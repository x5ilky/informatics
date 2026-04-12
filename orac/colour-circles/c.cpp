#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("circles.in","r",stdin);
    freopen("circles.out","w",stdout);
    int N,R,S,T,M;cin>>N>>R>>S>>T>>M;
    using pii=pair<int,int>;
    vector<int>C(N+1);
    for(int i=1;i<=N;i++)cin>>C[i];
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=M;i++){
        int u,v,c;cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<vector<int>>dist(N+1,vector<int>(N+1,1e9)); queue<pii>q; 
    q.push({R,S});q.push({S,R});dist[R][S]=dist[S][R]=0;
    while(!q.empty()){
        auto [a,b]=q.front();
        q.pop();
        for(auto [v,c]:adj[a]){
            if(v==a||v==b)continue;
            if(c==C[b]&&dist[a][b]+1<dist[v][b]){
                dist[v][b]=dist[a][b]+1;
                q.push({v,b});
            }
        }
        for(auto [v,c]:adj[b]){
            if(v==a||v==b)continue;
            if(c==C[a]&&dist[a][b]+1<dist[a][v]){
                dist[a][v]=dist[a][b]+1;
                q.push({a,v});
            }
        }
    }
    int d=1e9;
    for(int i=1;i<=N;i++){
        d=min(d,dist[i][T]);
        d=min(d,dist[T][i]);
    }
    if(d>=1e9)d=0;
    cout<<d<<endl;
}

// begin signature
// +----------------------------------------+
// |允せ火ビビ火せ山山せ火火せ山山せ山山允洪|
// |ミヘㇵ一一ㇵヘミシヘㇵヘヘシシヘシミビせ|
// |・一一・　・・　・一一ㇸ・・・　　ㇸㇵミ|
// |・ㇸ一ㇸヘヘシシヘㇸㇸ一ㇵㇵシシシシㇵㇵ|
// |ヘ・　　・・　・　ㇸ・　・・ヘビ山山火丁|
// |　一ヘミ丁丁丁シヘ・・一　ㇵミ丁ミ山労汎|
// |一ミビ山允汎汎允せビシㇸ・　ㇸヘビ山火汎|
// |シ火允労李耗耗和李洪山ビヘ　シビ丁丁丁火|
// |火汎李奏陽群耗李洪允山山ビㇵㇸシ・・ㇸㇵ|
// |洪耗陽陽耗労允汎李和耗和汎火ヘミㇵ・ㇵ・|
// |群義奏労汎耗義覇覇慶慶義耗洪火ヘヘ　シㇵ|
// |陽耗洪奏慶慶陽奏奏耗奏和労汎せミㇸ・シミ|
// |奏労李慶陽奏李労洪汎洪汎せビ丁シㇵ・ㇵ火|
// |耗洪労耗奏李汎せ火ビビ火ミㇵ一ㇵㇵㇸㇸミ|
// |奏洪山労耗洪せ丁ヘ一ㇸ一ㇵシ丁火丁ミシヘ|
// |和洪火汎和允ビㇵ　　一ㇸヘビせミ一　　　|
// |李汎丁汎洪火ヘ　シㇵㇸㇵビ山ミㇸ一シミミ|
// |洪火せ労せヘ・ヘ　ㇵヘ火山ミ　ヘ火山允せ|
// |山ビ汎せシ・ㇵㇸ丁せせ允ミ　シ山労和李允|
// |ビせ汎ビㇸヘ　シ山洪汎火ㇵ一火洪奏陽李山|
// +----------------------------------------+
// 2026 (April 12th) 16:07:48
// end signature

