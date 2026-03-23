#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int N;cin>>N;
    vector<int>A(N+1),ans(N+1,false);
    for (int i=1;i<=N;i++)cin>>A[i];
    vector<vector<int>>adj(N+1);
    for (int i=1;i<=N-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int,int,multiset<int>&)> dfs=[&](int u, int p, multiset<int>& s){
        if (s.find(A[u])!=s.end()){
            ans[u]=true;
        }
        s.insert(A[u]);
        for (auto e:adj[u]){
            if(e==p)continue;
            if(ans[u])ans[e]=true;
            dfs(e,u,s);
        }
        s.erase(s.find(A[u]));
    };
    multiset<int> s;
    dfs(1,-1,s);
    for (int i=1;i<=N;i++){
        cout<<(ans[i]?"Yes\n":"No\n");
    }
}
