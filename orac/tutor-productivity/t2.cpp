#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int N,Q;cin>>N>>Q;
    vector<vector<int>>g(N+1);
    for(int i=2;i<=N;i++){
        int v;cin>>v;g[v].push_back(i);
    }
    vector<int>sz(N+1),dep(N+1),mndep(N+1);
    function<void(int)>dfs=[&](int u){
        mndep[u]=g[u].empty()?dep[u]:N;
        sz[u]=1;for(int v:g[u])dep[v]=dep[u]+1,dfs(v),sz[u]+=sz[v],mndep[u]=min(mndep[u],mndep[v]);
    };
    vector<int>cnt(N+1),ans(N+1,0);
    gp_hash_table<int,null_type>l;
    function<void(int,int)>add=[&](int u, int d){
        cnt[dep[u]]+=d;
        if(d==1)l.insert(dep[u]);
        for(auto v:g[u])add(v,d);
    };
    function<void(int,bool,bool)> solve=[&](int u, bool keep, bool line){
        int big=-1,isline=g[u].size()==1;
        for(auto v:g[u])if(big==-1||sz[v]>sz[big])big=v;
        for(auto v:g[u])if(v!=big)solve(v,false,isline);
        if(big!=-1)solve(big,true,isline);
        for(auto v:g[u])if(v!=big)add(v,1);
        // printf("at %d mn %d isline %d\n",u,mndep[u],line);
        cnt[dep[u]]++;
        l.insert(dep[u]);
        // for(auto d:l)printf("%d ",d);printf("\n");
        if(!line){
            for(auto d:l)if(d<=mndep[u]){
                ans[cnt[d]]=max(ans[cnt[d]],d-dep[u]+1);
                // printf("update at %d fill time %d with %d\n",u,d-dep[u]+1,cnt[d]);
            }
            l.clear();
        }
        if(!keep)add(u,-1);
    };
    dfs(1);
    solve(1,true,false);
    for(int i=1;i<=N;i++)ans[i]=max(ans[i],ans[i-1]);
    for(int i=1;i<=Q;i++){
        int v;cin>>v;
        cout<<ans[v]<<endl;
    }
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎山火ビ丁丁丁ビせ允労洪洪洪|
// |慶奏李汎山火丁ヘ一・　　・一シビ火ビビ火|
// |李汎火ミㇵ一　ㇵㇸ・ㇸ・　ㇸㇵ一ㇸㇸ一ㇵ|
// |山ミ一一・ㇵㇵミ丁ビビ丁シ一一ヘヘヘㇵㇸ|
// |ミㇸ一ㇸ一ミ火允汎洪洪汎山ビ火せ山せ火丁|
// |ヘ・・ヘ丁せ汎李耗奏奏耗和労山ビビ火山洪|
// |ヘ・ㇵ丁山汎李和労洪汎洪李労李汎せシヘ丁|
// |ㇸ一ミせ洪和耗洪李労汎山せせせせ丁ㇵㇸ　|
// |ヘ丁山洪耗李洪労允火丁シヘㇵㇵヘシ丁一ㇵ|
// |山允労奏労労允ビシ一　ㇸ一・　・・一ㇵㇸ|
// |山李奏洪汎火ヘ・一シㇸ・・　・ㇸㇵシㇵㇵ|
// |労群労山丁ヘ・シヘミ丁ビ丁ミㇵㇸㇸ　ヘㇵ|
// |李耗汎ビ一ㇸㇵㇸ丁山汎洪汎允火ミ一　ㇸ・|
// |洪和允丁ㇸㇵㇸヘ　シ火允汎汎汎汎火シヘㇵ|
// |せ労汎丁ㇸㇵシ　ㇵ一ㇸヘ丁ビ丁ビビ丁丁ミ|
// |ミ允汎丁ㇸヘせ丁ㇵ　一一　・・ㇸシ火汎丁|
// |山汎山シ・シ火允ビシㇵ一一ㇵシ丁山洪労せ|
// |和汎丁　ヘ一シ丁火せ火火火せ允洪和奏洪山|
// |洪火一ヘ火丁ミミミビ火允労李耗群慶耗李允|
// |允ミ　ミ汎汎允允汎洪李耗群義覇覇義義和允|
// +----------------------------------------+
// 2026 (June 3rd) 19:23:00
// end signature


