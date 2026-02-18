#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct segtree {
    vector<int> T, lazy, tag; int N;
    segtree(int n) : N(n), T(4*n), lazy(4*n), tag(4*n) {}

    void build(int v, int tl, int tr, vector<int>& a) {
        lazy[v] = 0;
        tag[v] = false;
        if (tl == tr) {
            T[v] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(v*2, tl, tm, a);
            build(v*2+1, tm+1, tr, a);
            T[v] = T[v*2] + T[v*2+1];
        }
    }

    void push(int v) {
        if (tag[v]) {
            tag[v] = false;
            tag[v*2] = tag[v*2+1] = true;

            T[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            T[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int ql, int qr, int addend) {
        if (tl == tr) {
            T[v] += addend;
            lazy[v] += addend;
            tag[v] = true;
        } else {
            push(v);
            int tm = (tl+tr)/2;
            update(v*2, tl, tm, ql, min(qr, tm), addend);
            update(v*2+1, tm+1, tr, max(tm+1, ql), qr, addend);
            T[v] = T[v*2] + T[v*2+1];
        }
    }
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql == tl and qr == tr) {
            return T[v];
        } else {
            push(v);
            int tm = (tl+tr)/2;
            return query(v, tl, tm, ql, min(qr, tm))
                 + query(v, tm+1, tr, min(ql, tm+1), qr);
        }
    }
};

