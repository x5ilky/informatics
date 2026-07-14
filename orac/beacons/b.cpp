#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    set<int>B;
    for(int i=1;i<=K;i++){
        int v;cin>>v;
        B.insert(v);
    }
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    function<bool(int,int)>dfs=[&](int u,int p){
        if(g[u].size()<=2){
            bool b=B.find(u)!=B.end();
            for(auto v:g[u]){
                if(v==p)continue;
                b|=dfs(v,u);
            }
            return b;
        }
        bool b=B.find(u)!=B.end();
        int c=p!=-1;
        for(auto v:g[u]){
            if(v==p)continue;
            bool d=dfs(v,u);
            c+=d;b|=d;
        }
        if(c<=g[u].size()-1){
            ans+=g[u].size()-1-c;
            return true;
        }
        return b;
    };
    for(int i=1;i<=N;i++){
        if(g[i].size()>2){
            dfs(i,-1);
            return cout<<ans<<endl,0;
        }
    }
    if(B.size()>=2)cout<<0<<endl;
    else if(B.size()){
        int u=*B.begin();
        cout<<g[u].size()-1<<endl;
    } else cout<<1<<endl;
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎山火ビ丁丁ビ火山汎労耗陽覇|
// |慶奏李汎山火丁シ一ㇸ・・ㇸㇵミビ山労耗陽|
// |和汎火ミㇵ一　一一・　・ㇸ一一シ火汎労耗|
// |山ミ一一　ㇵ一一一ㇸ　・一シシヘミ火山洪|
// |ミㇸ　ㇵミビ丁ヘシミミシㇵ・一ミㇵㇵミせ|
// |ヘ・ヘビ山ビ丁火山允允山せビヘ・ㇵミ・ㇵ|
// |一ㇸ丁山允丁せ汎李李・ㇸ一ㇸ・　ヘ　シㇵ|
// |ㇸㇵ火汎允火汎李ㇸㇵシシㇵ　一一一ㇸ　ヘ|
// |ㇸ丁火火火汎・シ・シㇵ・　ㇸ一一・　・・|
// |ヘ火ビビ汎ㇸシ　ㇵ・一一一ㇸ　一一ㇸㇵ一|
// |せ火ビ　ㇵ一一ㇵミビ火火ビ丁ヘㇸㇸ　せ丁|
// |山シ　　ㇸヘㇸ　ㇸヘ丁丁火火ビシ・　ミシ|
// |山ミヘ丁ビ火ビミヘ・・・一ㇵヘヘㇵ・　　|
// |丁ビ火允汎允火シ一ㇸㇸ・シビせ山せ丁ヘ　|
// |一シ山労李山ミㇸㇵ一ㇸヘ丁ビ丁ビ火ビビ丁|
// |シシ汎和労せヘ　ㇵ　一ㇸ　・・ㇸシ火汎丁|
// |一丁李耗汎丁・ヘビシㇵ一ㇸ一ヘ丁せ洪洪火|
// |ヘ李群労火一ㇵ丁火せ火ビ火せ允洪和耗汎山|
// |汎群和山ヘㇸミミミビせ允労李耗群群奏和汎|
// |李群労火ㇵㇵ火允汎洪李和群義覇義群慶耗允|
// +----------------------------------------+
// 2026 (July 6th) 14:22:28
// end signature

