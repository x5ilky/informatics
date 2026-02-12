#include <bits/stdc++.h>
using namespace std;
#define int long long

#define printf(...)
signed main() {
    using pii = pair<int ,int>;
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pii>> adj(N+1);
    vector<array<int, 3>> edges;
    for (int i = 1; i <= M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }

    vector<array<pii, 2>> from(N+1, {pair{-1, -1}, pair{-1, -1}});
    map<int, vector<int>> reachable;
    function<void (int, int)> bfs = [&](int node, int parity) {
        for (auto& [e, w] : adj[node]) {
            if (from[e][parity^1].second != -1) continue;
            from[e][parity^1] = {w, node};
            reachable[w].push_back(e);
            bfs(e, parity^1);
        }
    };
    from[1][0] = {0, 0};
    bfs(1, 0);
    if (from[N][0].second == -1 and from[N][1].second == -1) {
        cout << "NO\n";
        return 0;
    }

    int can = false;
    int k = N, parity = 1;
    if (from[k][parity].second != -1) {
        // odd
        int lte = 0, gt = 0;
        while (k != 0) {
            printf("%d,%d ", k, from[k][parity].first);
            if (from[k][parity].first <= K) lte++; else gt++;
            k = from[k][parity].second;
            parity = !parity;
        }
        lte--;
        printf("lte: %d, gt: %d\n", lte, gt);
        if (reachable.find(K) != reachable.end()) {
            printf("found odd\n");
            can = true;
        }
    }
    printf("\n-----\n");
    k = N;
    parity = 0;
    if (from[k][parity].second != -1) {
        // even
        while (k != 0) {
            printf("%d ", k);
            k = from[k][parity].second;
            parity = !parity;
        }
        vector<int> candidates;
        for (auto& [r, _] : reachable) {
            if (r > K) break;
            if (reachable.find(2*K-r) != reachable.end()) {
                candidates.push_back(r);
                break;
            }
        }
        
        const int INF = 1e13+7;
        vector<int> HEAD(2*N+1);
        for (int i = 1; i <= 2*N; i++) HEAD[i] = i;
        vector<pii> lo(2*N+1, {INF, 0}), hi(2*N+1, {-INF, 0});

        function<int(int)> head = [&](int node) {
            if (HEAD[node] == node) return node;
            return HEAD[node] = head(HEAD[node]);
        };
        function<void(int, int)> join = [&](int a, int b) {
            lo[head(a)] = min(lo[head(a)], lo[head(b)]);
            hi[head(a)] = max(hi[head(a)], hi[head(b)]);
            HEAD[head(b)] = head(a);
        };

        sort(edges.begin(), edges.end());
        int lp = 0; int rp = M-1;
        const int DIS = 1e13+7;
        for (auto& cand : candidates) {
            while (lp < M and edges[lp][0] <= cand) {
                auto [v, a, b] = edges[lp];
                join(a, b+N);
                hi[head(a)] = max(hi[head(a)], {v+DIS, b});
                join(a+N, b);
                hi[head(a+N)] = max(hi[head(a+N)], {v, b});
                lp++;
            }
            while (rp > 0 and edges[rp][0] >= 2*K-cand) {
                auto [v, a, b] = edges[rp];
                join(a, b+N);
                lo[head(a)] = min(lo[head(a)], {v+DIS, b});
                join(a+N, b);
                lo[head(a+N)] = min(lo[head(a+N)], {v, b});
                rp--;
            }
            for (int i = 1; i <= N+1; i += N) {
                int a = hi[head(i)].first, b = lo[head(i)].first;
                if ((a < DIS and b > DIS) or (a > DIS and b < DIS)) {
                    printf("found even: %d, ", cand);
                    can = true;
                    goto exit;
                }
            }
        }
exit:;
    }
    printf("\n-----\n");
    cout << (can ? "YES\n" : "NO\n");
}
