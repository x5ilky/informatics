#include <bits/stdc++.h>

using namespace std;

struct node{
    int sum, lz, start, clear;
};
struct segtree {
    vector<node>T;
    segtree(int n) : T(n*4, {0,0,0}) {
    }

    int sum(int s,int l) {
        return (l*(s-1)+l*(l+1)/2);
    }
    void apply_ap(int v,int l,int r,int a) {
        int len=r-l+1;
        T[v].sum=sum(a,len);
        T[v].start=a;
        T[v].lz=true;
    }
    void apply_clear(int v) {
        T[v].sum=0;
        T[v].clear=true;
        T[v].lz=false;
    }
    void push(int v, int tl, int tr) {
        if (T[v].clear) {
            int mid=(tl+tr)/2;
            apply_clear(v*2);
            apply_clear(v*2+1);
            T[v].clear=false;
        }
        if (T[v].lz) {
            int mid=(tl+tr)/2;
            apply_ap(v*2,tl,mid,T[v].start);
            apply_ap(v*2+1,mid+1,tr,T[v].start+(mid-tl+1));
            T[v].lz=false;
        }
    }

    void update_ap(int v, int tl, int tr, int ql, int qr, int a) {
        if(tl>tr)return;
        if(ql<=tl&&tr<=qr){
            apply_ap(v, tl, tr, a+tl-ql);
        } else {
            push(v,tl,tr);
            int mid=(tl+tr)/2;
            if (ql<=mid) update_ap(v*2,tl,mid,ql,qr,a);
            if (qr> mid) update_ap(v*2+1,mid+1,tr,ql,qr,a);
            T[v].sum=T[v*2].sum+T[v*2+1].sum;
        }
    }
    void update_clear(int v, int tl, int tr, int ql, int qr) {
        if(tl>tr)return;
        if(ql<=tl&&tr<=qr){
            apply_clear(v);
        } else {
            push(v,tl,tr);
            int mid=(tl+tr)/2;
            if (ql<=mid) update_clear(v*2,tl,mid,ql,qr);
            if (qr> mid) update_clear(v*2+1,mid+1,tr,ql,qr);
            T[v].sum=T[v*2].sum+T[v*2+1].sum;
        }
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr)return T[v].sum;
        push(v,tl,tr);
        int mid=(tl+tr)/2;
        int res=0;
        if (ql<=mid)res+=query(v*2,tl,mid,ql,qr);
        if (qr> mid)res+=query(v*2+1,mid+1,tr,ql,qr);
        return res;
    }
};

int main() {
    int N; cin >> N;
    segtree st(N+1);

    cout << st.query(1, 1, N, 1, N) << endl;
}
