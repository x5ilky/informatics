#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int>D(N+1,-1),p(N+1);
    set<pii>pq;
    function<void(int)>dfs=[&](int u){
        pq.insert({D[u],u});
        for(auto [v,w]:g[u]){
            if(D[v]==-1){
                p[v]=u; D[v]=D[u]+w;
                dfs(v);
            }
        }
    };
    p[1]=-1;
    D[1]=0;dfs(1);
    vector<int> ans;
    while(!pq.empty()){
        auto [d,u]=*pq.rbegin();
        while(u!=-1&&D[u]>=d-K){
            if(D[p[u]]>=d-K)u=p[u];
            else break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto u:ans)cout<<u<<" ";
    cout<<endl;
}
