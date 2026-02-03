#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
void solve() {
    ll N; cin >> N;

    vector<pii> reindeer;
    for (ll i = 0; i < N; i++) {
        ll w, p; cin >> w >> p;
        reindeer.push_back({w, p});
    }
    sort(reindeer.begin(), reindeer.end(), [](auto &a, auto& b) {
        return a.second < b.second;
    });
    reverse(reindeer.begin(), reindeer.end());

    priority_queue<pii> pq;
    ll store = 0;
    ll ans = 0;
    for (auto& [w, p] : reindeer) {
        if (store < w) {
            if (!pq.empty()) {
                store += pq.top().second;
                store += pq.top().first;
                pq.pop();
            } else {
                store += p;
                continue;
            }
        }
        pq.push({w, p});
        store -= w;
        ans = max(ans, (ll)pq.size());
    }
    cout << ans << endl;
}

int main() {
    ll T; cin >> T;
    while (T--) solve();
}
