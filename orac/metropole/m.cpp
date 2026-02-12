#include <bits/stdc++.h>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

signed main() {
    int V, H; cin >> V >> H;
    vector<vector<pii>> adj(V+H+100);
    const ll INF = 1e16+9;
    vector<ll> dist(V+H+100, INF);
    for (int i = 1; i <= H; i++) {
        int c; cin >> c; int n; cin >> n;
        vector<int> a(n);
        for (int k = 0; k < n; k++)
            cin >> a[k];
        int idx = V+i;
        for (auto& e : a) {
            adj[e].push_back({idx, c});
            adj[idx].push_back({e, 0});
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto& [e, w] : adj[u]) {
            if (e == u) continue;
            if (d+w >= dist[e]) continue;
            dist[e] = d+w;
            pq.push({d+w, e});
        }
    }
    cout << dist[V] << endl;
}
