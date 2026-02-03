#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+10;
int N, Q;

using ll = long long;
struct D {
    ll v[4];
};

D t[2 * MAX_N];

D make_node(ll x, ll y) {
    D nd;
    nd.v[0] = x + y;
    nd.v[1] = x - y;
    nd.v[2] = -x + y;
    nd.v[3] = -x - y;
    return nd;
}

D merge(const D &a, const D &b) {
    D res;
    for (int i = 0; i < 4; i++)
        res.v[i] = max(a.v[i], b.v[i]);
    return res;
}

void build() {
    for (int i = N - 1; i > 0; --i)
        t[i] = merge(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, ll x, ll y) {
    t[p += N] = make_node(x, y);
    for (p >>= 1; p > 0; p >>= 1)
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
}

D query_node(int l, int r) {
    D resl, resr;
    for (int i = 0; i < 4; i++)
        resl.v[i] = resr.v[i] = LLONG_MIN;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) resl = merge(resl, t[l++]);
        if (r & 1) resr = merge(t[--r], resr);
    }
    return merge(resl, resr);
}

ll query(int l, int r, ll qx, ll qy) {
    D res = query_node(l, r);
    ll ans = 0;
    ans = max(ans, res.v[0] - (qx + qy));
    ans = max(ans, res.v[1] - (qx - qy));
    ans = max(ans, res.v[2] - (-qx + qy));
    ans = max(ans, res.v[3] - (-qx - qy));
    return ans;
}
int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >>x >> y;
        t[N+i] = make_node(x, y);
    }
    build();
    for (int i = 0; i < Q; i++) {
        int qq; cin >> qq;
        if (qq == 1) {
            int i, x, y; cin >> i >> x >> y;
            i--;
            modify(i, x, y);
        } else if (qq == 2) {
            int l, r, x, y; cin >> l >> r >> x >> y;
            l--, r--;
            ll ans = query(l, r+1, x, y);
            cout << ans << endl;
        }
    }
    return 0;
}
