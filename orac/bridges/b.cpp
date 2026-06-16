#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M;cin>>N>>M;
    using pii=pair<int,int>;
    vector<vector<pii>>g(N+1);
    vector<int>W(M+1);
    set<pii>E;
    for(int i=1;i<=M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,i});g[v].push_back({u,i});
        W[i]=w;E.insert({w,i});
    }
    const int B=350;
    int Q;cin>>Q;
    vector<vector<array<int,3>>>q(Q/B+1);
    for(int qq=0;qq<Q;qq++){
        int a,b,c;cin>>a>>b>>c;q[qq/B].push_back({a,b,c});
    }
    for(int bl=0;bl<Q/B+1;bl++){
        auto it=E.begin();
        vector<
    }
}
