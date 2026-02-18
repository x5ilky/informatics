#include <bits/stdc++.h>

using namespace std;

struct segtree {
    vector<int> T; int N;
    segtree(int n) : N(n), T(n*4) {
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            T[v] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            T[v] = T[v*2] + T[v*2+1];
        }
    }

    int sum(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr)
            return 0;
        if (ql == tl && qr == tr) {
            return T[v];
        }
        int tm = (tl+tr)/2;
        return sum(v*2, tl, tm, ql, min(qr, tm)) +
               sum(v*2+1, tm+1, tr, max(ql, tm+1), qr);
    }
    void update(int v, int tl, int tr, int q, int a) {
        if (tl == tr) {
            T[v] = a;
        } else {
            int tm = (tl+tr)/2;
            if (q <= tm)
                update(v*2, tl, tm, q, a);
            else
                update(v*2+1, tm+1, tr, q, a);
            T[v] = T[v*2] + T[v*2+1];
        }
    }
};

int main() {
    int N; cin >> N;
    segtree st(N+1);
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) a[i] = i*2;
    st.build(a, 1, 1, N);
    printf("built\n");
    while (true) {
        int l, r, a; cin >> l >> r >> a;
        printf("%d\n", st.sum(1, 1, N, l, r));
        st.update(1, 1, N, l, a);
    }
}
