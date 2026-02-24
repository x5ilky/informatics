#include <bits/stdc++.h>

using namespace std;

struct segtree {
    vector<int>T;
    segtree(int n):T(n*4,0) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=T[v*2]^T[v*2+1];
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=0;
            if (ql<=tm)ans^=query(v*2,tl,tm,ql,qr);
            if (qr>tm)ans^=query(v*2+1,tm+1,tr,ql,qr);
            return ans;
        }
    }
};
int main() {
    int N,Q;
    cin>>N>>Q;
    segtree st(N+1);
    for (int qq=1;qq<=Q;qq++){
        int q,a,b; cin>>q>>a>>b;
        if (q==1) cout<<st.query(1,1,N,a,b)<<endl;
        else st.update(1,1,N,a,b);
    }
}
