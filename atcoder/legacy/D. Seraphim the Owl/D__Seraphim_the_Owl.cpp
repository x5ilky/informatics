#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200010
#define int long long

int best[MAX_N];
int best_carry[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    best[n] = 0;
    best_carry[n] = 0;
    best[n-1] = 0;
    best_carry[n-1] = 0;

    for (int i = n-1; i >= 0; i--) {
        if (b[i] < a[i]) {
            // better to take till next
            best[i] = a[i] + (best_carry[i+1] == 0 ? best[i+1] : min(best[i+1], best_carry[i+1]));
            best_carry[i] = b[i] + best_carry[i+1];
        } else {
            best[i] = a[i] + (best_carry[i+1] == 0 ? best[i+1] : min(best[i+1], best_carry[i+1]));
            best_carry[i] = best[i];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", best[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", best_carry[i]);
    // }
    // printf("\n\n");
    int ans = best[0];
    for (int i =0; i < m; i++) {
        ans = min(ans, best[i]); 
    }
    printf("%lld\n", ans);
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}