#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using mint=atcoder::static_modint<1'000'000'007>;
int main() {
    int N;cin>>N;
    vector<vector<int>>adj(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<mint>fac(N+10,1);
    for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i;
    auto binom=[&](int n,int k){
        if(n<k)return mint(0);
        return fac[n]*fac[k].inv()*fac[n-k].inv();
    };

    vector<mint>down(N+1,1),up(N+1,1);vector<int>sz(N+1,0);
    function<void(int,int)> dfs1=[&](int u,int p){
        sz[u]=1;
        mint a=1;int c=0;
        for(auto e:adj[u]){
            if(e==p)continue;
            dfs1(e,u);
            sz[u]+=sz[e];
            a*=down[e]*binom(c+sz[e],sz[e]);
            c+=sz[e];
        }
        down[u]=a;
    };
    dfs1(1,-1);
    function<void(int,int)> dfs2=[&](int u,int p){
        mint a=up[u]*down[u]*binom(sz[1]-1,sz[u]-1);
        for(auto e:adj[u]){
            if(e==p)continue;
            up[e]=a/down[e]/binom(sz[1]-1,sz[e]);
            dfs2(e,u);
        }
    };
    dfs2(1,-1);
    for(int i=1;i<=N;i++){
        mint ans=up[i]*down[i]*binom(sz[1]-1,sz[1]-sz[i]);
        // printf("%d %d %d\n",up[i].val(),down[i].val(),ans.val());
        cout<<ans.val()<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇慶群和李洪汎山せ火ビ火せ山汎李奏義覇|
// |覇群和洪山火丁ミヘ一ㇸㇸ一ヘミ火允労奏義|
// |和汎せ丁ヘ一・・ㇵ一　・ㇸㇸㇸシ火汎和陽|
// |山丁一一・一一　一ヘシシシㇵ・ㇸミ山労和|
// |丁ㇸ一　ヘ　ㇵㇵ・・ㇸ・　一ミㇵㇸ丁火允|
// |シ　ㇵㇸ一一　ㇸヘヘヘㇵㇸ　　　　　一シ|
// |シ・一ㇸㇸ　ㇵミ火せ山せ火ビシ丁丁丁シㇵ|
// |ㇵ・ㇵシシㇵ丁山允せせ火せ山允汎允山山せ|
// |ㇸミ火山ヘビせ丁シヘㇵ一ㇵヘミビせシヘミ|
// |ビ汎允ミ火ミシ・ㇸㇵヘ一　ㇸㇸㇵシ丁・・|
// |労汎丁ミㇸ一一ㇵ　一ㇵ一一ㇵㇵㇸ　・・ㇸ|
// |汎ビㇵ・ㇸシ・一シミミミヘ一　一ヘ　シヘ|
// |せヘ・ミㇵ一ㇵ一ビ允汎允山火シㇸ　ヘ・　|
// |火ㇵ一ビㇵㇵ一ㇵ・ミせ洪労労允火ヘシヘㇵ|
// |ミヘ・ミㇵ丁ヘ　シㇸ一ミ火火火せせ丁ミミ|
// |　ㇵ一　ヘ火山ミㇸㇸヘ・ㇸ一一一ヘ火ビㇵ|
// |シㇸヘヘㇸシ火山丁ヘ一・・ㇸㇵミせ洪せ丁|
// |丁ㇸ火シヘ一シビせせビ丁ビ火山汎李労汎山|
// |ヘ丁丁せ火丁ミミ丁ビせ允洪李耗群奏奏和汎|
// |ヘ火ミ汎洪汎汎汎汎洪李耗群義慶義陽覇耗汎|
// +----------------------------------------+
// 2026 (April 13th) 22:14:32
// end signature


