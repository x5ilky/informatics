#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200010;
vector<int> adj[MAX_N];

#define int long long
int dist[MAX_N], sz[MAX_N], dp[MAX_N];

signed main() {
    int N; cin >> N;
    
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(dist, dist+MAX_N, -1);
    function<void (int)> dfs = [&](int node) {
        sz[node] = 1;
        for (auto&e : adj[node]) {
            if (dist[e] != -1) continue;
            dist[e] = dist[node]+1;
            dfs(e);
            sz[node] += sz[e];
        }
    };
    dist[1] = 0;
    dfs(1);

    dp[1] = 0;
    for (int i = 1; i <= N; i++) dp[1] += dist[i];

    fill(dist, dist+MAX_N, -1);
    function<void (int)> dfs2 = [&](int node) {
        for (auto& e : adj[node]) {
            if (dist[e] != -1) continue;
            dp[e] = dp[node] + (sz[1]-sz[e]) - (sz[e]);
            dist[e] = 1;
            dfs2(e);
        }
    };

    dist[1] = 0;
    dfs2(1);
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i];
    }
    cout << (ans/2) << endl;
}
