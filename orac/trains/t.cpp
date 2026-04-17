#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("trains.in","r",stdin);
    freopen("trains.out","w",stdout);
    int N;cin>>N;int S,T;cin>>S>>T;
    vector<int>D(N+1);for(int i=1;i<=N;i++)cin>>D[i];
    using pii=pair<int,int>;
    int M;cin>>M;
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    const int INF=1e9+7;
    vector<vector<int>>δ(N+1,vector<int>(N+1,INF));
    using state=pair<int,pii>;
    priority_queue<state,vector<state>,greater<state>>pq;
    pq.push({0,{S,S}}); δ[S][S]=0;
    while(!pq.empty()){
        auto [d,ε]=pq.top();pq.pop();
        auto [u,c]=ε;
        if(d>δ[u][c])continue;
        for(auto [v,w]:adj[u]){
            int dst=d+max(w-D[c],0);
            int nc=D[v]>D[c]?v:c;
            if(dst<δ[v][nc]){
                δ[v][nc]=dst;
                pq.push({dst,{v,nc}});
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=N;i++)ans=min(ans,δ[T][i]);
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火火火ビビビ火火せ山允洪李|
// |和労允せビミシヘヘㇵㇵㇵㇵヘシミ丁火山汎|
// |汎せ丁ヘ一ㇸ一　　・・・　　・一ヘミ火山|
// |ビシㇸㇸㇸ　　一ㇸ　　　ㇸ一ㇸㇸㇸㇵミせ|
// |ヘ・ㇸ・・ㇸㇵ一　ㇸ・　　・・ヘ一　ㇵ丁|
// |ㇵ　一・・ヘ・・ㇵ　　　　　　・ㇸシㇵㇸ|
// |・　・・ㇸㇸㇸミ火せ山火丁シヘ一　　ㇵヘ|
// |ㇵヘシシㇸヘシミビヘ一ㇸㇸㇸㇵシミㇵ　ㇵ|
// |丁火シㇸ・ㇸシヘㇸ　ㇸㇵㇵ一・・ヘ丁ㇵ　|
// |火シ・ㇸ一ミせ丁ㇵ　　ㇸㇵㇵヘㇸㇸヘシ・|
// |ヘ　・ㇵ丁ビシ一　　・ㇸㇸ・　ㇸ・ㇵㇵ・|
// |・　一丁ミㇵ・一ヘシミミミシㇵㇸ・シシ　|
// |　ㇵ丁丁ㇵㇸヘ丁火せ山山山せビミㇵㇸシㇵ|
// |ㇸシ火ミ一ㇵ丁せ允洪労労労洪汎山ビシㇸㇵ|
// |ㇵミせ丁一ヘビ山洪李耗奏和洪山火丁ミミㇵ|
// |シミ山丁一シ火汎李奏陽奏李允火ミㇵㇸ・・|
// |ミ火せシㇵビ允李奏義陽和汎せミ一　一ㇵㇵ|
// |丁山ミ一丁允李奏慶陽和洪火シ・一ミビビ丁|
// |山ビㇵ丁山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |せミヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 17th) 19:01:32
// end signature
