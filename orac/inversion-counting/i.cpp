#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9+7;
struct segtree {
    vector<int> T;
    segtree(int n):T(n*4){}
    void update(int v,int tl,int tr,int pos,int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            if (pos> tm) update(v*2+1,tm+1,tr,pos,a);
            T[v]=T[v*2]+T[v*2+1];
        }
    }
    int query(int v,int tl,int tr,int ql,int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=0;
            if (ql<=tm) ans+=query(v*2,tl,tm,ql,qr);
            if (qr> tm) ans+=query(v*2+1,tm+1,tr,ql,qr);
            return ans;
        }
    }
};

signed main() {
    using pii=pair<int,int>;
    int N; cin>>N;
    vector<pii>V;
    for(int i=1;i<=N;i++) {
        int v;cin>>v;
        V.push_back({v,i});
    }
    sort(V.begin(),V.end());
    segtree st(N+1);
    int ans=0;
    for(auto& t:V){
        ans+=st.query(1,1,N,t.second,N);
        st.update(1,1,N,t.second,1);
    }
    cout<<ans<<endl;
}
