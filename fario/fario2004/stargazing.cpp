#include <bits/stdc++.h>

using namespace std;

#define printf(...)
using pii = pair<int, int>;
signed main() {
    int N; cin >> N;
    vector<pii> points(N);
    vector<int> X, Y;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
        X.push_back(x);
        Y.push_back(y);
    }

    const int INF = 1e9+7;
    map<int, pii> by_row;
    for (auto &[x, y] : points) {
        if (by_row.count(y) == 0) by_row[y] = {x, x};
        by_row[y].first  = min(by_row[y].first,  x);
        by_row[y].second = max(by_row[y].second, x);
    }
    int ans = -INF;
    for (auto [y, d] : by_row) {
        auto [l, r] = d;
        if (l == r) continue;
        int h = INF;
        for (auto& [x, y] : points) {
            if (l < x and x < r)
                h = min(h, y);
        }
        if (y-h < r-l) continue;
        printf("%d %d %d %d\n", l, r, h, y);
        ans = max(ans, r-l+y-h);
    }
    cout << ans << endl;
} 
