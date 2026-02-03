// one path - distance to lca's - 1
#include <bits/stdc++.h>
#include <functional>

using namespace std;

const int MAX_N = 100010;
vector<int> adj[MAX_N];

using pii = pair<int, int>;
pii fir[MAX_N], sec[MAX_N];

int main() {
    int N, K; cin >> N >> K;

    for (int i = 0; i < N-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void (int, int)> dfs1 = [&](int u, int p) {
        fir[u] = {0, u};

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);

            if (fir[v].first + 1 > fir[u].first) {
                fir[u] = {fir[v].first + 1, fir[v].second};
            }
        }
    };
    dfs1(1, -1);

    function<void (int, int)> dfs2 = [&](int u, int p) {
        fir[u] = {0, u};

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u);

            if (fir[v].first + 1 > fir[u].first) {
                fir[u] = {fir[v].first + 1, fir[v].second};
            }
        }
    };
}
