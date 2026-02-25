#include <bits/stdc++.h>

using namespace std;

struct segtree {
    vector<int> T, lazy;
    segtree(int n) : T(4*n), lazy(4*n) {}

    void push(int v) {
        if (lazy[v]>0) {
            T[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            T[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int ql, int qr, int addend) {
        if (ql<=tl&&tr<=qr) {
            T[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl+tr)/2;
            if(ql<=tm) update(v*2, tl, tm, ql, min(qr, tm), addend);
            if(qr >tm) update(v*2+1, tm+1, tr, max(tm+1, ql), qr, addend);
            T[v] = T[v*2] + T[v*2+1];
        }
    }
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            push(v);
            int tm = (tl+tr)/2,ans=0;
            if(ql<=tm)ans+=query(v*2,tl,tm,ql,qr);
            if(qr >tm)ans+=query(v*2+1,tm+1,tr,ql,qr);
            return ans;
        }
    }
};

int main() {
    int N=1e6+10;
    segtree st(N+1);
    while (true) {
        int q; cin>>q;
        switch (q) {
            case 0: return 0;
            case 1: {
                int a,b;cin>>a>>b;
                st.update(1,1,N,a,b,1);
            } break;
            case 2: {
                int c;cin>>c;
                cout<<st.query(1,1,N,c,c)<<endl;
            } break;
        }
    }
}
