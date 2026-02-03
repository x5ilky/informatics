// main idea: if you take an upgrade, it only makes sense to take the next best one on the right
// so you can use dp: state is dp[index of upgrade shop] = min price for journey from i to N
// to calculate the cost of taking a shop, you can use a sum segtree with coord compression
//
// you start with no stations in the segtree,
// loop through all upgrades descending order, and calculate dp state
// add any stations into the segtree thats >= to current calculating upgrade
//
// transition for each i:
//  dp[i] = min for all r in i..N (
//      sum [i, r] + dp[r] + c[i], 
//  )
//
// segtree is:
//  sum = l + r
//  mn = min(l.mn, l.sum + r.mn)
//
// update min sets mn[r] = a[r] + v[r]
// update sum is standard

#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;
#define int long long
using pii = pair<int, int>;

#define printf(...)

struct Station {
    int pos, stealth, fine;
    bool operator<(const Station& r) const {
        return stealth < r.stealth;
    }
};
struct Workshop {
    int pos, stealth, cost;
    bool operator<(const Workshop& r) const {
        if (stealth == r.stealth)
            return pos < r.pos;
        return stealth < r.stealth;
    }
};

using ll = long long;
struct Segtree {
    struct Node {
        ll sum;
        ll mn;
    };

    int n;
    vector<Node> st;
    vector<ll> a, v;
    static constexpr ll INF = (1LL << 56);

    Segtree(int n_) { init(n_); }

    void init(int n_) {
        n = n_;
        st.assign(4 * n + 5, Node{0, INF});
        a.assign(n + 1, 0);
        v.assign(n + 1, INF);
    }

    static Node merge(const Node& L, const Node& R) {
        Node out;
        out.sum = L.sum + R.sum;
        out.mn  = min(L.mn, L.sum + R.mn);
        return out;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = Node{a[l], a[l] + v[l]};
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    // set a[i] = x
    void set_cost(int i, ll x) {
        a[i] = x;
        upd(1, 1, n, i);
    }

    // set v[i] = x
    void set_dp(int i, ll x) {
        v[i] = x;
        upd(1, 1, n, i);
    }

    void upd(int p, int l, int r, int i) {
        if (l == r) {
            st[p] = Node{a[l], a[l] + v[l]};
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) upd(p << 1, l, m, i);
        else        upd(p << 1 | 1, m + 1, r, i);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    ll query_min(int ql, int qr) const {
        Node res = query_node(1, 1, n, ql, qr);
        return res.mn;
    }
    ll query_sum(int ql, int qr) const {
        Node res = query_node(1, 1, n, ql, qr);
        return res.sum;
    }

    Node query_node(int p, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) return st[p];
        int m = (l + r) >> 1;
        if (qr <= m) return query_node(p << 1, l, m, ql, qr);
        if (ql >  m) return query_node(p << 1 | 1, m + 1, r, ql, qr);

        Node left  = query_node(p << 1, l, m, ql, qr);
        Node right = query_node(p << 1 | 1, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

signed main() {
    int D, T, W; cin >> D >> T >> W;
    vector<pii> coord;
    vector<Station> raw_stations(T+1);
    vector<Workshop> shops(W+1);
    for (int i = 1; i <= T; i++) {
        int a, s, f; cin >> a >> s >> f;
        raw_stations[i] = {a, s, f};
        coord.push_back({a, i});
    }
    for (int i = 1; i <= W; i++) {
        int b, u, c; cin >> b >> u >> c;
        shops[i] = {b, u, c};
        coord.push_back({b, -i});
    }

    // coord compress
    sort(coord.begin(), coord.end());
    for (int i = 0; i < coord.size(); i++) {
        auto& [pos, idx] = coord[i];
        if (idx < 0) {
            shops[-idx].pos = i+1;
        } else {
            raw_stations[idx].pos = i+1;
        }
    }

    priority_queue<Station, vector<Station>, less<Station>> pq;
    for (int i = 1; i <= T; i++) pq.push(raw_stations[i]);

    sort(shops.begin()+1, shops.end());
    reverse(shops.begin()+1, shops.end());


    int N = coord.size();
    Segtree st(N+1);

    st.set_dp(N+1, 0);
    vector<ll> dp(N+1, -1);

    int s = 1;
    while (s <= W) {
        int u = shops[s].stealth;
        while (!pq.empty() and pq.top().stealth > u) {
            auto top = pq.top();
            printf("adding %lld at %lld\n", top.fine, top.pos);
            st.set_cost(top.pos, top.fine);
            pq.pop();
        }
        // transition for each i:
        //  dp[i] = min for all r in i..N (
        //      sum [i, r] + dp[r] + c[i], 
        //  )

        int e = s;
        while (e <= W && shops[e].stealth == u) e++;

        for (int k = s; k < e; k++) {
            printf("shop %lld is %lld\n", shop.pos, shop.stealth);
            auto& shop = shops[k];
            ll query = st.query_min(shop.pos, N+1);
            dp[shop.pos] = query + shop.cost;
        }
        for (int k = s; k < e; k++) {
            auto& shop = shops[k];
            st.set_dp(shop.pos, dp[shop.pos]);
        }
        printf("result: %lld\n", dp[shop.pos]);
        s = e;
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        printf("adding %lld at %lld\n", top.fine, top.pos);
        if (top.stealth == 0) continue;
        st.set_cost(top.pos, top.fine);
    }
    for (int i = 1; i <= N; i++) {
        printf("%lld\n", st.query_min(i, N+1));
    }
    cout << st.query_min(1, N+1) << endl;
}
