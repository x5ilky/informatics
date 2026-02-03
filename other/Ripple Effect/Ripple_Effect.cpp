#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define IINF 0xfffffff
#define pii pair<int, int>
#define pll pair<ll, ll>

signed main() {
    int n;
    cin >> n;
    int A[n];
    forn(i, n) cin >> A[i];

    ll ans = 0;
    for (int t = 0; t < n-1; t++) {
        int mn = A[t];
        int mx = A[t];
        for (int b = t+1; b < n; b++) {
            if (A[b] < mn) mn = A[b];
            else if (A[b] > mx) mx = A[b];
            ans += mx-mn;
        }
    }
    printf("%lld\n", ans);

    return 0;
}