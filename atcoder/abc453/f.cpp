#include <bits/stdc++.h>
#include <queue>
using namespace std;

void solve() {
    int N,K;cin>>N>>K;
    vector<vector<int>>adj(N+1);
    vector<int>cnt(K+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=K;i++)cin>>cnt[i];
    for(int i=1;i<=N;i++){
        vector<int>lay(N+1,0);
        function<void(int,int,int)> dfs=[&](int u,int p,int d){
            lay[d]++;
            for(auto& e:adj[u]){
                if(e==p)continue;
                dfs(e,u,d+1);
            }
        };
        dfs(i,-1,0);
        vector<vector<int>> col(N+1);
        vector<int> even{},odd{}; bool skip=0;
        for(int l=1;l<=N;l++){
            if(lay[l]==0)break;
            if(lay[l]==1){
                skip=1;
                break;
            }
            for(int i=1;i<=lay[l]/2;i++)
                even.push_back(l);
            for(int i=1;i<=lay[l]%2;i++)
                odd.push_back(l);
        }
        if(skip)continue;
        using pii=pair<int,int>;
        auto comp=[](pii a,pii b){
            if(a.first%2!=b.first%2)return a.first%2<b.first%2;
            return a.first<b.first;
        };
        priority_queue<pii,vector<pii>,decltype(comp)> pq(comp);
        for(int k=1;k<=K;k++){
            pq.push({cnt[k],k});
        }
        while(!pq.empty()&&odd.size()>0){
            auto [top,c] =pq.top();
            pq.pop();
            if(top>=3){
                col[odd.back()].push_back(c);
                col[odd.back()].push_back(c);
                col[odd.back()].push_back(c);
                odd.pop_back();
                pq.push({top-3,c});
            } else break;
        }
        if(!odd.empty())continue;
        while(!pq.empty()&&even.size()>0){
            auto [top,c] =pq.top();
            pq.pop();
            if(top>=2){
                col[even.back()].push_back(c);
                col[even.back()].push_back(c);
                even.pop_back();
                pq.push({top-2,c});
            } else break;
        }
        if(!even.empty())continue;
        col[0].push_back(pq.top().second);
        vector<int>coloring(N+1,0);
        function<void(int,int,int)> dfs2=[&](int u,int p,int d){
            coloring[u]=col[d].back();
            col[d].pop_back();
            for(auto& e:adj[u]){
                if(e==p)continue;
                dfs2(e,u,d+1);
            }
        };
        dfs2(i,-1,0);
        for(int i=1;i<=N;i++){
            cout<<coloring[i]<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
}
signed main() {
    int T;cin>>T;
    while(T--)solve();
}

// begin signature
// +----------------------------------------+
// |覇覇義奏和労汎山火丁ミミ丁ビせ允洪和群慶|
// |義奏李汎山火ミヘミ丁ビ丁シ一シビ山洪耗群|
// |李汎火ミㇵㇸシビ火せせ火火ヘ一ヘビ允洪和|
// |せミ一一一ビ允汎火丁せ洪山ミシヘシビせ洪|
// |ミㇸ一　シ山李山允汎洪洪洪允山火ミ一シ火|
// |一・一・ㇵせ李洪李耗奏群奏耗和労汎火シ一|
// |ㇵㇵ・一ㇵミ允耗耗陽奏群慶覇慶陽奏李允ビ|
// |火せビヘ　シ山李陽群耗陽陽義慶覇覇陽耗汎|
// |洪労汎火ㇵ一ビ洪耗和李李李和耗群義覇陽李|
// |群奏労火一ㇵせ洪允山せせ山允洪李耗陽陽李|
// |陽和山シ・丁火丁シヘヘヘミ丁せ允労李耗洪|
// |李允丁・シヘㇸ　ㇸ一ㇸ・　一シ火せ允汎允|
// |せビㇵㇸ一・ㇵㇸ　ㇸ一ㇸ　ㇸ　ㇵヘミビ山|
// |ヘㇵ　ㇵ　ヘ　一シ一ㇸ・ㇸ　ㇸ一一・・ヘ|
// |ㇸㇸ　ㇵㇸ一ㇸヘ・ㇸヘシシヘ丁火ビ丁ミㇵ|
// |ビビㇵ　ㇵ　ヘㇸ一ミ火山山せ山丁シ一ㇸㇸ|
// |洪山シ・一一一一丁山労李和汎ビㇵ　ㇵヘヘ|
// |允ミ　ヘ一　ㇵビ汎和陽耗汎丁ㇸㇵビせ山火|
// |丁・シㇸ・ミビ洪奏慶耗汎丁・シせ洪李労せ|
// |ヘㇸㇸ・シ丁允和義陽労せㇵ一火労群群労火|
// +----------------------------------------+
// 2026 (April 12th) 00:09:47
// end signature
