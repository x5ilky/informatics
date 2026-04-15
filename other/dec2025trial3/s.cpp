#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>

using namespace std;

const int MAX_N = 1e5+10;
vector<int> adj[MAX_N];

bool seen[MAX_N], seen2[MAX_N];
bool special[MAX_N];

int order[MAX_N];
vector<bool> in_cycle(MAX_N, true);
#define printf(...) ((void)0);

int main() {
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int v; cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    for (int i = 1; i <= K; i++) {
        int v; cin >> v;
        special[v] = true;
    }

    using pii = pair<int, int>;
    vector<pii> trees;
    set<int> intersections;
    int cycle = -1;
    {
        // find cycle parts
        queue<int> q;
        vector<int> deg(MAX_N);

        for (int i = 1; i <= N; i++) {
            deg[i] = adj[i].size();
            if (deg[i] == 1)
                q.push(i);
        }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            in_cycle[v] = false;
            for (int u : adj[v]) {
                if (--deg[u] == 1)
                    q.push(u);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (in_cycle[i]) {
                cycle = i;
                break;
            }
        }

        for (int v = 1; v <= N; v++) {
            if (in_cycle[v] && adj[v].size() > 2) {
                for (auto &e : adj[v]) {
                    if (!in_cycle[e]) {
                        printf("tree deteched: %d %d\n", v, e);
                        trees.push_back({v, e});
                    }
                }
            }
        }
    }

    // solve for tree

    int total_dist = 0;
    function<int (int, int)> dfs = [&](int u, int parent) {
        int has = 0;
        for (auto& e : adj[u]) {
            if (e == parent) continue;
            bool ans = dfs(e, u);
            has += ans;
        }
        total_dist += has;
        has += special[u];
        return has & 1;
    };

    for (auto& [ip, tp] : trees) {
        int remaining = dfs(tp, ip);
        if (remaining) {
            total_dist += 1;
            special[ip] = !special[ip];
        }
    }
    
    printf("tree only: %d\n", total_dist);

    vector<int> cyc;
    {
        queue<int> q;
        q.push(cycle);
        
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            cyc.push_back(top);
            seen2[top] = true;

            for (auto& e : adj[top]) {
                if (!in_cycle[e] or seen2[e]) continue;
                q.push(e);
                break;
            }
        }
    };

    int first_spec = -1;
    auto dp = [&](int start) {
        bool spec = false;
        int time = 0;
        int c = 0, i = start;
        while (c < cyc.size()) {
            if (special[cyc[i]]) {
                if (first_spec == -1)
                    first_spec = i;
                spec = !spec;
            }
            if (spec) time++;

            i++;
            i %= cyc.size();
            c++;
        }
        return time;
    };
    int best = INT_MAX;
    printf("tree: %d\n", total_dist);
    best = min(best, dp(0));
    
    reverse(cyc.begin(), cyc.end());
    best = min(best, dp(cyc.size()-1-first_spec));
    cout << total_dist + best << endl;
}
