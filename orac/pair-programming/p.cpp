#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    using pii=pair<int,int>;
    vector<vector<pii>>g(2*N+1);
    vector<pii>E(N+1);
    for(int i=1;i<=N;i++){
        int u,v;cin>>u>>v;
        g[u].push_back({v+N,i});
        g[v+N].push_back({u,i});
    }
    vector<pii>ans;
    vector<short>seen(2*N+1);
    vector<short>used(N+1);
    function<bool(int,int)>dfs=[&](int u,int p){
        seen[u]=true;
        vector<int>edges;
        for(auto [v,e]:g[u]){
            if(e==p)continue;
            if(used[e])continue;
            used[e]=true;
            if(seen[v])edges.push_back(e);
            else if(dfs(v,e))edges.push_back(e);
        }
        if(edges.size()%2==0){
            for(int i=0;i<edges.size();i+=2)ans.push_back({edges[i],edges[i+1]});
            return true;
        } else {
            if(p!=-1)edges.push_back(p);
            for(int i=0;i+1<edges.size();i+=2)ans.push_back({edges[i],edges[i+1]});
            return false;
        }
    };
    for(int i=1;i<=2*N;i++)if(!seen[i])dfs(i,-1);
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans)cout<<u<<" "<<v<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎允せビ丁丁丁ビせ允洪和群慶|
// |慶奏李汎山火丁シㇵㇸ・・ㇸ一シ丁せ洪和奏|
// |和汎火ミㇵ一　一ㇵㇸ・・・ㇸ　ヘビ允汎洪|
// |山ミ一ㇸ　ㇵㇵㇵㇵㇸ　ㇸㇵ一ㇸ　シミビせ|
// |ミㇸ・ヘ丁ビ火せ火ビミㇵ　・　・・　ㇸヘ|
// |ㇵ・シビ山汎労李労労汎山丁シミ丁丁丁シㇵ|
// |一一丁山労和奏陽陽群奏和洪允山汎山山山せ|
// |・ヘ火洪和陽慶義奏和労洪汎一シシㇵ・ヘミ|
// |ㇸ丁汎和陽慶群和洪允ㇵヘシミ丁火山汎せシ|
// |丁允和義陽耗洪山　・ㇸㇸ　　ㇸヘ丁せ洪山|
// |允耗義奏労山一・　ㇸヘシミミシヘㇵビ允山|
// |李陽和汎火ヘ・シ丁火山允允允山火ミシミ丁|
// |李耗汎火　ㇸㇵㇸ丁山労耗耗耗李洪允ビヘ・|
// |汎和允丁・ㇵㇸヘ　シ火允洪洪洪労洪允山ミ|
// |火労允丁・ミシ　ㇵ一ㇸシ丁ビ丁ビ火ビ允汎|
// |ヘせ允ミ　シビ丁ㇵ　一ㇸ　・・ㇸシ火洪耗|
// |一ビせㇵ・シ火允ビシㇵ一ㇸ一ヘ丁せ洪耗陽|
// |一ビシ・ヘ一シ丁火せ火ビ火せ允洪和群慶覇|
// |ㇸ丁　シビ丁ミミミビせ允労李耗群慶覇覇覇|
// |　ㇵㇸヘ山汎允允汎洪李耗群義覇覇覇覇覇覇|
// +----------------------------------------+
// 2026 (June 18th) 16:22:11
// end signature

