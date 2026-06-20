#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,M,Y;cin>>N>>M>>Y;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+2);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int>X(N+1);
    for(int i=1;i<=N;i++)cin>>X[i];
    for(int i=1;i<=N;i++){
        g[i].push_back({N+1,X[i]+Y});
        g[N+1].push_back({i,X[i]});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;pq.push({0,1});
    vector<int>dist(N+2,1ull<<60);
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:g[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }
    for(int i=2;i<=N;i++)cout<<dist[i]<<" ";cout<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇覇慶陽耗和労汎山山山山汎労和群慶覇覇|
// |覇覇群李汎山火丁ヘㇵ一一ヘミ火允李群覇覇|
// |群李允ビヘㇵ　一ヘㇵㇵヘ一　ㇵビ允和義覇|
// |汎ビㇵ一・ヘ・ㇸヘシヘヘシヘヘシ火労群覇|
// |ビㇸ一　ㇵㇸミシヘシミシㇵㇵ丁允允せ李義|
// |シ・一ㇸ　ミシビ山允汎汎允せ丁ヘ火允洪李|
// |ミ・一・・丁丁允李ㇸ一　労李労允ビ丁山山|
// |丁・ㇸㇵㇸシミ洪耗一丁火山山せビ李汎火允|
// |ㇸヘ火シㇵ労和一ミ丁火允労耗耗和労耗労せ|
// |ミ允ミ洪和・・ㇸ・　一ミせ洪汎山山山允允|
// |汎丁耗汎シビ火せシ　　一ミ丁ヘ一一ヘミせ|
// |山和山せ汎丁ビヘ　一ヘシシヘ一　ヘ一　シ|
// |奏汎山労火丁ㇸ一丁せ火丁ミミ丁丁ㇵㇸミ・|
// |耗允汎労ビヘㇸ丁せミ一　ㇸ一・・ヘ丁ㇸヘ|
// |和洪允李せㇵㇵ火ビ一一ミ火せせビシㇸㇵシ|
// |汎洪山李火ㇸシ允シ・丁山労和労せミ一ㇸ・|
// |和汎山汎ミㇸ火丁　ミ汎和陽李せㇵ・シミミ|
// |李火洪ビ　一ミ　丁洪奏義労火ㇸヘせ汎洪允|
// |允火火・丁火ㇸミ洪群義李火・ミ汎耗陽奏洪|
// |せビミ一せシ一せ耗覇奏允ヘㇵ山耗覇覇陽労|
// +----------------------------------------+
// 2026 (June 20th) 22:52:09
// end signature
