#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int cons = 0;
    int N, R; cin >> N >> R;

    using pii = pair<int, int>;
    vector<pii> value_ranges; 
    set<pair<pii, int>> ranges;
    vector<int> HEAD; 
    function<int (int)> head = [&](int node) {
        if (HEAD[node] == node) return node;
        return HEAD[node] = head(HEAD[node]);
    };

    for (int i = 1; i <= R; i++) {
        int x, a, b; cin >> x >> a >> b;
        int idx = cons;
        value_ranges.push_back({x, x});
        value_ranges.push_back({a, b});

        HEAD.push_back(idx);
        HEAD.push_back(idx);

        auto try_merge = [&](int ai, int bi) {
            int a = head(ai);
            int b = head(bi);

            if (a == b) return false;
            pii ra = value_ranges[a], rb = value_ranges[b];
            if (rb.first < ra.first) swap(ra, rb);

            if (ra.second+1 >= rb.first) {
                int left = min(ra.first, rb.first);
                int right = max(ra.second, rb.second);
                
                value_ranges[a].first = left;
                value_ranges[a].second = right;
                HEAD[b] = a;
                ranges.insert({value_ranges[a], a});
                return true;
            } else return false;
        };
        
        bool merged = false;
        {
            auto after = ranges.lower_bound({{a, 0}, 0});
            if (after != ranges.end()) {
                if (try_merge(idx+1, after->second)) {
                    ranges.erase(after);
                    merged = true;
                }
            }
            if (after != ranges.begin()) {
                auto before = prev(after);
                if (try_merge(idx+1, before->second)) {
                    ranges.erase(after);
                    merged = true;
                }
            }
            if (!merged) {
                ranges.insert({{a, b}, idx+1});
            }
        }
        for (int i = 0; i < value_ranges.size(); i++) {
            if (head(i) == i) {
                auto r = value_ranges[i];
                printf("%d-%d ", r.first, r.second);
            }
        }
        printf("\n");
    }
}
