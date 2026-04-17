#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M,T;cin>>N>>M>>T;
    vector<vector<int>>adj(N+1);
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    using pii=pair<int,int>;
    vector<int>δ(N+1,-1);
    priority_queue<pii,vector<pii>,less<pii>>pq;
    for(int i=1;i<=T;i++){
        int l,k;cin>>l>>k;
        δ[l]=0;
        pq.push({k,l});
    }
    while(!pq.empty()){
        auto [p,u]=pq.top();
        pq.pop();
        if(p<δ[u]||p==0)continue;
        for(auto v:adj[u]){
            if(p-1<=δ[v])continue;
            δ[v]=p-1;
            pq.push({p-1,v});
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++)ans+=δ[i]>=0;
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火ビ丁ミミ丁ビ火せ允労和奏|
// |和労允せビミシヘ一ㇸㇸㇸ一ㇵシ丁火允労和|
// |汎せ丁ヘ一ㇸ　・一ㇸㇸㇸㇸ　ㇸヘ丁せ汎和|
// |ビシㇸㇸ　一　・一一一一一一一一シ火允李|
// |ヘ・ㇸ・ㇸ・ㇵㇸ　・・　　・ㇵミ丁ミせ洪|
// |・　　ㇸ・一一・ㇵ　一ヘシシヘ一シ火火せ|
// |一ヘシシヘ一一丁せ山一ヘヘ一火ビミヘビせ|
// |ミビ火せ火丁允ㇵ・一ミ火せ山山ビシ丁ヘヘ|
// |せ允汎山せ汎　ㇵ・ㇵㇵヘミ丁ビ丁丁丁丁シ|
// |労洪せ洪一　ㇵ・ㇸ・　　一一ㇵ一ㇸㇸㇵヘ|
// |洪山允ㇸ一ㇸㇸ一　・ㇸㇸㇸ・　・ㇵ一　ㇸ|
// |山山ㇸ一・ㇵ　一ヘミ丁丁ミシヘㇸ　ㇵヘ・|
// |允ヘ　ヘ・ㇸヘ丁火せ山山山せビミㇵ・一ㇵ|
// |山シ・ㇵ　ヘ丁せ允洪労李労労汎山火ミ一・|
// |允ビㇵㇸ・シビ允洪和耗奏和洪山火丁ミシヘ|
// |洪せシ　ㇸミせ汎李奏陽奏李允火ミㇵㇸ・・|
// |洪せシ　ㇵビ允李奏義群和汎火ミㇸ・ㇵヘㇵ|
// |汎ビㇵ一丁允李奏慶陽和汎火シ・一ミビ火丁|
// |山丁一丁山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |ビ丁ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (April 17th) 17:56:01
// end signature
