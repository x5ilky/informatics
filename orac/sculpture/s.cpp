#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAX_N = 50010;
using pii = pair<int, int>;
vector<pii> adj[MAX_N];
int cnt[MAX_N], smW[MAX_N], mxW[MAX_N];

int main() {
    int N; cin >> N ;
    for (int i = 1; i <= N; i++) {
        int a, x, b, y; cin >> a >> x >> b >> y;

        if (a) {
            adj[i].push_back({x, a});
            adj[i].push_back({y, b});
        }
    }

    function<void (int, int)> dfs = [&](int node, int w) {
        cnt[node] = !adj[node].size();
        smW[node] = mxW[node] = adj[node].size() ? 0 : w;

        for (auto& [ww, e] : adj[node]) {
            dfs(e, w + ww);
            cnt[node] += cnt[e];
            smW[node] += smW[e];
            mxW[node] = max(mxW[node], mxW[e]);
        }
    };

    dfs(1, 0);
    int mxMxW = *max_element(mxW, mxW + MAX_N);

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int node, int target) {
        if (smW[node] != target * cnt[node]) {
            // not correct
            if (mxW[node] == target) {
                // we cant go deeper here
                for (auto& [_, e] : adj[node]) {
                    dfs2(e, target);
                }
            } else {
                // we can go
                ans += target-mxW[node];
                for (auto& [_, e] : adj[node]) {
                    dfs2(e, mxW[node]);
                }
            }
        }
    };
    dfs2(1, mxMxW);

    // for (int i = 1; i <= N; i++) {
    //     printf("%d: %d %d %d\n", i, cnt[i], smW[i], mxW[i]);
    // }
    cout << ans << endl;
}
