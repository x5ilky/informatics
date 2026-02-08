#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define printf(...) 
#define int long long
using pii = pair<int, int>;
signed main() {
    int N; cin >> N;
    vector<pii> ranges;
    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        ranges.push_back({a, b+1});
    }
    sort(ranges.begin(), ranges.end());

    int lo = 0, hi = 1e12+1;
    while (lo+1 < hi) {
        int mid = (lo+hi+1)/2;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> values(N+1);

        int i = 0, t = 0;
        while (i < N) {
            if (i < N and pq.empty()) t = ranges[i].first;
            while (i < N and ranges[i].first <= t) {
                pq.push({ranges[i].second, i});
                i++;
            }
            while (!pq.empty()) {
                auto [_, id] = pq.top();
                int amt = mid - values[id];
                if (i+1 < N) {
                    printf("next: %d, t: %d\n", ranges[i+1].first, t);
                    amt = min(amt, ranges[i+1].first - t);
                }
                values[id] += amt;
                if (values[id] >= mid) {
                    pq.pop();
                }
                printf("adding %d to %d,%d\n", amt, ranges[id].first, ranges[id].second); 
                t += amt;
                if (t > ranges[id].second) {
                    hi = mid;
                    goto skip;
                }
                while (i < N and ranges[i].first <= t) {
                    pq.push({ranges[i].second, i});
                    i++;
                }
            }
        }

        while (!pq.empty()) {
            auto [amt, id] = pq.top();
            t += mid;
            if (t > ranges[id].second) {
                hi = mid;
                goto skip;
            }
            pq.pop();
        }
        lo = mid;
skip:;
    }
    cout << lo << endl;
}
