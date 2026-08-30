#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=-1ull<<60;
struct segtree{
    using node=struct{
        int sm,lz,mn;
    };
    int N;vector<node>T;
    segtree(int N):T(N*4,{0,0,0}){}
    void push(int v,int tl,int tr){
        int tm=(tl+tr)/2;
        T[v*2].sm+=T[v].lz*(tm-tl+1);
        T[v*2+1].sm+=T[v].lz*(tr-tm);
        T[v*2].mn+=T[v].lz;
        T[v*2+1].mn+=T[v].lz;
        T[v*2].lz+=T[v].lz;
        T[v*2+1].lz+=T[v].lz;
        T[v].lz=0;
    }
    void range_add(int v,int tl,int tr,int ql,int qr,int a){
        if(ql<=tl&&tr<=qr){
            T[v].sm+=a*(tr-tl+1);
            T[v].lz+=a;
            T[v].mn+=a;
            return;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(ql<=tm)range_add(v*2,tl,tm,ql,qr,a);
        if(qr >tm)range_add(v*2+1,tm+1,tr,ql,qr,a);
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
        T[v].mn=min(T[v*2].mn,T[v*2+1].mn);
    }
    void set(int v,int tl,int tr,int pos,int a){
        if(tl==tr){
            T[v].sm=a;
            T[v].mn=a;
            T[v].lz=0;
            return;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(pos<=tm)set(v*2,tl,tm,pos,a);
        if(pos >tm)set(v*2+1,tm+1,tr,pos,a);
        T[v].sm=T[v*2].sm+T[v*2+1].sm;
        T[v].mn=min(T[v*2].mn,T[v*2+1].mn);
    }
    int range_sum(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v].sm;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2,sm=0;
        if(ql<=tm)sm+=range_sum(v*2,tl,tm,ql,qr);
        if(qr >tm)sm+=range_sum(v*2+1,tm+1,tr,ql,qr);
        return sm;
    }
    int range_min(int v,int tl,int tr,int ql,int qr){
        if(ql<=tl&&tr<=qr){
            return T[v].mn;
        }
        push(v,tl,tr);
        int tm=(tl+tr)/2,mn=-INF;
        if(ql<=tm)mn=min(mn,range_min(v*2,tl,tm,ql,qr));
        if(qr >tm)mn=min(mn,range_min(v*2+1,tm+1,tr,ql,qr));
        return mn;
    }
};
signed main() {
    int N;cin>>N;
    string S;cin>>S;
    segtree st(N+1);
    for(int i=1;i<=N;i++){
        if(S[i-1]=='A')st.range_add(1,0,N,i,N,1);
        if(S[i-1]=='B')st.range_add(1,0,N,i,N,-1);
    }
    int Q;cin>>Q;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int i;string C;cin>>i>>C;
            int d=0;
            if(S[i-1]=='A')d-=1;
            if(S[i-1]=='B')d+=1;
            if(C[0]=='A')d+=1;
            if(C[0]=='B')d-=1;
            S[i-1]=C[0];
            st.range_add(1,0,N,i,N,d);
        }else {
            int l,r;cin>>l>>r;
            int lft=st.range_sum(1,0,N,l-1,l-1);
            if(st.range_min(1,0,N,l,r)-lft<0)cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
}
