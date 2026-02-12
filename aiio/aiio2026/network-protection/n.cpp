#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define printf(...)
int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> children(N+1);
    for (int i = 2; i <= N; i++) {
        int P; cin >> P;
        children[P].push_back(i);
    }
    set<int> s;
    vector<int> stStart(N+1), stEnd(N+1);
    vector<int> sz(N+1);
    for (int i = 1; i <= M; i++) {
        int v; cin >> v;
        s.insert(v);
    }

    int c = 1;
    function<void (int)> bfs = [&](int node) {
        sz[node] = 1;
        stStart[node] = c++; 
        for (auto& ch : children[node]) {
            bfs(ch);
            sz[node] += sz[ch];
        }
        stEnd[node] = c;
    };
    bfs(1);
    using pii = pair<int, int>;
    priority_queue<pii> pq;
    pq.push({sz[1], 1});

    int target = N-K, ans = 0;
    while (!pq.empty()) {
        if (target <= 0) break;
        auto [size, u] = pq.top();
        pq.pop();
        if (s.find(u) == s.end()) {
            for (auto& c : children[u]) {
                pq.push({sz[c], c});
            }
        } else {
            target -= size;
            printf("take %d, now %d\n", u, target);
            ans++;
        }
    }
    printf("target: %d\n", target);
    if (target > 0) cout << -1 << endl;
    else cout << ans << endl;
}
