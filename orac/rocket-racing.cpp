#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int N,M,S,T,K;cin>>N>>M>>S>>T>>K;
    using ai3=array<int,3>;
    vector<vector<ai3>>g(N+1);
    const int INF=1ull<<60;
    vector<int>dist(N+1,INF);
    vector<int>dist2(N+1,INF);
    for(int i=1;i<=M;i++){
        int u,v,w,r;cin>>u>>v>>w>>r;
        g[u].push_back({v,w,w-r});
        g[v].push_back({u,w,w-r});
    }
    using pii=pair<int,int>;
    priority_queue<ai3,vector<ai3>,greater<ai3>>pq;
    dist2[T]=0;
    for(int k=K;k>=1;k--){
        vector<int>dnew=dist2;
        for(int i=1;i<=N;i++){
            for(auto [v,w,w2]:g[i]){
                dnew[v]=min(dnew[v],dist2[i]+w2);
            }
        }
        dist2=dnew;
    }
    dist[S]=0;pq.push({0,S,0});
    while(!pq.empty()){
        auto [d,u,_]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w,w2]:g[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({d+w,v,0});
            }
        }
    }
    int d=INF;
    for(int i=1;i<=N;i++)
        d=min(d,dist[i]+dist2[i]);
    cout<<d<<endl;
}
// ad-hoc
// may 6th 12:42pm
