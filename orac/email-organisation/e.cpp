#include <bits/stdc++.h>
#include <set>
 
using namespace std;
 
void solve() {
    int M, N, K; cin >> M >> N >> K;
    map<int, int> m, c; for (int i = 1; i <= N; i++) {
        int v; cin >> v;
        m[i] = v;
        c[v]++;
    }
    int ll = 1, lr = K;
    using pii = pair<int, int>;
    set<pii> by_number, by_place;
 
    auto mit = m.begin();
    bool end = false;

    int it = N*2;
    while (mit != m.end()) {
        if (it --< 0) {
            printf("broke\n");
            break;
        }
        int earliest = mit->second;
        by_number.insert({mit->second, mit->first});
        by_place.insert({mit->first, mit->second});
        
        while (ll <= M and c[ll] == 0) {
            ll++;
            lr++;
        }

        auto add = [&](){
            if (end) {
                if (mit != m.begin()) mit--;
            } else {
                mit++;
                if (mit == m.end()) {
                    end = true;
                    mit = m.find(earliest);
                    if (mit != m.begin()) mit--;
                }
            }
            by_number.insert({mit->second, mit->first});
            by_place.insert({mit->first, mit->second});
        };
        auto it = by_number.lower_bound({ll, 0});
        if (it != by_number.end() and it->first <= lr) {
            c[it->first]--;
            m.erase(it->second);
            by_place.erase({it->second, it->first});
            by_number.erase({it->first, it->second});
            add();
        }
        add();
        if (by_number.size() >= K) {
            auto b = *by_number.begin();
            by_number.erase({b.first, b.second});
            by_place.erase({b.second, b.first});
        }
        for (auto& c : m)
            printf("%d ", c.second);
        printf(": %d-%d end: %d\n", ll, lr, end);
        for (auto& [p, v] : by_place)
            printf("%d:%d ", p, v);
        printf("\n");
    }
    // printf("size: %d\n", m.size());
    cout << (m.size() ? "NO\n" : "YES\n");
    return;
}
 
int main() {
    int T; cin >> T;
    while (T--) solve();
}
