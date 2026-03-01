#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int N,C;cin>>N>>C;
    vector<int>COL(N+1);for (int i=1;i<=N;i++)cin>>COL[i];
    int K;cin>>K;
    vector<vector<int>> pairs(C+1);
    for (int i=1;i<=K;i++){
        int u,v;cin>>u>>v;
        pairs[u].push_back(v);
        pairs[v].push_back(u);
    }
    vector<int>col(N+1);
    vector<int>dp(N+1);
    for(auto e:pairs[COL[N]]){
        col[e]+=1;
    }
}
