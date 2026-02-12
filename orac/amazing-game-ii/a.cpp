#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int K; cin >> K;
    vector<int> A(K+1);
    for (int i = 1; i <= K; i++) cin >> A[i];

    int Q; cin >> Q;
    vector<int> B(Q+1);
    for (int i = 1; i <= Q; i++) cin >> B[i];
    
    vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            for (auto& e : adj[top]) {
                if (dist[i][e] != -1) continue;
                q.push(e);
                dist[i][e] = dist[i][top]+1;
            }
        }
    }

    vector<int> value(K+1);
    const int INF = 1e9+7;
    int latest_skip = INF;
    for (int k = K-1; k >= 1; k--) {
         
    }
}
