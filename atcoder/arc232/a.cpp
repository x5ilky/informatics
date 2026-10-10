#include <bits/stdc++.h>
#include "silky/stl.hpp"
using namespace std;
#define int long long
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
        if(qr<ql)return 1e9;
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
struct segtree2 {
    vector<int>T;
    segtree2(int n):T(n*4,-1e9) {}
    void update(int v, int tl, int tr, int pos, int a) {
        if(tl==tr){
            T[v]=a;
        } else {
            int tm=(tl+tr)/2;
            if (pos<=tm) update(v*2,tl,tm,pos,a);
            else update(v*2+1,tm+1,tr,pos,a);
            T[v]=max(T[v*2],T[v*2+1]);
        }
    }
    
    int query(int v, int tl, int tr, int ql, int qr) {
        if(qr<ql)return -1e9;
        if (ql<=tl&&tr<=qr) {
            return T[v];
        } else {
            int tm=(tl+tr)/2,ans=-1e9;
            if (ql<=tm)ans=max(ans,query(v*2,tl,tm,ql,qr));
            if (qr>tm)ans=max(ans,query(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};
signed main() {
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        using pii=pair<int,int>;
        vector<pii>R(M+1);
        LazySegTree st(N+1),st2(N+1);
        st.set(1,N,1);
        st2.set(1,N,0);
        for(int i=1;i<=M;i++)cin>>R[i].first>>R[i].second;
        sort(R.begin()+1,R.end());
        segtree mn(N+1);
        segtree2 mx(N+1);
        for(int i=1;i<=M;i++){
            // printf("set %d.%d\n",R[i].first,R[i].second);
            auto [l,r]=R[i];
            mn.update(1,1,N,r,min(mn.query(1,1,N,r,r),l));
            mx.update(1,1,N,l,max(mx.query(1,1,N,l,l),r));
        }
        // for(int i=1;i<=N;i++)printf("%lld ",mn.query(1,1,N,i,i));printf("\n");
        for(int i=1;i<=M;i++){
            auto [l,r]=R[i];
            int L=mn.query(1,1,N,r,N);
            int R=mx.query(1,1,N,1,l);
            // printf("lr %lld..%lld, LR %lld..%lld\n",l,r,L,R);
            if(L>N||R<1)continue;
            // printf("do something\n");
            st.set(L,l-1,0);
            st.set(r+1,R,0);
        }
        bool good=true;
        for(int i=1;i<=M;i++){
            // printf("set %d.%d\n",R[i].first,R[i].second);
            auto [l,r]=R[i];
            if(l+1==r){
                if(st.sum(l,r)!=2)good=false;
                st2.set(l,r,1);
                st.set(l,r,0);
            }
        }
        for(int i=1;i<=M;i++){
            auto [l,r]=R[i];
            int c=2;
            c-=st2.sum(l,r);
            if(c<0||st.sum(R[i].first,R[i].second)<c){
                good=false;
                break;
            }
        }
        cout<<(good?"Yes\n":"No\n");
    }
}
