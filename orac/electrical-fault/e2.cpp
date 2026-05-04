#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    using pii=pair<int,int>;
    int N,M,K;cin>>N>>M>>K;
    vector<int>spec(K+1);
    for(int i=1;i<=K;i++)cin>>spec[i];
    vector<vector<pii>>g(N+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    const int INF=1ull<<60;
    vector<array<pii,2>>dist(N+1);
    for(int i=1;i<=N;i++){
        dist[i][0]={INF,-1};
        dist[i][1]={INF,-1};
    }
    using path=array<int,3>;
    priority_queue<path,vector<path>,greater<path>>pq;
    auto add=[&](int u,int d,int s){
        for(int i=0;i<2;i++){
            if(dist[u][i].second==s){
                if(d>=dist[u][i].first)return false;
                dist[u][i].first=d;
                if(dist[u][1]<dist[u][0])swap(dist[u][0],dist[u][1]);
                return true;
            }
        }

        if(d>=dist[u][1].first)return false;
        dist[u][1]={d,s};
        if(dist[u][1]<dist[u][0])swap(dist[u][0],dist[u][1]);
        return true;
    };
    for(int i=1;i<=K;i++){
        if(add(spec[i],0,i)){
            pq.push({0,spec[i],i});
        }
    }
    while(!pq.empty()){
        auto [d,u,s]=pq.top();pq.pop();
        if(!(dist[u][0]==pii{d,s}||dist[u][1]==pii{d,s}))continue;
        for(auto [v,w]:g[u]){
            if(add(v,d+w,s)){
                pq.push({d+w,v,s});
            }
        }
    }

    int ans=INF;
    for(int i=1;i<=N;i++){
        ans=min(ans,dist[i][0].first+dist[i][1].first);
    }
    cout<<ans<<endl;
}

// ad-hoc
// no signature
