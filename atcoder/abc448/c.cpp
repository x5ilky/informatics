#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF=(1ULL<<60);
struct segtree {
    vector<int>T;
    segtree(int n):T(n*4,INF) {}
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
            int tm=(tl+tr)/2,ans=INF;
            if (ql<=tm)ans=min(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=min(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
signed main(){
    int N,Q;cin>>N>>Q;
    vector<int>V(N+1);
    segtree st(N+1);
    for (int i=1;i<=N;i++) {
        int v;cin>>v;
        V[i]=v;
        st.update(1,1,N,i,v);
    }
    for (int i=1;i<=Q;i++){
        int K;cin>>K;
        vector<int> q;
        for (int k=1;k<=K;k++){
            int qq;cin>>qq;q.push_back(qq);
        }
        for (auto e:q)st.update(1,1,N,e,INF);
        cout<<st.query(1,1,N,1,N)<<endl;
        for (auto e:q)st.update(1,1,N,e,V[e]);
    }
}
