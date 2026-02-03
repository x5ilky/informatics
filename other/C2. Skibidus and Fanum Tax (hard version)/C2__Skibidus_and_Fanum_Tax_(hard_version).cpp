#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> n(a), m(b);
    for (auto&l : n) cin >> l;
    for (auto&l : m) cin >> l;
    sort(m.begin(), m.end());

    int prev = min(n[0], m[0] - n[0]);
    for (int i = 1; i < n.size(); i++) {
        int atleast = prev + n[i];
        auto it = lower_bound(m.begin(), m.end(), atleast);
        if (it != m.end()) {
            int l = *it - n[i];
            // printf("prev: %d, it: %d\n", prev, *it);
            // printf("l: %d, n[i]: %d\n", l, n[i]);
            if (l >= prev) {
                if (n[i] >= prev) prev = min(n[i], l);
                else prev = l;
            } else {
                if (n[i] >= prev) prev = n[i];
                else {
                    printf("NO\n");
                    return;
                }
            }
        } else {
            if (n[i] >= prev) prev = n[i];
            else {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    

    return 0;
}