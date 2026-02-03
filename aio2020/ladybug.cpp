#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
int P[100020];

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    rep(i, n) cin >> P[i];
    
    rep(tt, q) {
        int d;
        cin >> d;
        
        if (d <= P[0]) {
            // go right
            printf("%d ", P[k-1]-d);
        } else if (d >= P[n-1]) {
            printf("%d ", d - P[n-k]);
        } else {
            // in bewteen
            int ans = 1e9+7;

            int onLeft = lower_bound(P, P + n, d) - P;
            if (onLeft-k >= 0) {
                // can just full left
                ans = min(ans, d - P[onLeft-k]);
            }
            if (onLeft + k <= n) {
                // can just full right
                ans = min(ans, P[onLeft + k - 1] - d);
            }
            ans = min(
                ans, 
                (d - P[0]) * 2 + (P[k-1] - d)
            );
            ans = min(
                ans, 
                (P[n-1]-d) * 2 + (d - P[n-k])
            );

            printf("%d ", ans);
        }
    }
}
