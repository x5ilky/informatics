#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

#define int long long
using pii = pair<int, int>;
signed main() {
    int N, M; cin >> N >> M;

    vector<pii> inputs;
    vector<pii> ranges;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        if (a > b) {
            inputs.push_back({b, a});
        }
    }
    sort(inputs.begin(), inputs.end());
    for (int i = 0; i < inputs.size(); i++) {
        auto [a, b] = inputs[i];
        if (ranges.empty()) {
            ranges.push_back({a, b});
        } else {
            auto last = ranges.back();
            int merge = (max(last.second, b) - min(last.first, a));
            int split = (last.second-last.first) + (b - a);
            if (merge < split) {
                ranges.pop_back();
                ranges.push_back({min(last.first, a), max(last.second, b)}); 
            } else {
                ranges.push_back({a, b});
            }
        }
    }

    int ans = 0;
    for (auto& [l, r] : ranges) {
        ans += (r - l) * 2; 
    }
    cout << ans+M << endl;
}
