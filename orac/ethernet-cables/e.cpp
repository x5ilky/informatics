#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

struct E {
    int dest, cost, speed;
};

int main() {
    int N, M; cin >> N >> M;
    vector<vector<E>> adj(N+1);
    for (int i = 1; i <= M; i++) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        
        adj[u].push_back({v, c, f});
        adj[v].push_back({u, c, f});
    }

    constexpr static const int INF = 1e9+7;
    int ans = 0;
    vector<int> dist(N+1, INF);
    for (int max_speed = 1; max_speed <= 1000; max_speed++) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        fill(dist.begin(), dist.end(), INF);
        pq.push({0, 1});
        dist[1] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            for (auto& [v, c, s] : adj[u]) {
                if (s < max_speed) continue;
                if (d+c >= dist[v]) continue;

                dist[v] = d+c;
                pq.push({d+c, v});
            }
        }
        if (dist[N] < INF)
            ans = max(max_speed*(int)1e6/dist[N], ans);
    }
    cout << ans << endl;
}
