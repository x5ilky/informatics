#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,M,K;cin>>N>>M>>K;
    using pii=pair<int,int>;
    vector<vector<pii>> adj(N+1);
    vector<int> spec(K+1);
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=1;i<=K;i++){
        cin>>spec[i];
    }
    
    struct node{
        map<int,int> d_i;
        map<int,int> i_d;
    };
    vector<node> dist(N+1);
    struct entry{
        int d,u,s;
        bool operator<(const entry& r) const {
            return d<r.d;
        }
    };
    priority_queue<entry,vector<entry>,greater<entry>> pq;
    for (int i=1;i<=K;i++){
        dist[i].i_d[i]=0;
        dist[i].d_i[0]=i;
        pq.push({0,i,i});
    }
    while (!pq.empty()){
        auto [d,u,s]=pq.top();
        pq.pop();
        if(dist[u].i_d.find(s)!=dist[u].i_d.end()){
            int d2=dist[u].i_d[s];
            if(d>=d2) continue;
            dist[u].i_d[s]=d;
            dist[u].d_i[d]=s;
        }
    }
}
