#include <bits/stdc++.h>

using namespace std;

struct segtree {
    using ll = long long;
    vector<ll> T, lz;
    vector<char> tag;
    segtree(int n): T(4*n), lz(4*n), tag(4*n, 0) {}
    void apply(int v, int l, int r, ll val) {
        T[v] = (ll)(r - l + 1) * val;
        lz[v] = val;
        tag[v] = 1;
    }
    void push(int v, int l, int r) {
        if (!tag[v] || l == r) return;
        int m = (l + r) >> 1;
        apply(v<<1,   l,   m, lz[v]);
        apply(v<<1|1, m+1, r, lz[v]);
        tag[v] = 0;
    }
    void update(int v, int tl, int tr, int ql, int qr, ll a) {
        if (ql > qr) return;
        if (ql == tl && qr == tr) {
            apply(v, tl, tr, a);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) >> 1;
            if (ql <= tm) update(v<<1,   tl,   tm, ql, min(qr, tm), a);
            if (qr >  tm) update(v<<1|1, tm+1, tr, max(ql, tm+1), qr, a);
            T[v] = T[v<<1] + T[v<<1|1];
        }
    }

    ll query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql == tl && qr == tr) return T[v];
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(v<<1,   tl,   tm, ql, min(qr, tm)) +
               query(v<<1|1, tm+1, tr, max(ql, tm+1), qr);
    }
};

int main() {
    int N,Q,X;cin>>N>>Q>>X;
    segtree st(N+1);
    int x=0;
    for(int i=1;i<=N;i++) {
        int v;cin>>v;
        st.update(1,1,N,i,i,v<=X);
        if(v==X)x=i;
    }
    for(int q=1;q<=Q;q++){
        int c,l,r;cin>>c>>l>>r;
        if(c==1){
            int lte=st.query(1,1,N,l,r);
            st.update(1,1,N,l,l+lte-1,1);
            st.update(1,1,N,l+lte,r,0);
            if(l<=x&&x<=r){
                x=lte+l-1;
            }
        } else if (c==2) {
            int lte=st.query(1,1,N,l,r);
            st.update(1,1,N,l,r-lte,0);
            st.update(1,1,N,r-lte+1,r,1);
            if(l<=x&&x<=r){
                x=r-lte+1;
            }
        }
    }
    cout << x << endl;

}
