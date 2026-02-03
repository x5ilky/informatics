#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_N = 300010;
const ll MOD = 998244353;
ll psa[MAX_N];
ll psb[MAX_N];
#define FIX sum %= MOD; sum += MOD; sum %= MOD;

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> a(N+1), b(M+1);
    
    for (ll i = 1; i <= N; i++) cin >> a[i];
    for (ll i = 1; i <= M; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (ll i = 1; i <= N; i++) {
        psa[i] = psa[i-1] + a[i];
        psa[i] += MOD;
        psa[i] %= MOD;
    }
    for (ll i = 1; i <= M; i++) {
        psb[i] = psb[i-1] + b[i];
        psb[i] += MOD;
        psb[i] %= MOD;
    }
    
    ll sum = 0;
    ll r = 0;
    for (ll i = 1; i <= N; i++) {
        while (b[r] < a[i] && r <= M) r++;
        r--;
        
        sum += a[i]*r; FIX;
        sum -= psb[r]; FIX;

        sum += psb[M]; FIX;
        sum -= psb[r]; FIX;
        sum -= a[i]*(M-r); FIX;
    }

    cout << sum << endl;
}
