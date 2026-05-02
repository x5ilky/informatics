#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
signed main() {
    int N,M;cin>>N>>M;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    const int INF=1ull<<60;
    vector<pii>A(N+1,{INF,0}),B(N+1,{INF,0}),C(N+1,{INF,0});
    auto solve=[&](vector<pii>&D,int s){
        priority_queue<pii,vector<pii>,greater<pii>>pq;D[s]={0,1};pq.push({0,s});
        while(!pq.empty()){
            auto [d,u]=pq.top();pq.pop();
            if(d!=D[u].first)continue;
            for(auto [v,w]:g[u]){
                if(d+w<D[v].first){
                    D[v]={d+w,D[u].second};
                    pq.push({D[v].first,v});
                }else if(d+w==D[v].first){
                    D[v].second+=D[u].second;
                    D[v].second%=MOD;
                }
            }
        }
    };
    solve(A,1);
    solve(B,2);
    solve(C,N);
    int mx=0,cnt=0;
    for(int i=3;i<=N;i++){
        if(A[i].first==B[i].first&&A[i].first+C[i].first==A[N].first)mx=max(mx,C[i].first);
    }
    for(int i=3;i<=N;i++){
        if(A[i].first==B[i].first&&A[i].first+C[i].first==A[N].first&&C[i].first==mx){
            cnt+=A[i].second*B[i].second%MOD*C[i].second%MOD;
            cnt%=MOD;
        }
    }
    cout<<mx<<endl;
    cout<<(mx==0?A[N].second*B[N].second%MOD:cnt)<<endl;
}

// begin signature
// +----------------------------------------+
// |群耗和和和李労汎山せ火火ビビ火せ允洪和群|
// |洪允山せせ火ビミㇵ一ㇸ・・・一ヘ丁せ汎和|
// |ミヘㇵㇵヘㇵ　一ㇵㇵシミミシㇵ　一ミ山労|
// |ㇸ一ㇵㇵ一ヘㇸシ丁シヘヘミビビシ・ㇵビ汎|
// |ビせせせ火丁丁一ヘミビビビミシ火ミㇸㇵ丁|
// |洪李和和李洪允火シㇵ一ㇸㇵシビビ丁ビ一　|
// |耗群義義群労山　丁允労李允汎せミ　ビせビ|
// |陽覇覇慶耗汎・シ山労奏労和奏和允丁・シせ|
// |覇覇覇陽労ミ・ビ洪奏奏和義覇奏李せㇵㇵせ|
// |覇覇奏労ㇵㇸシ允耗群耗慶慶群耗労火ㇸシせ|
// |義和ㇵ・ヘ一せ李耗和義奏李汎山せシㇸ火ミ|
// |和ㇵㇵㇵㇸシ山和耗和李汎せ火丁丁・ミ火一|
// |洪ミシ・ヘ一火洪奏労山丁ヘㇸ　　・ビ丁　|
// |洪・丁ヘ一ㇵ一ビ允允丁ㇵ・ㇵミ丁ミビビシ|
// |李ㇵ　ミヘㇸシ　ヘビミ　ヘビ山允火ビビビ|
// |和ㇸヘ　シシ・ミㇵ　ㇵㇸ丁允允ビシせシ　|
// |洪一ビヘ・シㇵ・シミㇵシ山汎丁ビビヘ　シ|
// |　ヘビビシ一シ一ㇸミ丁山汎丁ミㇵ　ㇵ丁允|
// |・丁丁允せビㇵㇵせ洪允洪丁　一ヘビ山労汎|
// |・丁火労洪丁　ミ汎労汎山ㇵㇵせ允労耗奏汎|
// +----------------------------------------+
// 2026 (May 2nd) 19:04:47
// end signature

