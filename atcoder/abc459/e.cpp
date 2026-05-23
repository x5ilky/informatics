#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint=atcoder::modint998244353;
#define int long long
signed main() {
    int N;cin>>N;
    vector<vector<int>>g(N+1);
    vector<int>C(N+1),D(N+1);
    for(int i=2;i<=N;i++){
        int v;cin>>v;g[v].push_back(i);
    }
    for(int i=1;i<=N;i++)cin>>C[i];
    for(int i=1;i<=N;i++)cin>>D[i];
    vector<mint>fac(1e6+1,1);for(int i=1;i<=1e6;i++)fac[i]=fac[i-1]*i;
    auto choose=[&](int n,int k)->mint{
        if(k>n||k<0)return 0;
        if(n==k||k==0)return 1;
        mint a=mint(fac[k]).inv();
        for(int i=n-k+1;i<=n;i++)a*=i;
        return a;
    };
    vector<mint>dp(N+1,1);
    function<void(int)>dfs=[&](int u){
        for(auto v:g[u]){
            dfs(v);C[u]+=C[v],dp[u]*=dp[v];
        }
        dp[u]*=choose(C[u],D[u]);C[u]-=D[u];
    };
    dfs(1);cout<<dp[1].val()<<endl;;
}

// begin signature
// +----------------------------------------+
// |汎山せ火火火せ允汎山せせせ山汎労耗群覇覇|
// |ミㇵ一ㇸㇸ一ヘミシㇵ一一ㇵシ丁せ汎和群覇|
// |一ヘシシシㇵ・・ㇵㇵ一一一　一ミせ洪耗慶|
// |せ允允允山火丁ㇵ・ヘヘヘㇵㇵㇵㇸ丁允和陽|
// |和耗奏労せシㇸㇸ・・ㇸ・　ㇵヘㇵ一ビ汎耗|
// |陽義和允丁ㇸ一　ヘ・一シミミミ丁ミ一丁汎|
// |覇慶和允ミ　ㇵ一ヘ・ミ丁ビせ允汎洪山丁ミ|
// |覇慶和山シ・ㇸヘ一・　　　ㇸヘ丁せ汎洪火|
// |覇陽労火ㇸ　　ミヘミ丁丁丁シ一　ㇵビ允洪|
// |義和せビシㇸシ火山汎洪洪汎山ビヘ　ヘ火洪|
// |耗汎山ヘシせ洪和奏群群奏耗労允ビ一一ビ洪|
// |李允ミ丁允和群奏和和耗群義奏労山シ　丁火|
// |和山シ山李奏李労山山允洪耗洪せミヘㇵ・一|
// |耗汎丁允和和允李洪洪火火山允丁一シミ丁シ|
// |義和山せ李和山洪李耗洪洪労汎ミ丁ビミミミ|
// |覇群洪火労和山汎奏労耗和奏汎ミ丁一　ㇸ・|
// |群陽労せ李李火洪耗奏覇義耗允丁・ㇵ丁火ビ|
// |李耗労汎奏汎せ李李陽慶奏汎丁　ミ山労労汎|
// |慶陽労労和山允耗労耗和洪丁　丁汎耗陽奏洪|
// |慶奏汎李和允允労汎労允山ヘㇵせ和慶覇群洪|
// +----------------------------------------+
// 2026 (May 23rd) 23:43:49
// end signature


