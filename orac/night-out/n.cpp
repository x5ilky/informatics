#include <bits/stdc++.h>

using namespace std;

using pii=pair<int,int>;
const int INF=1e9+7;
struct segtree {
    vector<pii> T;
    segtree(int n):T(n*4,{-INF,-1}){}
    void update(int v,int tl,int tr,int pos,pii a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            if (pos> tm) update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    pii query(int v,int tl,int tr,int ql,int qr) {
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2; pii ans={-INF,-1};
            if (ql<=tm) ans=max(ans,query(v*2,tl,tm,ql,qr));
            if (qr> tm) ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};

int main() {
    int N,K,Q;cin>>N>>K>>Q;
    segtree st(N+1); vector<int>V(N+1);
    for(int i=1;i<=N;i++) {
        int v;cin>>v;
        V[i]=v;
        st.update(1,1,N,i,{v,i});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>last(N+1,-1);
    for(int q=1;q<=Q;q++) {
        while (!pq.empty()&&pq.top().first<q-K) {
            auto [t,i]=pq.top();
            if (last[i]==t) {
                st.update(1,1,N,i,{V[i],i});
            }
            pq.pop();
        }
        int l,r;cin>>l>>r;
        auto[v,i]=st.query(1,1,N,l,r);
        cout<<i<<endl;
        if (i!=-1){ 
            st.update(1,1,N,i,{-INF,-1});
            last[i]=q;
            pq.push({q,i});
        }
    }
}
