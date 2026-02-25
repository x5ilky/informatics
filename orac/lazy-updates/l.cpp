#include <bits/stdc++.h>
using namespace std;

enum TAG{NONE,ADD,SET};
struct node{long long mx,sm,lz;TAG tag;};

#define int long long
const int INF=(1LL<<60);

struct segtree{
    vector<node>T;
    segtree(int N):T(N*4,{0,0,0,NONE}){}

    void apply_set(int v,int len,int val){
        T[v].tag=SET;
        T[v].lz=val;
        T[v].sm=(int)len*val;
        T[v].mx=val;
    }
    void apply_add(int v,int len,int val){
        if(T[v].tag==SET){
            T[v].lz+=val;
            T[v].sm+=(int)len*val;
            T[v].mx+=val;
        }else{
            if(T[v].tag==NONE){T[v].tag=ADD;T[v].lz=0;}
            T[v].lz+=val;
            T[v].sm+=(int)len*val;
            T[v].mx+=val;
        }
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
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
        T[v].mx=max(T[v*2].mx,T[v*2+1].mx);
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

    int query_sum(int v,int tl,int tr,int ql,int qr){
        if(qr<tl||tr<ql)return 0;
        if(ql<=tl&&tr<=qr){
            return T[v].sm;
        }else{
            push(v,tl,tr);
            int tm=(tl+tr)/2;
            int ans=0;
            if(ql<=tm)ans+=query_sum(v*2,tl,tm,ql,qr);
            if(qr>tm)ans+=query_sum(v*2+1,tm+1,tr,ql,qr);
            return ans;
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;cin>>N>>Q;
    segtree st(N+1);
    for(int q=1;q<=Q;q++){
        string s;cin>>s;
        if(s=="A"){int l,r,v;cin>>l>>r>>v;st.range_add(1,1,N,l+1,r+1,v);}
        if(s=="S"){int l,r,v;cin>>l>>r>>v;st.range_set(1,1,N,l+1,r+1,v);}
        if(s=="T"){int l,r;cin>>l>>r;cout<<st.query_sum(1,1,N,l+1,r+1)<<"\n";}
        if(s=="M"){int l,r;cin>>l>>r;cout<<st.query_max(1,1,N,l+1,r+1)<<"\n";}
    }
}
