#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N; 
    vector<vector<int>> adj(N+1);
    for (int i = 1; i <= N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N+2, -1), sz(N+2, 0);
    function<void (int)> dfs = [&](int node) {
        sz[node] = 1;
        bool leaf = true;
        for (auto& e : adj[node]) {
            if (dist[e] != -1) continue;
            dist[e] = dist[node]+1;
            dfs(e);
            sz[node] += sz[e];
            leaf = false;
        }
    };
    dist[1] = 0;
    dfs(1);

    vector<int> psEdges(N+2);
    for (int i = 1; i <= N; i++) psEdges[i] = edges[i] + psEdges[i-1];

    const int INF = 1e9+7;
    int ans = INF;
    int leaves = 0;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, psEdges[N] - psEdges[i] + leaves);
        leaves += leafs[i];
    }
    cout << ans << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}
