#include <bits/stdc++.h>
using namespace std;
#include "silky/stl.hpp"
int main() {
    int N,Q;
    cin>>N>>Q;
    Graph<1> g(N);
    while(Q--){
        int t,u,v;
        cin>>t>>u>>v;
        g(v,u,t);
    }
    SCC s(g);auto dag=s.scc();
    FOR(u,1,N)
        for(auto [v,w]:g[u])
            if(s.comp[u]==s.comp[v]&&w)return cout<<"No\n",0;
    auto top=dag.top_sort();
    Vec<int>dp(s.comps+1,1);
    top.reverse(0);
    for(int u:top)
        for(auto [v,w]:dag[u])
            dp[u]=max<int>(dp[u],dp[v]+w);
    Vec<int>A(N+1);
    FOR(i,1,N)A[i]=dp[s.comp[i]];
    cout<<"Yes\n";
    FOR(i,1,N)cout<<A[i]<<" ";cout<<"\n";
}
