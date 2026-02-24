#include <bits/stdc++.h>

using namespace std;

struct segtree {
    vector<int>T;
    segtree(int n):T(n*4,1e9) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=min(T[v*2],T[v*2+1]);
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=1e9;
            if (ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
int main() {
    int N,Q;
    cin>>N>>Q;
    segtree st(N+1);
    for (int i=1;i<=N;i++) {
        int v;cin>>v;
        st.update(1,1,N,i,v);
    }
    for (int q=1;q<=Q;q++){
        string t; int a,b; cin>>t>>a>>b;
        if (t=="Q") cout<<st.query(1,1,N,a,b)<<endl;
        else st.update(1,1,N,a,b);
    }
}
