#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin>>N;
    vector<vector<int>>g(N+1);
    for(int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<short>B(N+1);
    for(int i=1;i<=N;i++)cin>>B[i];
    using pii=pair<int,int>;
    function<pii(int,int)>dfs=[&](int u,int p){
        pii ans={1e9,1e9};
        for(auto v:g[u]){
            if(v==p)continue;
            auto [off,on]=dfs(v,u);
        }
        return ans;
    };
}
