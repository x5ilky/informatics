#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    vector<vector<int>>g(N+1);
    vector<pair<int,int>>E(N);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        E[i]={u,v};
    }
    int ans=1e9;
    for(int i=1;i<=N;i++){
        int c=0;
        auto dfs=[&](auto&&dfs,int u,int p,int d)->void{
            if(d>K/2)c++;
            for(auto v:g[u]){
                if(v==p)continue;
                dfs(dfs,v,u,d+1);
            }
        };
        dfs(dfs,i,-1,0);
        ans=min(ans,c);
    }
    for(int i=1;i<=N-1;i++){
        int c=0;
        auto [s,t]=E[i];
        auto dfs=[&](auto&&dfs,int u,int p,int d)->void{
            if(2*d+1>K)c++;
            for(auto v:g[u]){
                if(v==p)continue;
                dfs(dfs,v,u,d+1);
            }
        };
        dfs(dfs,s,t,0);
        dfs(dfs,t,s,0);
        ans=min(ans,c);
    }
    cout<<ans<<endl;
}

// begin signature
// +----------------------------------------+
// |陽奏和労汎山せ火丁ミミミミ丁ビせ允洪李奏|
// |和労允せビミシㇵ一・・・ㇸ一ヘミ火山洪李|
// |汎せ丁ヘ一ㇸ　ㇸ一ㇸ・ㇸㇸ　ㇸヘ丁せ允洪|
// |ビシㇸㇸ　ㇸ　　　　ㇸ一一ㇵㇵ一シ丁火山|
// |ヘ・ㇸシヘ一　ㇸ・ㇸ・　　・　　・一シビ|
// |ㇵ　一丁火ミ一・ㇵ　一ヘシシヘㇸ　一　一|
// |ㇵ　一丁火シ・一一・ヘヘ一ㇵシ丁シㇸㇸ一|
// |ヘ　ㇸ丁せシ・ㇵ・一ミ火ビシ一ㇸヘ丁ㇵ　|
// |一ㇸㇵ丁丁ヘ　ㇵ・シ火ビビビミヘ・ヘミㇸ|
// |　・一ヘミ・ㇵ　ヘシㇵㇵ一ㇵヘシㇵㇵ丁一|
// |　ヘビ丁一ㇸㇸ一　　ㇸㇸㇸ・　ㇸㇵㇵシ・|
// |・シせミ・ㇵ・一ヘミミミミシㇵㇸ　ㇵヘ　|
// |　ヘビシㇸㇸヘ丁火せ山山山せビミㇵ　一　|
// |・　シㇵ　ㇵ丁せ允洪労労労洪汎山火シ一・|
// |ミㇸ　ㇵ・ヘビ山洪李耗奏和洪山火丁ミシヘ|
// |火ミ一　ㇸミせ汎李奏陽奏李允火ミㇵㇸ・・|
// |火火シ　ㇵビ允李奏義群和汎火ミ一　一ヘㇵ|
// |山ミㇸ一丁允李奏慶陽和汎火シ・一ミビビ丁|
// |丁一ㇸ丁山労奏慶義耗洪せシ　ㇵビ山汎允火|
// |シ　ヘ火汎和陽覇群李允丁一ㇸ丁山労和汎火|
// +----------------------------------------+
// 2026 (August 22nd) 19:50:47
// end signature
