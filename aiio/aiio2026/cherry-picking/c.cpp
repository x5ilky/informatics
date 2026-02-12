#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define printf(...)
using pii = pair<int, int>;
int main() {
    int N; cin >> N;
    vector<pii> by_size(N+1), by_taste(N+1);
    
    for (int i = 1; i <= N; i++) {
        int s, t; cin >> s >> t;
        by_size[i] = {s, t};
        by_taste[i] = {t, s};
    }
    sort(by_size.begin()+1, by_size.end());
    sort(by_taste.begin()+1, by_taste.end());
    vector<int> pmBy_size(N+2), pmBy_taste(N+2);
    for (int i = N; i >= 1; i--) {
        pmBy_size[i] = max(pmBy_size[i+1], by_size[i].second);
        pmBy_taste[i] = max(pmBy_taste[i+1], by_taste[i].second);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        auto [s, t] = by_size[i];
        int idx = lower_bound(by_size.begin()+1, by_size.end(), pair<int, int>{s+1, 0}) - by_size.begin();
        bool works = true;
        if (idx <= N) {
            if (pmBy_size[idx] > t) works = false;
            printf("size: %d\n", pmBy_size[idx]);
        }
        int idx2 = lower_bound(by_taste.begin()+1, by_taste.end(), pair<int, int>{t+1, 0}) - by_taste.begin();
        if (idx2 <= N) {
            if (pmBy_taste[idx2] > s) works = false;
            printf("taste: %d\n", pmBy_taste[idx]);
        }
        ans += works;
        printf("idx: %d\n", idx);
    }
    cout << ans << endl;
}
