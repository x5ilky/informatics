#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    vector<int>A(N+1);for(int i=1;i<=N;i++)cin>>A[i];
    vector<set<int>>g(N+1);
    for(int i=1;i<=M;i++){int u,v;cin>>u>>v;g[u].insert(v);g[v].insert(u);}
    using pii=pair<int,int>;
    set<pii>S;
    for(int i=1;i<=N;i++)S.insert({A[i]-g[i].size(),i});
    vector<pii>ans;
    while(S.size()){
        auto [c,u]=*S.rbegin();S.erase(prev(S.end()));
        if(c<0)return cout<<"IMPOSSIBLE"<<endl,0;
        for(auto v:g[u]){
            auto [c2,_]=*S.find({A[v]-g[v].size(),v});
            S.erase({c2,v});
            g[v].erase(u);
            S.insert({c2+1,v});
            ans.push_back({u,v});
        }
    }
    for(auto [u,v]:ans)printf("%d %d\n",u,v);
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労洪允せ火ビビビせ山汎李奏群群|
// |慶奏李汎山火丁シㇵㇸㇸㇸ一ヘミ火允労労労|
// |和汎せミㇵ一　ㇸㇵ一ㇸ・　　ㇸシ火火火せ|
// |山ミ一一　ヘ・ㇸㇵヘㇵヘシミヘㇵ一一ㇵヘ|
// |ミㇸ一・一・シ一　ㇸㇸ　　ㇸシビミㇸㇸ　|
// |　・ㇸㇵ　・　・ヘ一ㇸ・　・ㇵミ丁火ヘ　|
// |丁ミシヘㇸヘ丁火火火丁シヘ一・　一ミせ丁|
// |汎汎允山火山允汎汎汎允山ビシㇸ　　・ヘ丁|
// |耗耗李汎山洪李耗李洪允せ火ビ丁ヘ　・　ㇸ|
// |和汎せ洪和奏李汎せ丁シㇵ一ㇸㇸ一一・　一|
// |山允李群和汎火ミ一　一ㇵヘヘヘㇵヘㇵ一・|
// |允和耗洪山丁一・ヘ丁火せ山山せせせせビミ|
// |洪奏労せミ一ㇵㇸ丁山労李和李労洪山山汎允|
// |汎耗汎ビㇵ・ㇸヘ　シ火允洪洪洪労洪允山ビ|
// |せ李汎ビ一一シ　ヘ一ㇸシ丁ビ丁火火ビ允汎|
// |ビ洪汎丁ㇸヘ丁丁一　一ㇸ　・・ㇸシ火洪耗|
// |丁汎山ヘ・ヘ火山ビシㇵㇸㇸ一ヘ丁せ洪耗陽|
// |火允ミ　ヘ一シビ火せ火ビビせ山洪和群慶陽|
// |せビ・シ丁丁ミミミビせ允労李耗群慶覇覇奏|
// |火シ・ㇵせ汎允允汎洪李耗群義覇覇覇覇義和|
// +----------------------------------------+
// 2026 (June 21st) 16:42:39
// end signature
