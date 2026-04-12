#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    using pii=pair<int,int>;
    vector<vector<pii>>adj(N+1);
    for(int i=1;i<=M;i++){
        int u,v,k;cin>>u>>v>>k;
        adj[u].push_back({v,k});
        adj[v].push_back({u,k});
    }
    int K;cin>>K;
    vector<int>T(K+1);
    for(int i=1;i<=K;i++)cin>>T[i];
    set<int>ans;
    set<pii>q;
    vector<vector<int>>seen(N+1,vector<int>(K+1,false));
    for(int i=1;i<=N;i++){
        q.insert({i,0});
        seen[i][0]=true;
    }
    while(!q.empty()){
        auto [u,d]=*q.begin();
        q.erase(q.begin());
        if(d==K){
            ans.insert(u);
            continue;
        }
        for(auto [v,k]:adj[u]){
            if(k==T[d+1]&&!seen[v][d+1]){
                seen[v][d+1]=true;
                q.insert({v,d+1});
            }
        }
    }
    if(ans.empty())cout<<"Impossible\n";
    for(auto c:ans)cout<<c<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪允せビビビビ火山汎労耗陽覇|
// |慶奏李汎山火丁シㇵㇸ・・一ㇵミ火允労耗義|
// |和汎火ミㇵ一　一ㇵㇸㇸㇸ・・ㇸシ火汎和陽|
// |山ミ一一　ㇵ　ㇸヘㇵㇵヘヘシシㇵミ山労和|
// |ミㇸ一　一・一一一一一ㇸ　ㇸヘ丁丁丁せ允|
// |一・一ヘシ丁ビミヘㇸ　　　一一ㇸ・一ㇵシ|
// |　ヘ丁火山火シㇵㇵ・　・　・　ㇸ　一ㇵㇸ|
// |ㇵビ山洪山丁一ヘㇸㇸヘシミシヘ一　ㇸ　ㇵ|
// |ビ允李允丁一・シ・・ㇸㇸㇸ・　ミミ一ㇸ・|
// |洪和允丁ㇸ・シ　・ㇸㇸ　　　　　一一・・|
// |和允丁　・一一一ヘミミミミ丁丁ミヘ一　一|
// |汎ビ・ㇸ　ヘ・シ山允允允允汎允山せ丁ヘ　|
// |山シㇵ・ㇵㇸㇵㇸ丁山労耗耗耗耗和労汎火シ|
// |允丁ㇸㇵビㇵㇸヘ　シ火允洪洪洪労洪允允允|
// |汎丁ㇸㇵ火せシ　ㇵ一ㇸシ丁ビ丁ビ火ビ允和|
// |汎丁・　シせ山丁一　一ㇸ　・・ㇸシ火洪耗|
// |山シ・ヘ・シ火山ビシㇵㇸㇸ一ヘ丁せ洪耗陽|
// |丁　ミビヘ一シビ火せ火ビ火せ山洪和群慶覇|
// |ㇸヘ山山火丁ミミミビせ允労李耗群慶覇覇覇|
// |・丁汎李洪汎允允汎洪李耗群義覇覇覇覇覇慶|
// +----------------------------------------+
// 2026 (April 12th) 18:12:39
// end signature


