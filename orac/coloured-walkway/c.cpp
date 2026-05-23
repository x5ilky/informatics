#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;
using mint=atcoder::modint1000000007;
int main() {
    int N,C;cin>>N>>C;
    vector<int>c(N+1);for(int i=1;i<=N;i++)cin>>c[i];
    int P;cin>>P;
    vector<set<int>>g(C+1);vector<set<int>>prop(C+1);
    for(int i=1;i<=P;i++){
        int u,v;cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    const int B=310;
    for(int i=1;i<=C;i++)
        if(g[i].size()>B)for(auto v:g[i])prop[v].insert(i);
    vector<mint>dp(C+1),lz(C+1);
    dp[c[1]]=1;
    for(auto v:prop[c[1]])lz[v]+=1;
    for(int i=2;i<=N-1;i++){
        int cc=c[i];mint d=0;
        if(g[cc].size()<=B)for(auto v:g[cc])d+=dp[v];
        else d=lz[cc];
        for(auto v:prop[cc])lz[v]+=d;
        dp[cc]+=d;
    }
    int cc=c[N]; mint ans=0;
    if(g[cc].size()<=B)for(auto v:g[cc])ans+=dp[v];
    else ans=lz[cc];
    cout<<ans.val()<<endl;
}

// begin signature
// +----------------------------------------+
// |ㇸㇸㇸ一一一ㇵシミミミミシㇵㇵㇵㇵヘシミ|
// |一一一ㇸㇸ・　・一ㇸㇸㇸ　・・・・　ㇸㇵ|
// |丁丁ミミミシㇵㇸㇸㇸㇸ　　　　ㇸ・ㇸㇸ　|
// |山山せせせビシ　シㇵㇵㇵヘミミ一　・ㇸ　|
// |労洪汎山ビヘシ一　　・　　ㇸヘミシㇸ・　|
// |耗労允火ミミ一　一・ㇸㇵヘヘㇵヘシ丁ヘ　|
// |耗洪山ビ・シㇸㇸ一　ㇵミビビビ丁ミミミシ|
// |和洪せ丁シシ・一ㇸ　　　　火山允ビシㇸㇸ|
// |李允火シヘㇵ　ㇵㇸ一一ㇵㇵㇵ一　火丁ヘㇸ|
// |汎火シㇸ　ㇸㇵㇸㇸㇸ　ㇸ一ヘヘㇵ・シㇵ一|
// |火シ　　ㇸㇸㇸㇸㇸ・ㇸ一ㇵヘヘシ一ミㇵ一|
// |丁　ㇸ一　ㇵ　　一シミビビミシヘ一・シシ|
// |　一ㇸ　ㇸ一一ㇵミ丁丁ミヘㇸ・一ㇸ　　一|
// |ビ・・ㇵシ丁丁ミミシミ丁ミヘㇸㇸㇵㇵㇵㇸ|
// |せ・ㇸシビせ山山せビせ山山火丁シシヘㇵヘ|
// |山　ㇵ丁せ汎労労洪允汎洪洪せ丁ヘㇸ　・　|
// |せ・シ火汎李耗奏耗労李労允ビヘ・ㇸヘシシ|
// |ビヘビ允李奏義義奏李李允ビヘ　ㇵ丁火火ビ|
// |一丁山労奏義覇群和和汎火ヘ　ヘビ允洪允火|
// |ㇵビ允労耗群群耗労労山丁一ㇸミ山労李汎ビ|
// +----------------------------------------+
// 2026 (May 22nd) 19:26:44
// end signature












