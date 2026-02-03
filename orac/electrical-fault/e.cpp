#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;
struct R {
    int d, v, init;
};
bool operator>(const R&l, const R&r) {
    return l.d > r.d;
}


#define printf(...)
int main() {
    int V, E, K; cin >> V >> E >> K;    
    vector<int> grounds(K+1); for (int i = 1; i <= K; i++) cin >> grounds[i];
    vector<vector<pii>> adj(V+1, vector<pii>{});

    for (int i = 1; i <= E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<R, vector<R>, greater<R>> pq;
    for (int i = 1; i <= K; i++) {
        pq.push({0, grounds[i], grounds[i]});
    }

    const int INF = 1e9+7;
    vector<set<pii, greater<pii>>> dists(V+1, set<pii, greater<pii>>());

    int ans = INF;
    while (!pq.empty()) {
        auto [d, u, orig] = pq.top();
        pq.pop();

        for (auto& [v, w] : adj[u]) {

        }
    }
    cout << ans << endl;
}
