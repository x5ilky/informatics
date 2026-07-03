#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,K;cin>>N>>K;
    vector<int>B(K+1);
    for(int i=1;i<=K;i++)cin>>B[i];
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

}
