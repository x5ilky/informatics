#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF=1e18;
struct segtree {
    vector<int> T;
    segtree(int n):T(n*4,-INF){}
    void update(int v, int tl, int tr, int pos, int a) {
        if (tl==tr) {
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if(pos<=tm)update(v*2,tl,tm,pos,a);
            if(pos> tm)update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql<=tl and tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=-INF;
            if(ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
            if(qr>tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
signed main() {
    int N; cin>>N;
    vector<int>D(N+1),V(N+1); for(int i=1;i<=N;i++)cin>>D[i];for(int i=1;i<=N;i++)cin>>V[i];
    segtree st(N+1);
    for(int i=N;i>=1;i--){
        int v=-INF;
        if(D[i]+i>=N+1)v=V[i];
        int s=st.query(1,1,N,i,min(i+D[i],N));
        if(s!=-INF)
            v=max(v,s+V[i]);
        st.update(1,1,N,i,v);
    }
    int ans=st.query(1,1,N,1,1);
    if(ans==-INF){
        cout << "Impossible\n";
    } else {
        cout<<ans<<endl;
    }
}
