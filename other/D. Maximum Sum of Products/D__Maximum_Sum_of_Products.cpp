#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define IINF 0xfffffff
using ll = long long;

signed main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(auto& c : a) cin >> c;
    for(auto& c : b) cin >> c;
    
    ll sl[n+1] = {0};
    for(int i = 0; i < n; i++) {
        sl[i+1] = sl[i] + a[i] * b[i];
    }
    
    ll ans = sl[n];
    forn(c, n) {
        ll base = a[c] * b[c];
        for (int l = c-1, r=c+1; l >= 0 && r < n; l--, r++) {
            base += a[l] * b[r];
            base += a[r] * b[l];
            ans = max(ans, base + sl[l] + (sl[n] - sl[r+1]));
        }
        base = 0;
        for (int l = c, r=c+1; l >= 0 && r < n; l--, r++) {
            base += a[l] * b[r];
            base += a[r] * b[l];
            ans = max(ans, base + sl[l] + (sl[n] - sl[r+1]));
        }
    }
    printf("%lld\n", ans);

    return 0;
}