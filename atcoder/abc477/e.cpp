#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,Q;cin>>N>>Q;
    vector<int>A(N+1),B(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    for(int i=1;i<=N;i++)cin>>B[i];
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+2);
    for(int i=1;i<=N;i++){
        int s=i,t=(i%N)+1;
        g[s].push_back({t,A[i]});
        g[t].push_back({s,A[i]});
        g[i].push_back({N+1,B[i]});
        g[N+1].push_back({i,B[i]});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(N+2,1e18);dist[N+1]=0;
    pq.push({0,N+1});
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto [v,w]:g[u]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }
    vector<int>psA(N+1);
    for(int i=1;i<=N;i++)psA[i]=psA[i-1]+A[i];
    auto mn=[&](int i,int j){
        tie(i,j)=minmax(i,j);
        return min(psA[j-1]-psA[i-1],psA[N]-(psA[j-1]-psA[i-1]));
    };
    while(Q--){
        int s,t;cin>>s>>t;
        if(t==N+1)cout<<dist[s]<<endl;
        else cout<<min(dist[s]+dist[t],mn(s,t))<<endl;
    }
}
