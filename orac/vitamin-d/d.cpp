#include <bits/stdc++.h>

using namespace std;

enum {
    NONE,
    ADD,
    SET
};
#define int long long
struct node {
    int mx,lz,tag;
};

const int INF=1LL<<60;
struct segtree{
    vector<node>T;int mxmx=0;
    segtree(int N):T(N*4,{0,0,NONE}){}

    void apply_set(int v,int len,int val){
        T[v].tag=SET;
        T[v].lz=val;
        T[v].mx=val;
        mxmx=max(mxmx,T[v].mx);
    }
    void apply_add(int v,int len,int val){
        if(T[v].tag==SET){
            T[v].lz+=val;
            T[v].mx+=val;
        }else{
            if(T[v].tag==NONE){T[v].tag=ADD;T[v].lz=0;}
            T[v].lz+=val;
            T[v].mx+=val;
        }
        mxmx=max(mxmx,T[v].mx);
    }

    void push(int v,int l,int r){
        if(T[v].tag==NONE||l==r)return;
        int m=(l+r)/2;
        int llen=m-l+1,rlen=r-m;
        if(T[v].tag==SET){
            apply_set(v*2,llen,T[v].lz);
            apply_set(v*2+1,rlen,T[v].lz);
        }else{
            apply_add(v*2,llen,T[v].lz);
            apply_add(v*2+1,rlen,T[v].lz);
        }
        T[v].lz=0;
        T[v].tag=NONE;
    }

    void pull(int v){
        T[v].mx=max(T[v*2].mx,T[v*2+1].mx);
        mxmx=max(mxmx,T[v].mx);
    }

    void range_add(int v,int tl,int tr,int ql,int qr,int addend){
        if(qr<tl||tr<ql)return;
        if(ql<=tl&&tr<=qr){
            apply_add(v,tr-tl+1,addend);
        }else{
            push(v,tl,tr);
            int tm=(tl+tr)/2;
            if(ql<=tm)range_add(v*2,tl,tm,ql,qr,addend);
            if(qr>tm)range_add(v*2+1,tm+1,tr,ql,qr,addend);
            pull(v);
        }
    }

    void range_set(int v,int tl,int tr,int ql,int qr,int val){
        if(qr<tl||tr<ql)return;
        if(ql<=tl&&tr<=qr){
            apply_set(v,tr-tl+1,val);
        }else{
            push(v,tl,tr);
            int tm=(tl+tr)/2;
            if(ql<=tm)range_set(v*2,tl,tm,ql,qr,val);
            if(qr>tm)range_set(v*2+1,tm+1,tr,ql,qr,val);
            pull(v);
        }
    }

    int query_max(int v,int tl,int tr,int ql,int qr){
        if(qr<tl||tr<ql)return -INF;
        if(ql<=tl&&tr<=qr){
            return T[v].mx;
        }else{
            push(v,tl,tr);
            int tm=(tl+tr)/2;
            int ans=-INF;
            if(ql<=tm)ans=max(ans,query_max(v*2,tl,tm,ql,qr));
            if(qr>tm)ans=max(ans,query_max(v*2+1,tm+1,tr,ql,qr));
            return ans;
        }
    }
};

signed main() {
    int N,L;cin>>N>>L;
    int S=L=10;
    segtree st(S+1);
    for (int i=1;i<=N;i++){
        int l,r;cin>>l>>r;l++,r++;
        if(l>1)st.range_set(1,1,S,1,l-1,0);
        st.range_set(1,1,S,r,L,0);
        st.range_add(1,1,S,l,r-1,1);
    }
    cout<<st.mxmx<<endl;
}
