#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    freopen("mudin.txt", "r", stdin);
    freopen("mudout.txt", "w", stdout);
    int N;cin>>N;
    vector<int>I(N+1);
    for(int i=1;i<=N;i++)cin>>I[i];
    map<int,vector<int>>adj;
    int M;cin>>M;
    for(int i=1;i<=M;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u,v;cin>>u>>v;
    map<int,pair<int,int>>dist;
    queue<int>q;
    q.push(u);
    dist[u]={0,u};
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto&e:adj[u]){
            if(dist.find(e)==dist.end())dist[e]={1e9,-1};
            if(dist[u].first+1<dist[e].first){
                dist[e]={dist[u].first+1,u};
                q.push(e);
            }
        }
    }
    if(dist.find(v)==dist.end()) return cout<<"No route exists.\n",0;
    int t=v;
    vector<int>path;
    while(t!=u){
        path.push_back(t);
        t=dist[t].second;
    }
    path.push_back(t);
    reverse(path.begin(),path.end());
    for(auto p:path)printf("%d ",p);
    printf("\n");
}

// begin signature
// +----------------------------------------+
// |覇陽奏和労汎允山山せせ火せせ允汎労和群義|
// |群和洪允火丁ミシシヘヘヘヘミ丁火允洪和群|
// |洪山ビシㇵㇸㇵ・　・ㇸ・　ㇸㇵミ火允李奏|
// |火シㇸㇸ一　一ㇸ　　　　ㇸㇵ一ㇵ丁せ洪耗|
// |シ・ㇸ・ㇸ一ㇸㇸ　ㇸㇸ　　・・ヘㇵ丁山労|
// |ㇸ　一ㇵヘシヘㇵㇵㇸㇸㇸㇸ　ㇸ　ㇸミミ山|
// |・ㇵミビ火せせ火ビミㇵ一・・ㇸヘㇵ　ヘシ|
// |ミ丁せ允洪労労労汎允火ミヘㇵㇸ・ミミ一ㇵ|
// |山允洪李耗奏群奏耗李汎せ丁ミヘㇸ　　ㇸ・|
// |李李奏陽慶覇慶群和洪山ビミヘ一・　　・・|
// |和陽覇覇慶群耗労山ビシㇸ・一一一ㇸ・・ㇸ|
// |陽覇覇陽耗労汎せミ一ㇵシ丁ビビビ丁シㇵ　|
// |慶覇陽耗労山ビミ一シミミ丁ビせ允允せビシ|
// |義覇群和汎火シㇵㇵㇸ　　・一ヘ丁丁ビせ山|
// |奏覇群李允ビヘ　ㇵㇸㇸヘシヘㇸ・ㇸㇸㇵシ|
// |慶慶群李允丁一・ㇸ　一ㇸ　・・ㇸ・　一　|
// |覇陽奏洪せヘ　・シㇸ一ㇸㇸ一ㇵミヘシミミ|
// |慶群李山ミ　・シㇸ一丁丁丁ビせせビ山允せ|
// |群和允丁ㇸ　シ一　・ミせ允洪洪せ洪李労山|
// |群李山シ　一ㇵ・ヘ・丁允和李允汎耗群労せ|
// +----------------------------------------+
// 2026 (April 12th) 15:41:53
// end signature

