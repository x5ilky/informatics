#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1ull<<60;
struct segtree{
    vector<int>T;int N;
    segtree(int N):N(N),T(2*N,INF){}
    void set(int v,int a){
        for(T[v+=N]=a;v>>=1;)
            T[v]=min(T[v<<1],T[v<<1|1]);
    }
    int query(int l,int r){
        int L=INF,R=INF;
        for(l+=N,r+=N;l<r;l>>=1,r>>=1){
            if(l&1)L=min(L,T[L++]);
            if(r&1)R=min(T[--R],R);
        }
        return min(L,R);
    }
};
signed main(){
    int N,C,D,S,E;cin>>N>>C>>D>>S>>E;
    segtree st(N+1);
    for(int i=1;i<=N;i++){int v;cin>>v;st.set(i,v);}
    struct range{
        int l,r,d,s;
        bool operator<(const range&o)const{
            return tie(l,r,d,s)<tie(o.l,o.r,o.d,o.s);
        }
    };
    set<range>R;
    R.insert({1,N,0,D});
    auto norm=[&](range&r,int s){
        int m=st.query(r.l,r.r);
        r.d+=(s-r.s)*m;
        r.s=s;
        return r;
    };
    auto split=[&](int s){
        auto it=prev(R.upper_bound({s-1,INF,0,0}));
        auto v=*it;
        R.erase(it);
        R.insert({v.l,s,v.d,v.s});
        R.insert({s+1,v.r,v.d,v.s});
    };
    auto merge=[&](int s){
        auto it=prev(R.upper_bound({s,0,0,0}));
    };
}
