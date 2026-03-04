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
        set<pii> d_i;
        set<pii> i_d;
    };
    vector<node> dist(N+1);

}
