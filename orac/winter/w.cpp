#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100010;
using pii = pair<int, int>;
int p[MAX_N], ans[MAX_N];

vector<int> adj[MAX_N];
int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pii> pq;
    for (int i = 1; i <= N; i++) {
        ans[i] = p[i];
        pq.push({p[i], i});
    }
    while (!pq.empty()) {
        auto [prof, u] = pq.top();
        pq.pop();
        if (prof < ans[u]) continue;
        
        for (auto& v : adj[u]) {
            if (p[v] + prof > ans[v]) {
                ans[v] = p[v] + prof;
                pq.push({ans[v], v});
            }
        }
    }


}

