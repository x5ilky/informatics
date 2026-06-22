#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    vector<int>E(M+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        E[i]=w;
    }
    vector<int>dist(N+1,INT_MAX);
    using ai3=array<int,3>;
    priority_queue<ai3,vector<ai3>,greater<ai3>>pq;dist[1]=0;pq.push({0,1,-1});
    while(pq.size()){
        auto [d,u,m]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:g[u]){
            int nd=m==-1?0:(d|(m^w));
            if(nd<dist[v]){
                dist[v]=nd;
                pq.push({nd,v,w});
            }
        }
    }
    int bit=bit_width((unsigned)dist[N]);
    set<int>pfx;
    for(int i=1;i<=M;i++){
        pfx.insert(E[i]&((~0)<<bit));
    }
    for(auto p:pfx){
        priority_queue<ai3,vector<ai3>,greater<ai3>>pq;dist[1]=0;pq.push({0,1,-1});
        while(pq.size()){
            auto [d,u,m]=pq.top();pq.pop();
            if(d>dist[u])continue;
            for(auto [v,w]:g[u]){
                int nd=m==-1?0:(d|(m^w));
                if(nd<dist[v]){
                    dist[v]=nd;
                    pq.push({nd,v,w});
                }
            }
        }
    }
    cout<<bit<<endl;
}
