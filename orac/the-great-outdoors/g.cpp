#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
const int INF=1ull<<60;
signed main() {
    int N,M,A,B,K;cin>>N>>M>>A>>B>>K;
    vector<int>C(N+1),H(N+1);
    vector<set<pii>>company(N+1);
    for(int i=1;i<=N;i++)cin>>C[i]>>H[i];
    for(int i=1;i<=N;i++)company[C[i]].insert({H[i],i});
    for(int i=1;i<=N;i++)company[i].insert({INF,0});
    vector<vector<int>>g(N+1);
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;pq.push({0,1});
    vector<int>D(N+1,INF);D[1]=0;
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>D[u])continue;
        int c=C[u];
        for(auto v:g[u])
            if(d+A<D[v]){
                D[v]=d+A;
                pq.push({d+A,v});
            }
        for(auto it=company[c].lower_bound({H[u]-K,0});it->first<=H[u]+K;it=company[c].erase(it)){
            if(d+B<D[it->second]){
                D[it->second]=d+B;
                pq.push({d+B,it->second});
            }
        }
    }
    cout<<(D[N]>=INF?-1:D[N])<<endl;
}

// begin signature
// +----------------------------------------+
// |山せビビ丁ビ火せ山せせ火ビビ火せ允洪和耗|
// |シㇵㇸ・・ㇸㇵシシヘㇵ一一一ㇵシ丁せ汎允|
// |一ヘシシヘㇵ・　ㇸ一ㇵヘヘㇵㇸ　ㇵ丁丁ミ|
// |火せ山山せビミㇵミミシシミビミㇵ　・　　|
// |労李和労山丁シヘ・　・・　一ミビヘㇸ　一|
// |奏陽和汎ビヘヘ一ミ丁ミㇵミヘ　ㇵ丁ミㇸㇸ|
// |義陽李允丁シ允李ミせ允汎允せビヘ　シビ一|
// |覇陽李山丁労ㇸㇵ火汎洪洪洪李洪せシ　シビ|
// |慶奏洪火耗シ　ミせ火ビビ火山山火ビ一ㇵ火|
// |群労汎李一ㇸヘミㇵㇸㇸ一ヘ丁ヘ一ㇸㇸヘ火|
// |労和ヘ・ㇵ一一・ㇵヘヘ一　　一ヘヘㇵビシ|
// |和シ　ㇵㇸ　ヘシ一ㇵヘ丁ヘ丁火せせビビㇸ|
// |労ヘㇸㇸㇵ一ヘシビ火せ火ビ允労李労汎せシ|
// |労ミ　一一一ㇵビ允洪李労允洪李洪允允允山|
// |和火ㇵ一ㇵㇸシビ汎和奏陽耗洪汎せビミビミ|
// |耗允ミ　シㇵㇸ丁汎耗慶慶奏洪山ミㇵビミ・|
// |和汎丁・ㇸシ　丁允和陽陽李山ミシビシ・ㇵ|
// |洪山ミ　ヘㇸㇸ丁允労李労山ビミヘㇸㇸシせ|
// |山せヘ・ミㇵㇸミ火山せビミ・　一ミ火允允|
// |せミシ　ヘシ　ミヘシヘㇸㇵ一丁火允労和允|
// +----------------------------------------+
// 2026 (June 20th) 18:00:03
// end signature

